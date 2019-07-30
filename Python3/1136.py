__________________________________________________________________________________________________
from collections import defaultdict
class Solution:
    def minimumSemesters(self, N: int, relations: List[List[int]]) -> int:
        
        graph = defaultdict(list)
        cnt = [0] * (N+1)
        for x, y in relations:
            graph[x].append(y)
            cnt[y] += 1
            
        q = [i for i in range(1, N) if cnt[i] == 0]
        res = 0
        visited = set()
        while q:
            new_q = []
            for i in q:
                visited.add(i)
                for post in graph[i]:
                    cnt[post] -= 1
                    if not cnt[post]:
                        new_q.append(post)
            res += 1
            q = new_q
        return res if len(visited) == N else -1
__________________________________________________________________________________________________

__________________________________________________________________________________________________
