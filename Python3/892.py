__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    ans += 4 * grid[i][j] + 2
        for row in grid:
            ans -= self.checking(row)
        for col in zip(*grid):
            ans -= self.checking(col)
        return ans
    
    def checking(self, nums: List[int]) -> int:           
        total = 0
        for i in range(len(nums) - 1):
            total += 2 * nums[i] if nums[i] < nums[i + 1] else 2 * nums[i + 1]
        return total
__________________________________________________________________________________________________
sample 13228 kb submission
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        M =  len(grid)
        total = 0
        remove = 0
        for i in range(M):
            for j in range(M):
                total += grid[i][j]
                if grid[i][j] != 0:
                    remove += grid[i][j] - 1
                if j + 1 < M and grid[i][j+1] != 0:
                    remove += min(grid[i][j],grid[i][j+1])
                    
        for i in range(M):
            for j in range(M):
                if j + 1 < M and grid[j+1][i] != 0:
                    remove += min(grid[j+1][i],grid[j][i])
                    
        return 6*total - 2*remove                    
__________________________________________________________________________________________________
