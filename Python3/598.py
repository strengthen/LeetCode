__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        rMin, cMin = sys.maxsize, sys.maxsize
        for i in ops:
            rMin = min(rMin, i[0])
            cMin = min(cMin, i[1])
        return min(m, rMin) * min(n, cMin)
__________________________________________________________________________________________________
sample 14136 kb submission
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        if not ops:
            return m*n
        row = min(m, min([op[0] for op in ops]))
        col = min(n, min([op[1] for op in ops]))
        return row * col
__________________________________________________________________________________________________
