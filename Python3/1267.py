__________________________________________________________________________________________________
sample 456 ms submission
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        tmp, res = list(zip(*grid)), sum(map(sum, grid))
        for row in grid:
            if sum(row) == 1:
                res -= sum(tmp[row.index(1)]) == 1
        return res
__________________________________________________________________________________________________
sample 460 ms submission
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        grid_ = list(zip(*grid))
        total = sum(sum(r) for r in grid)
        m, n = len(grid), len(grid[0])
        r_set = set(i for i in range(m) if sum(grid[i]) == 1)
        c_set = set(j for j in range(n) if sum(grid_[j]) == 1)
        
        for r in r_set:
            for c in list(c_set):
                if grid[r][c]:
                    c_set.remove(c)
                    total -= 1
        return total
__________________________________________________________________________________________________
