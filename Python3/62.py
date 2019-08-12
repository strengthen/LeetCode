__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    import math 
    def uniquePaths(self, m: int, n: int) -> int:
        
        ans = math.factorial(m+n-2)//(math.factorial(n-1)*math.factorial(m-1))        
        
        return ans
__________________________________________________________________________________________________
sample 12948 kb submission
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        grid = [[1 for x in range(m)] for x in range(n)]
        for i in range(1, m):
            for j in range(1, n):
                grid[j][i] = grid[j - 1][i] + grid[j][i -1]
        return grid[-1][-1]
__________________________________________________________________________________________________
