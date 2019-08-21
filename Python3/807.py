__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        row_maxes = [max(row) for row in grid]
        col_maxes = [max(col) for col in zip(*grid)]

        return sum(min(row_maxes[r], col_maxes[c]) - val
                   for r, row in enumerate(grid)
                   for c, val in enumerate(row))
__________________________________________________________________________________________________
sample 13112 kb submission
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        row, col = list(map(max, grid)), list(map(max, zip(*grid)))
        return sum(min(i, j) for i in row for j in col) - sum(map(sum, grid))
__________________________________________________________________________________________________
