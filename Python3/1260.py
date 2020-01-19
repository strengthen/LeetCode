__________________________________________________________________________________________________
sample 136 ms submission
class Solution:
    def shiftGrid(self, grid, k):
        m, n = len(grid), len(grid[0])
        f = []
        for row in grid:
            f += row
        k %= (m*n)
        f = f[-k:] + f[:-k]
        output = []
        for idx in range(m):
            output.append(f[idx*n:(idx+1)*n])
        return output
__________________________________________________________________________________________________
sample 144 ms submission
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        ans = []
        row = len(grid)
        col = len(grid[0])
        n = row * col
        
        for row in grid:
            ans += row
        
        stack = []
        if k > n:
            k = k % n
        
        ans = ans[-k:] + ans[:-k]
        
        res = []
        
        for i in range(0, n, col):
            res.append(ans[i:i+col])
        return res
__________________________________________________________________________________________________
