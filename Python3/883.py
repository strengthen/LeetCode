__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def projectionArea(self, grid):
        hor = sum(map(max, grid))
        ver = sum(map(max, zip(*grid)))
        top = sum(v > 0 for row in grid for v in row)
        return ver + hor + top
__________________________________________________________________________________________________
sample 13140 kb submission
class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        if len(grid)==1:
            a=len([i for i in grid[0] if i>0])
            b=max(grid[0])
        else:
            a=sum(list(map(lambda x:len([i for i in x if i>0]),grid)))
            b=sum(list(map(lambda x:max(x),grid)))
        if len(grid[0])==1:
            c=max(*grid)
        else:
            c=sum(list(map(lambda x:max(x),list(zip(*grid)))))
        return a+b+c
__________________________________________________________________________________________________
