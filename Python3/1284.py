__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        M, N = len(mat), len(mat[0])
        res = float('inf')
        dire = [(0,0),(1,0),(-1,0),(0,1),(0,-1)]
        
        def turn(x,y):
            for d in dire:
                a, b = x + d[0], y + d[1]
                if 0 <= a < M and 0 <= b < N:
                    mat[a][b] ^= 1
        #all states of row 0
        for k in range(1 << N):
            cnt = 0
            backup = [[xx for xx in yy] for yy in mat]
            for j in range(N):
                if k >> j & 1:
                    cnt += 1
                    turn(0,j)
            for i in range(M - 1):
                for j in range(N):
                    if mat[i][j] == 1:
                        cnt += 1
                        turn(i + 1, j)
            is_successful = True
            for j in range(N):
                if mat[M - 1][j] == 1:
                    is_successful = False
                    break
            if is_successful: 
                res = min(res,cnt)
            mat = [[xx for xx in yy] for yy in backup]
        return -1 if res == float('inf') else res
__________________________________________________________________________________________________
sample 20 ms submission
import functools
import itertools


class Solution:
    @staticmethod
    def minFlips(mat: List[List[int]]) -> int:
        width = (m := len(mat)) * (n := len(mat[0]))

        mat = functools.reduce(
            lambda x, y: (x << 1) | y,
            (val for row in mat for val in row),
            0
        )

        flips, bfs, seen = 0, {mat}, {mat}
        awidth, lwidth = width - n, n - 1
        nshifts = itertools.cycle(range(n))

        while bfs:
            next_bfs = set()

            for curr in bfs:
                if curr == 0:
                    return flips

                for shift, nshift in zip(range(width), nshifts):
                    cand = curr ^ (1 << shift)

                    if shift < awidth:
                        cand ^= 1 << (shift + n)  # above
                    if shift >= n:
                        cand ^= 1 << (shift - n)  # below
                    if nshift < lwidth:
                        cand ^= 1 << (shift + 1)  # left
                    if nshift > 0:
                        cand ^= 1 << (shift - 1)  # right

                    if cand not in seen:
                        seen.add(cand)
                        next_bfs.add(cand)

            flips, bfs = flips + 1, next_bfs

        return -1
__________________________________________________________________________________________________
