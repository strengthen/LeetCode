__________________________________________________________________________________________________
sample 772 ms submission
class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
        d = collections.defaultdict(list)
        for a, b in dislikes:
            d[a].append(b)
            d[b].append(a)
        color = [0] * (N + 1)
        for i in range(1, N + 1):
            if not color[i]:
                queue = collections.deque([i])
                color[i] = 1
                while queue:
                    cur = queue.popleft()
                    for nei in d[cur]:
                        if not color[nei]:
                            color[nei] = -color[cur]
                            queue.append(nei)
                        elif color[nei] == color[cur]:
                            return False
        return True
__________________________________________________________________________________________________
sample 784 ms submission
from collections import defaultdict


class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for a, b in dislikes:
            graph[a].append(b)
            graph[b].append(a)
        
        tags = {}
        for start in range(1, n+1):
            if start in tags:
                continue
                
            tags[start] = 0
            to_visit = [start]
            while to_visit:
                node = to_visit.pop()
                tag = tags[node]
                for neighbor in graph[node]:
                    if neighbor not in tags:
                        tags[neighbor] = 1 - tag    # Alternates between 0 and 1
                        to_visit.append(neighbor)
                    else:
                        if tags[neighbor] != 1 - tag:
                            return False
        return True
__________________________________________________________________________________________________
