__________________________________________________________________________________________________
sample 168 ms submission
from collections import defaultdict
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        dic = defaultdict(list)
        for i in range(R):
            for j in range(C):
                dic[abs(i-r0)+abs(j-c0)].append([i,j])
        res = []
        for i in sorted(dic.keys()):
            res += dic[i]
        return res
__________________________________________________________________________________________________
sample 14956 kb submission
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        toCheck = set()
        toCheck.add((r0,c0))
        res = []
        grid = [[1 for _ in range(C)] for _ in range(R)]
        grid[r0][c0] = 0
        step = [(0,1),(0,-1),(1,0),(-1,0)]
        while toCheck:
            temp = set()
            for x in toCheck:
                res.append(x)
                for s in step:
                    sx, sy = x[0]+s[0], x[1]+s[1]
                    if (0 <= sx < R) and (0 <= sy < C) and grid[sx][sy]:
                        temp.add((sx,sy))
                        grid[sx][sy] = 0
            toCheck = temp.copy()
        return res
__________________________________________________________________________________________________
