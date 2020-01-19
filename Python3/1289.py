__________________________________________________________________________________________________
sample 232 ms submission
import math

class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        R = len(arr)
        C = len(arr[0])
        assert C >= 2 # no possible shift
        pm1 = pm2 = (0, None)
        for i in range(0, R):
            m1 = m2 = (float("inf"), None)
            for j, c in enumerate(arr[i]):
                if c < m1[0]:
                    m1, m2 = (c, j), m1
                elif c < m2[0]:
                    m2 = (c, j)
            m1 = (m1[0] + (pm2[0] if m1[1] == pm1[1] else pm1[0]), m1[1])
            m2 = (m2[0] + (pm2[0] if m2[1] == pm1[1] else pm1[0]), m2[1])
            if m1 > m2:
                pm1, pm2 = m2, m1
            else:
                pm1, pm2 = m1, m2
        return pm1[0]
__________________________________________________________________________________________________
sample 240 ms submission
class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        nrows, ncols = len(arr), len(arr[0])
        cache = [None] * nrows  # initialize 2d array
        
        def rec(row):
            if row == nrows:
                return (0, 0), (-1, -1)
            if cache[row] is None:
                s12_next, i12_next = rec(row+1)
                s12, i12 = [float('inf'), float('inf')], [None, None]
                for c in range(ncols):
                    sel = 1 if c == i12_next[0] else 0
                    s = s12_next[sel] + arr[row][c]
                    if s < s12[0]:
                        s12[1], i12[1] = s12[0], i12[0]
                        s12[0], i12[0] = s, c
                    elif s < s12[1]:
                        s12[1], i12[1] = s, c
                cache[row] = (s12, i12)
            return cache[row]

        sol = rec(0)[0][0]
        return sol
__________________________________________________________________________________________________
