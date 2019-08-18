__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        size = len(A)
        if size < 3:
            return 0
        # dp[i]表示以A[i]为起点的ArithmeticSlices的个数
        dp = [0 for _ in range(size - 2)]
        dp[size - 3] = 1 if A[size - 1] - A[size - 2] == A[size - 2] - A[size - 3] else 0
        for i in range(size - 4, -1, -1):
            if A[i + 2] - A[i + 1] == A[i + 1] - A[i]:
                dp[i] = dp[i + 1] + 1
        return sum(dp)
__________________________________________________________________________________________________
sample 13012 kb submission
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        last = 0
        res = 0
        for i in range(2, len(A)):
            if A[i] - A[i-1] == A[i-1]-A[i-2]:
                last += 1
                res += last
            else:
                last = 0
        return res
__________________________________________________________________________________________________
