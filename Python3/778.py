__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        visited = set()
        heap = [(grid[0][0], 0, 0)]
        heapq.heapify(heap)
        res = 0
        while heap:
            val, r, c = heapq.heappop(heap)
            res = max(res, val)
            if r == m - 1 and c == n - 1:
                return res
            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nr = r + dr
                nc = c + dc
                if (nr, nc) not in visited and nr >= 0 and nr < m and nc >= 0 and nc < n:
                    heapq.heappush(heap, (grid[nr][nc], nr, nc))
                    visited.add((nr, nc))
        return res
__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def swimInWater(self, G: List[List[int]]) -> int:
        front, added, hh, n = [[G[0][0], 0, 0]], {(0, 0)}, float('-inf'), len(G)
        while front:
            v, x, y = heapq.heappop(front)
            hh = max(hh, v)
            for a, b in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                if 0 <= a < n and 0 <= b < n and (a, b) not in added:
                    added.add((a, b))
                    if a == n - 1 and b == n - 1:
                        return max(hh, G[a][b])
                    heapq.heappush(front, (G[a][b], a, b))
__________________________________________________________________________________________________
