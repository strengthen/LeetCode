__________________________________________________________________________________________________
sample 140 ms submission
class Solution:
    def kthSmallestPrimeFraction(self, A: List[int], K: int) -> List[int]:
        l, r = 1 / A[-1], 1
        n = len(A)
        while l < r:
            mid = (l + r) / 2
            p, q = 0, 0
            cnt = 0
            val = -1
            i = 0
            for j in range(n - 1):
                while i < n and A[j] / A[i] > mid:
                    i += 1
                if i == n:
                    break
                cnt += n - i
                if A[j] / A[i] > val:
                    p, q = A[j], A[i]
                    val = p / q
                
            if cnt == K:
                return [p, q]
            elif cnt < K:
                l = mid
            else:
                r = mid
__________________________________________________________________________________________________
sample 13264 kb submission
from heapq import *
class Solution:
    def kthSmallestPrimeFraction(self, A: List[int], K: int) -> List[int]:
        fractions = []
        for i in reversed(range(1, len(A))):
            fractions.append((A[0]/float(A[i]), 0, i))
        for _ in range(K-1):
            frac, i, j = heappop(fractions)
            i += 1
            if (i < j):
                heappush(fractions, (A[i]/float(A[j]), i, j))
        return [A[fractions[0][1]], A[fractions[0][2]]]
__________________________________________________________________________________________________
