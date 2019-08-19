__________________________________________________________________________________________________
sample 496 ms submission
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        count=0
        rowlen=len(grid)
        collen=len(grid[0])
        for i in range(rowlen):
            for j in range(collen):
                if grid[i][j]:
                    count+=4
                    if j and grid[i][j-1]:
                        count-=2
                    if i and grid[i-1][j]:
                        count-=2
        return count
__________________________________________________________________________________________________
sample 13264 kb submission
class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0

        def sum_adjacent(i, j):
            adjacent = (i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1),
            res = 0
            for x, y in adjacent:
                if x < 0 or y < 0 or x == len(grid) or y == len(grid[0]) or grid[x][y] == 0:
                    res += 1
            return res

        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    count += sum_adjacent(i, j)
        return count
__________________________________________________________________________________________________
