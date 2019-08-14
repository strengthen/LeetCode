__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        degree = [0] * numCourses
        for pre in prerequisites:
            adj[pre[1]].append(pre[0])
            degree[pre[0]] += 1
        queue = []
        for i in range(len(degree)):
            if degree[i] == 0:
                queue.append(i)
        res = []
        while queue:
            # get the no input directed node
            curr = queue.pop(0)
            # for the curr node adjacent nodes
            for node in adj[curr]:
                degree[node] -= 1
                if degree[node] == 0:
                    queue.append(node)
            res.append(curr)
            numCourses -= 1
        return res if numCourses == 0 else []
__________________________________________________________________________________________________
sample 14072 kb submission
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        indegree = {}
        for a, b in prerequisites:
            adj[b].append(a)
            indegree[a] = indegree.get(a, 0) + 1
        topological_sorted_order = []
        queue = collections.deque([])
        for node in range(numCourses):
            if node not in indegree:
                queue.append(node)
        while queue:
            node = queue.popleft()
            topological_sorted_order.append(node)
            for neighbor in adj[node]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        
        return topological_sorted_order if len(topological_sorted_order) == numCourses else []
__________________________________________________________________________________________________
