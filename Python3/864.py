__________________________________________________________________________________________________
sample 172 ms submission
import collections
class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        nodes = {}
        for r, row in enumerate(grid):
            for c, v in enumerate(row):
                if v not in '.#':
                    nodes[v] = (r, c)
        def bfs_from(source):
            visited = [[False for _ in range(n)] for _ in range(m)]
            r, c = nodes[source]
            queue = [(r, c, 0)]
            visited[r][c] = True
            dist = {}
            while queue:
                r, c, d = queue.pop(0)
                if source != grid[r][c] != '.':
                    dist[grid[r][c]] = d
                    continue
                for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                    if nr >= 0 and nr < m and nc >= 0 and nc < n and grid[nr][nc] != '#' and not visited[nr][nc]:
                        visited[nr][nc] = True
                        queue.append((nr, nc, d+1))
            return dist
        
        edges = {node: bfs_from(node) for node in nodes}
        num_keys = sum(e.islower() for e in edges.keys())
        #print(edges)
        # dijikstra Algo
        pq = [(0, '@', '')]
        final_dist = collections.defaultdict(lambda: float('inf'))
        final_dist[('@', '')]
        
        while pq:
            d, e, state = heapq.heappop(pq)
            # print(e, d, state)
            if final_dist[e, state] < d:
                continue
            if len(state) == num_keys:
                return d
            for destination, dist in edges[e].items():
                state1 = state
                if destination.islower(): #key
                    if destination not in state:
                        state1 += destination
                elif destination.isupper():
                    if destination.lower() not in state:
                        continue
                if d + dist < final_dist[destination, state1]:
                    final_dist[destination, state1] = d + dist
                    heapq.heappush(pq, (d + dist, destination, state1))
        return -1
__________________________________________________________________________________________________
sample 13224 kb submission
import collections
import math
class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m = len(grid)
        n = len(grid[0])
        def neighbor(r, c):
            for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                if 0 <= nr < m and 0 <= nc < n:
                    yield nr, nc
                    
        def bfs(source, row, col):
            visited = [[False] * n for _ in range(m)]
            visited[row][col] = True
            Q = collections.deque([(row, col, 0)])
            dist = {}
            while Q:
                r, c, d = Q.popleft()
                if grid[r][c] != source and grid[r][c] != '.':
                    dist[grid[r][c]] = d
                    continue
                    
                for nr, nc in neighbor(r, c):
                    if grid[nr][nc] != '#' and not visited[nr][nc]:
                        Q.append((nr, nc, d + 1))
                        visited[nr][nc] = True
            return dist
        
        numKey = 0
        dists = collections.defaultdict(dict)
        for i in range(m):
            for j in range(n):
                if grid[i][j] not in '.#':
                    if grid[i][j].islower():
                        numKey += 1
                    dists[grid[i][j]] = bfs(grid[i][j], i, j)
        
        target = 2 ** numKey - 1
        pq = [(0, '@', 0)]
        final_dist = collections.defaultdict(lambda: math.inf)
        final_dist['@', 0] = 0
        while pq:
            d, place, state = heapq.heappop(pq)
            if final_dist[place, state] < d:
                continue
            if state == target:
                return d
            for destination, d2 in dists[place].items():
                state2 = state
                if destination.islower():
                    state2 |= (1 << (ord(destination) - ord('a')))
                elif destination.isupper():
                    if not (state & (1 << (ord(destination) - ord('A')))):
                        continue
                
                if d + d2 < final_dist[destination, state2]:
                    final_dist[destination, state2] = d + d2
                    heapq.heappush(pq, (d + d2, destination, state2))
        return -1
__________________________________________________________________________________________________
