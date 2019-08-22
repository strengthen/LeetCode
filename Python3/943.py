__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def shortestSuperstring(self, words: List[str]) -> str:
        if not words:
            return ''

        def concat(s, t, mink):
            for k in range(min(len(s), len(t)) - 1, 0, -1):
                if k <= mink: break
                if s[-k:] == t[:k]: return k, s + t[k:]
                if t[-k:] == s[:k]: return k, t + s[k:]

            return 0, s + t

        for n in range(len(words), 1, -1):
            sharedsize = a = b = -1
            concatstr = ''

            for j in range(n):
                for i in range(j):
                    k, s = concat(words[i], words[j], sharedsize)

                    if k > sharedsize:
                        sharedsize = k
                        concatstr = s
                        a = i
                        b = j

            if sharedsize > 0:
                words[b] = concatstr
                words[a] = words[n - 1]
            else:
                words[0] += words[n - 1]

        return words[0]
__________________________________________________________________________________________________
sample 76 ms submission
from functools import lru_cache
class Solution:
    def shortestSuperstring(self, A: List[str]) -> str:
        '''
        a* search
        
        partial match table for dist
        '''
        
        def astar():
            source = 0, -1 # bit mask, last
            targetSet = (1 << len(A)) - 1

            parents = {source: None}
            done = set()
            est = {}
            hp = [(0 + heu(source[0]), source)] # cost(s~>node) + heu(node~>t), node

            while hp:
                est_u, u = heapq.heappop(hp)

                if u[0] == targetSet:
                    path = []
                    curr = u
                    while curr[1] != -1:
                        path.append(curr[1])
                        curr = parents[curr]
                    return est_u - heu(u[0]), path[::-1]

                if u in done:
                    continue

                done.add(u)
                
                for vlast in range(len(A)):
                    if (1 << vlast) & u[0]:
                        continue
                    v = (1 << vlast) | u[0], vlast
                    if v in done:
                        continue
                    
                    cand = est_u - heu(u[0]) + dist(u[1], v[1]) + heu(v[0])
                    if v not in est or cand < est[v]:
                        est[v] = cand
                        parents[v] = u
                        heapq.heappush(hp, (cand, v))
            return float('inf'), []

        @lru_cache(maxsize=None)
        def partialMatchTable(i, j):
            s = A[j] + '#' + A[i]

            p = [0] * len(s)
            j = 0
            for i in range(1, len(s)):
                while j > 0 and s[i] != s[j]:
                    j = p[j - 1]
                if s[i] == s[j]:
                    j += 1
                p[i] = j
            return p[-1]

        @lru_cache(maxsize=None)
        def dist(i, j):
            if i == -1:
                return len(A[j])
            return len(A[j]) - partialMatchTable(i, j)
        
        @lru_cache(maxsize=None)
        def minDist(j):
            ret = float('inf')
            for i in range(len(A)):
                if i == j:
                    continue
                ret = min(ret, dist(i, j))
            return ret
        
        def heu(uset):
            ret = 0
            for i in range(len(A)):
                if (1 << i) & uset:
                    continue
                ret += minDist(i)
            return ret
        
        cost, path = astar()
        
        ret = [A[path[0]]]
        for i in range(1, len(path)):

            ret.append(A[path[i]][partialMatchTable(path[i - 1], path[i]):])

        return ''.join(ret)
__________________________________________________________________________________________________
