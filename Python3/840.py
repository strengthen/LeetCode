__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])
        ret = 0
        if r < 3 or c < 3:
            return ret
        for i in range(1, r - 1):
            for j in range(1, c - 1):
                if grid[i][j] != 5:
                    continue
                if self.magic(grid[i - 1][j - 1], grid[i - 1][j], grid[i - 1][j + 1],
                         grid[i][j - 1], grid[i][j], grid[i][j + 1],
                         grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]):
                    ret += 1
        return ret
    
    def magic(self, a, b, c, d, e, f, g, h, i):
        return (set([a, b, c, d, e, f, g, h, i]) == set(range(1, 10)) and 
                (a + b + c == g + h + i == a + d + g == c + f + i == 15) and 
                (a + i == c + g == d + f == b + h == 10))
__________________________________________________________________________________________________
sample 12912 kb submission
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def helper(x,y):
            memo = set([grid[x][y],grid[x + 1][y],grid[x + 2][y],grid[x][y + 1],grid[x + 1][y + 1],grid[x + 2][y + 1],grid[x][y + 2],grid[x + 1][y + 2],grid[x + 2][y + 2]])
            for i in range(1,10):
                if i not in memo:
                    return False
            return grid[x][y] + grid[x][y + 1] + grid[x][y + 2] == grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2] == grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2] and grid[x][y] + grid[x + 1][y] + grid[x + 2][y] == grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 2][y + 1] == grid[x][y + 2] + grid[x + 1][y + 2] + grid[x + 2][y + 2] and grid[x][y] + grid[x + 2][y + 2] == grid[x + 2][y] + grid[x][y + 2]
        ans = 0
        for i in range(len(grid) - 2):
            for j in range(len(grid[0]) - 2):
                ans += helper(i,j)
        return ans
__________________________________________________________________________________________________
