__________________________________________________________________________________________________
sample 1752 ms submission
class Solution:
    def minMalwareSpread(self, graph: List[List[int]], initial: List[int]) -> int:
        record = {}
        
        initial_set = set(initial)
        
        for start_node in initial:
            record[start_node] = self.DFS(graph, initial_set, start_node)
        
        max_nodes = 0
        max_index = len(graph)
        for key in record:
            if record[key] > max_nodes:
                max_nodes = record[key]
                max_index = key
            elif record[key] == max_nodes:
                max_index = min(key, max_index)
        return max_index
            
            
    def DFS(self, graph, initial_set, start_node):
        stack = collections.deque()
        visited = set()
        result = 1
        stack.append(start_node)
        visited.add(start_node) 
        while stack:
            node = stack.pop()
            for nxt, status in enumerate(graph[node]):
                if not status:
                    continue
                if nxt in visited:
                    continue
                if nxt in initial_set:
                    return 0
                
                visited.add(nxt)
                stack.append(nxt)
                result += 1
        return result
__________________________________________________________________________________________________
sample 14636 kb submission
class Solution:
    def minMalwareSpread(self, graph: List[List[int]], initial: List[int]) -> int:
        n = len(graph)
        parent = [i for i in range(n)]
        nodes = [1] * n
        def find(x):
            while parent[x] != x:
                x = parent[x]
            return x
        def union(i, j):
            pi = find(i)
            pj = find(j)
            if pi == pj:
                return
            if pi < pj:
                parent[pj] = pi
                nodes[pi] += nodes[pj]
            else:
                parent[pi] = pj
                nodes[pj] += nodes[pi]
        def calc():
            for i in range(n):
                for j in range(n):
                    if graph[i][j] == 1:
                        union(i, j)
        calc()
        m = len(initial)
        affects = [0] * m
        info = {}
        for i, val in enumerate(initial):
            pi = find(val)
            if pi not in info:
                info[pi] = i
                affects[i] = nodes[pi]
            else:
                affects[i] = 0
                affects[info[pi]] = 0
        ans = initial[0]
        mx = affects[0]
        for i in range(1, m):
            if affects[i] > mx:
                ans = initial[i]
                mx = affects[i]
            elif affects[i] == mx and initial[i] < ans:
                ans = initial[i]
        return ans
__________________________________________________________________________________________________
