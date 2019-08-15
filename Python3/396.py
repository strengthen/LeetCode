__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        f0 = 0
        maxi = -sys.maxsize
        for i in range(len(A)):
            f0 += A[i] * i
        maxi = max(maxi, f0)
        s = sum(A)
        for i in range(1, len(A)):
            f0 += s
            f0 -= A[-i] * len(A)
            maxi = max(maxi, f0)
        return maxi
__________________________________________________________________________________________________
sample 13756 kb submission
class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        n = len(A)
        f = 0
        s = 0
        for i in range(n):
            f = f + A[i]*i
            s = s + A[i]
        
        mf = f
        for i in range(n - 1):
            f = f - s + A[i] * n
            mf = max(mf, f)
            
        return mf
__________________________________________________________________________________________________
