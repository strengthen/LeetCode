__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def __init__(self):
        self.mem = {}
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        if (r, c, K) in self.mem:
            return self.mem[(r, c, K)]
        
        if r>=2*K and r+2*K<N and c>=2*K and c+2*K<N:
            return 1
        d = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]
        
        
        ret = 0
        for (dr, dc) in d:
            nr, nc = r+dr, c+dc
            if 0<=nr<N and 0<=nc<N:
                ret += 0.125*self.knightProbability(N, K-1, nr, nc)
        
        self.mem[(r, c, K)] = ret
        self.mem[(c, r, K)] = ret
        self.mem[(N-1-r, N-1-c, K)] = ret
        self.mem[(N-1-c, N-1-r, K)] = ret
        return ret
__________________________________________________________________________________________________
sample 13128 kb submission
from copy import deepcopy


class Solution:

    def get_near(self, y, x):
        return [(y-1, x-2), (y-2, x-1), (y-1, x+2), (y-2, x+1),
                (y+1, x+2), (y+2, x+1), (y+1, x-2), (y+2, x-1)]

    def recalculate_probs(self, old, new):
        for y in range(self.N):
            for x in range(self.N):
                near = self.get_near(y, x)
                total = 0
                for r, c in near:
                    if 0 <= r < self.N and 0 <= c < self.N:
                        total += old[r][c]
                new[y][x] = total / 8.0

    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        self.N = N
        old = [[1 for _ in range(N)] for _ in range(N)]
        for _ in range(K):
            new = deepcopy(old)
            self.recalculate_probs(old, new)
            old = new
        return old[r][c]
__________________________________________________________________________________________________
