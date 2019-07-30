__________________________________________________________________________________________________
sample 148 ms submission
class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        ans = 0
        n, m =len(grid), len(grid[0])
        dp_row, dp_col= [[0]*m for _ in range(n)], [[0]*m for _ in range(n)]
        for j in range(m):
            for i in range(n):
                if grid[i][j] == 1:
                    if j > 0:
                        dp_col[i][j] = dp_col[i][j-1]+1
                    else:
                        dp_col[i][j] = 1
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    if i > 0:
                        dp_row[i][j] = dp_row[i-1][j]+1
                    else:
                        dp_row[i][j] = 1
                    
                    d = ans+1
                    while d <= dp_col[i][j]:
                        if dp_row[i][j] >= d and dp_row[i][j-d+1] >= d and dp_col[i-d+1][j] >= d:
                            ans = d
                        d += 1
        return ans*ans        
__________________________________________________________________________________________________
sample 156 ms submission
class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        nrows = len(grid)
        ncols = len(grid[0])
        
        hor = [[0] * ncols for _ in range(nrows)]
        ver = [[0] * ncols for _ in range(nrows)]
        
        hor[0][0] = 1
        ver[0][0] = 1
        
        for r in range(nrows):
            for c in range(ncols):
                if grid[r][c] == 0:
                    hor[r][c] = 0
                    ver[r][c] = 0
                else:
                    hor[r][c] = 1 if c == 0 else hor[r][c - 1] + 1
                    ver[r][c] = 1 if r == 0 else ver[r - 1][c] + 1
        
        largest = 0
        for r in range(nrows - 1, -1, -1):
            for c in range(ncols - 1, -1, -1):
                min_v = min(hor[r][c], ver[r][c])
                while min_v > largest:
                    if hor[r - min_v + 1][c] >= min_v and \
                        ver[r][c - min_v + 1] >= min_v:
                        largest = min_v
                    min_v -= 1
        
        return largest ** 2
__________________________________________________________________________________________________
sample 160 ms submission
class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        h = [[0]*n for _ in range(m)]
        v = [[0]*n for _ in range(m)]
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    h[i][j] = 1 if j == 0 else h[i][j-1] + 1
                    v[i][j] = 1 if i == 0 else v[i-1][j] + 1
                    
        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    small = min(h[i][j], v[i][j])
                    while small > count:
                        if v[i][j-small+1] >= small and h[i-small+1][j] >= small:
                            count = max(count, small)
                            break
                        small -= 1
        
        return count*count