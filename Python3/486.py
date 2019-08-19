__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        if n==1 or n%2==0: return True
        dp = [[0]*n for _ in range(n)]
        for i in range(n-1, -1, -1):
            for j in range(i+1, n):
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1])
        return dp[0][-1]>=0
__________________________________________________________________________________________________
sample 13192 kb submission
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        f = [0] * n
        
        
        for r in range(1, n):
            for l in range(r)[::-1]:
                f[l] = max(nums[l] - f[l+1], nums[r] - f[l])
     
        return f[0] >= 0
__________________________________________________________________________________________________
