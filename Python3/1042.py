__________________________________________________________________________________________________
sample 168 ms submission
class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        g = [[] for _ in range(n + 1)]
        for x, y in paths:
            g[max(x, y)] += min(x, y),
        ret = [1] * (n + 1)
        for x in range(1, n + 1):
            for c in (1, 2, 3, 4):
                for y in g[x]:
                    if ret[y] == c:
                        break
                else:
                    ret[x] = c
                    break
        # print(g)
        return ret[1:]
__________________________________________________________________________________________________
sample 172 ms submission
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        used = [set() for n in range(N)] 
        graph = [[] for n in range(N)]
        for n1, n2 in paths:
            if n1 > n2:
                n1, n2 = n2, n1
            graph[n1 - 1].append(n2 - 1)
        res = [0] * N
        for n in range(N):
            for c in range(1, 5):
                if c not in used[n]:
                    break
            res[n] = c
            for n1 in graph[n]:
                used[n1].add(c)
        # print(graph, used)
        return res
__________________________________________________________________________________________________
sample 176 ms submission
class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        g = [[] for _ in range(N + 1)]
        flowers = [0] * (N + 1)
        
        for p in paths:
            fr, to = p
            g[fr].append(to)
            g[to].append(fr) 

        for i in range(1, len(g)):
            choices = {1, 2, 3, 4}
            
            for neighbor in g[i]:
                if flowers[neighbor] in choices:
                    choices.remove(flowers[neighbor])
            
            flowers[i] = choices.pop()
        
        return flowers[1:]
            