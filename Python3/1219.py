__________________________________________________________________________________________________
sample 1424 ms submission
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def dfs(x, y, pre, visited):
            nonlocal ans
            for x2, y2 in [[x - 1, y], [x + 1, y], [x, y - 1], [x, y + 1]]:
                if 0 <= x2 < m and 0 <= y2 < n and grid[x2][y2] and (x2, y2) not in visited:
                    dfs(x2, y2, pre + grid[x2][y2], visited | {(x2, y2)})
            if pre > ans:
                ans = pre
            
        m, n, ans = len(grid), len(grid[0]), 0
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    dfs(i, j, grid[i][j], {(i, j)})
        return ans
__________________________________________________________________________________________________
sample 1760 ms submission
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        def dfs(r, c):
            if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] == 0:
                return 0
            val = grid[r][c]
            grid[r][c] = 0
            ans = 0
            for nr, nc in (r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1):
                ans = max(ans, dfs(nr, nc))
            grid[r][c] = val
            return ans + val
        ans = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val != 0:
                    ans = max(ans, dfs(i, j))
        return ans
__________________________________________________________________________________________________
2778ms
class Solution:
def getMaximumGold(self, g: List[List[int]]) -> int:
    def dfs(i, j, visited):
        if not (0 <= i < len(g) and 0 <= j < len(g[0]) and g[i][j] != 0 and (i,j) not in visited):
            return -math.inf
        visited.add((i, j))
        res = g[i][j] + max(0, max(dfs(i+x, j+y, visited) for x,y in [[-1, 0], [1, 0], [0, 1], [0, -1]]))
        visited.remove((i, j))
        return res
    return max(dfs(i, j, set()) for i in range(len(g)) for j in range(len(g[0])))   
