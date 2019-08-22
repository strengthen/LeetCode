__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        if grid is None or len(grid) == 0 or len(grid[0]) == 0:
            return 0
        
        self.count = 0
        
        def dfs(x, y, grid, num):
            tmp = grid[x][y]
            grid[x][y] = "#"
            if x - 1 >= 0:
                if grid[x - 1][y] == 0:
                    dfs(x - 1, y, grid, num - 1)
                elif grid[x - 1][y] == 2 and num == 0:
                    self.count += 1
            if x + 1 < len(grid):
                if grid[x + 1][y] == 0:
                    dfs(x + 1, y, grid, num - 1)
                elif grid[x + 1][y] == 2 and num == 0:
                    self.count += 1
            if y - 1 >= 0:
                if grid[x][y - 1] == 0:
                    dfs(x, y - 1, grid, num - 1)
                elif grid[x][y - 1] == 2 and num == 0:
                    self.count += 1
            if y + 1 < len(grid[x]):
                if grid[x][y + 1] == 0:
                    dfs(x, y + 1, grid, num - 1)
                elif grid[x][y + 1] == 2 and num == 0:
                    self.count += 1
            grid[x][y] = tmp
        
        loc_1_i = -1
        loc_1_j = -1
        num_0 = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    loc_1_i, loc_1_j = i, j
                elif grid[i][j] == 0:
                    num_0 += 1
        dfs(loc_1_i, loc_1_j, grid, num_0)
        return self.count
__________________________________________________________________________________________________
sample 13028 kb submission
class Solution:
    def dfs(self, grid, m, n, x, y, end, empty, ans):
        if x < 0 or x >= m or y < 0 or y >= n or grid[x][y] < 0:
            return
        if x == end[0] and y == end[1]:
            if empty == 0:
                ans[0] += 1
            return
        
        grid[x][y] = -3
        empty -= 1
        dx = (1, 0, -1, 0)
        dy = (0, 1, 0, -1)
        for i in range(4):
            self.dfs(grid, m, n, x+dx[i], y+dy[i], end, empty, ans)
            
        # Reset.
        grid[x][y] = 0
        empty += 1
    
    
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        if len(grid) == 0:
            return 0
        
        m = len(grid)
        n = len(grid[0])
        empty = 1   # Include starting point.
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    start = i, j
                elif grid[i][j] == 2:
                    end = i, j
                elif grid[i][j] == 0:
                    empty += 1
                    
        ans = [0]
        self.dfs(grid, m, n, start[0], start[1], end, empty, ans)
        
        return ans[0]
__________________________________________________________________________________________________
