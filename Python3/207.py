__________________________________________________________________________________________________
sample 92 ms submission
class Solution:
    
    def cyclic(self, graph, node, current, visited):
        visited.add(node)
        current.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                if self.cyclic(graph, neighbor, current, visited):
                    return True
            elif neighbor in current:
                return True
        current.remove(node)
        return False
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [set() for _ in range(numCourses)]
        for prereq, nextCourse in prerequisites:
            graph[prereq].add(nextCourse)
        
        current = set()
        visited = set()
        for node in range(numCourses):
            if node not in visited:
                if self.cyclic(graph, node, current, visited):
                    return False
        return True
__________________________________________________________________________________________________
sample 13872 kb submission
class Solution:
    def canFinish(self, n: int, prerequisites: List[List[int]]) -> bool:
        G = [[] for i in range(n)]
        degree = [0] * n
        for j, i in prerequisites:
            G[i].append(j)
            degree[j] += 1
        bfs = [i for i in range(n) if degree[i] == 0]
        for i in bfs:
            for j in G[i]:
                degree[j] -= 1
                if degree[j] == 0:
                    bfs.append(j)
        return len(bfs) == n
__________________________________________________________________________________________________
