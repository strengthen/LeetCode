__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    # others' best
    def minDistance(self, word1: str, word2: str) -> int:
        from collections import deque
        visit, q=set(), deque([(word1, word2, 0)])
        while True:
            w1, w2, d=q.popleft()
            if (w1, w2) not in visit:
                if w1==w2:
                    return d
                visit.add((w1, w2))
                while w1 and w2 and w1[0]==w2[0]:
                    w1, w2=w1[1:], w2[1:]
                d+=1
                q.extend([(w1[1:], w2[1:], d), (w1, w2[1:], d), (w1[1:], w2, d)])
    
    def minDistance1(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        if not n or not m: return n or m
        
        d = [[0]*(m+1) for _ in range(n+1)]
        for i in range(n+1):
            d[i][0] = i
        for j in range(m+1):
            d[0][j] = j
        for i in range(1,n+1):
            for j in range(1,m+1): 
                d[i][j] = min(d[i-1][j-1] + (word1[i-1] != word2[j-1]), d[i-1][j]+1, d[i][j-1]+1)
                # print(f'd[{i}][{j}] = {d[i][j]}')
        return d[n][m]
__________________________________________________________________________________________________
sample 13032 kb submission
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        heap = [(0,word1,word2)]
        seen = set()
        n = 0
        while heap:
            dis, w1, w2 = heapq.heappop(heap)
            if w1 == w2: return dis
            if not (w1,w2) in seen:
                seen.add((w1,w2))
                while w1 and w2 and w1[-1]==w2[-1]:
                    w1 = w1[:-1]
                    w2 = w2[:-1]
                else:
                    heapq.heappush(heap,(dis+1,w1[:-1],w2))
                    if w2:
                        heapq.heappush(heap,(dis+1,w1,w2[:-1]))
                    if w1 and w2:
                        heapq.heappush(heap,(dis+1,w1[:-1],w2[:-1]))
__________________________________________________________________________________________________
