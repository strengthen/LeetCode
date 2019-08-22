__________________________________________________________________________________________________
sample 92 ms submission
class Solution:
    def minScoreTriangulation(self, A: List[int]) -> int:
        if len(A) < 3:
            return 0
        elif len(A) == 3:
            return A[0]*A[1]*A[2]
        else:
            dp = [[0]*len(A) for i in range(len(A))]
            for d in range(2, len(A)):
                for i in range(len(A)-d):
                    j = i+d
                    dp[i][j] = min(dp[i][k] + dp[k][j] + A[i]*A[j]*A[k] for k in range(i+1,j))
            return dp[0][len(A)-1]
__________________________________________________________________________________________________
sample 120 ms submission
import sys
class Solution:
    cache = {}
    def minScoreTriangulation(self, A) -> int:
        if len(A) < 3:
            return 0
        if len(A) == 3:
            return A[0] * A[1] * A[2]
        
        dp = [[0]*len(A) for _ in range(len(A))]
        for i in range(2, len(A)):
            for j in range(0, len(A)-i):
                k = j + i
                dp[j][k] = sys.maxsize
                for m in range(j+1, k):
                    dp[j][k] = min(dp[j][k], dp[j][m]+dp[m][k]+A[j]*A[m]*A[k])
        # print(dp)
        return dp[0][-1]

# s = Solution()
# res = s.minScoreTriangulation([3, 7, 4, 5])
# print(res)
__________________________________________________________________________________________________
