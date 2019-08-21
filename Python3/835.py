__________________________________________________________________________________________________
sample 212 ms submission
import collections
class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        '''
        1. map the two dimension coordinates to one dimension coordinate
        2. the same diff between two one-dimension coordinates(one from A, the other from B), means a point with 1 in A can be slided to another point with 1 in B:
            (i1, j1), (i2, j2)                  -> 100i1 + j1,           100i2 + i2
            -> slide(n, m)
            (i1 + n, j1 + m), (i2 + n, j2 + m)  -> 100i1 + j1 + 100n +m, 100i2 + j2 + 100n +m
                                               diff 100n + m           ,  100n + m
        '''
        n = len(A)
        AA, BB = [], []
        for row in range(n):
            for col in range(n):
                if A[row][col]:
                    AA.append(100 * row + col)
                if B[row][col]:
                    BB.append(100 * row + col)
        cnt = collections.Counter([a - b for a in AA for b in BB] )
        return max(cnt.values() or [0])
__________________________________________________________________________________________________
sample 13704 kb submission
class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        a_ind = []
        b_ind = []
        for i in range(len(A)):
            for j in range(len(A[0])):
                if A[i][j] == 1:
                    a_ind.append((i, j))
                if B[i][j] == 1:
                    b_ind.append((i, j))
        
        max_count = 0
        count = collections.defaultdict(int)
        for a in a_ind:
            for b in b_ind:
                vector = (b[0] - a[0], b[1] - a[1])
                count[vector] += 1
                max_count = max(max_count, count[vector])
        return max_count                        
__________________________________________________________________________________________________
