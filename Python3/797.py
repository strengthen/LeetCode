__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        
        paths = {}
        
        for u in range(n-2, -1, -1):
            paths[u] = []
            
            for v in graph[u]:
                
                if v == n - 1:
                    paths[u] += [u, v],
                else:
                    for path in paths[v]:
                        paths[u] += [u] + path,
        
        return paths[0]
__________________________________________________________________________________________________
sample 14784 kb submission
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        
        def solve(node):
            if node ==  n-1:
                return [[n-1]]
            ans = []
            for new in graph[node]:
                for path in solve(new):
                    ans.append([node] + path)
            return ans
        
        return solve(0)
__________________________________________________________________________________________________
