__________________________________________________________________________________________________
sample 712 ms submission
class Solution:
    def eventualSafeNodes(self, graph):
        # return t if i will be in a cycle, f if it will not.
        
        def explore(i):
            visited[i] = 0
            for v in graph[i]:
                # if neighbor has been visited before or after exploration, it is in a cycle
                # -1 => unvisited; 0 => visited; 1 => no cycle?
                if visited[v] == 0 or (visited[v] == -1 and explore(v)): return True
            visited[i] = 1
            res.append(i)
            return False
        visited, res = [-1] * len(graph), []
        for i in range(len(graph)):
            if visited[i] == -1: explore(i)
        return sorted(res)
__________________________________________________________________________________________________
sample 724 ms submission
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        #color[i], 0 means not visited. 1 means safe. 2 means unsafe.
        color=[0] * len(graph)
        res=[]
        for i in range(len(graph)):
            if self.dfs(graph,i,color):
                res.append(i)
        res.sort()
        return res
    
    def dfs(self,graph,i,color):
        if color[i] != 0:
            return color[i] == 1
        color[i] = 2
        for e in graph[i]:
            if not self.dfs(graph,e,color):
                return False
        color[i] = 1
        return True
__________________________________________________________________________________________________
