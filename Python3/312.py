__________________________________________________________________________________________________
sample 276 ms submission
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + list(filter(lambda i: i != 0, nums)) + [1]
        n = len(nums)
        dp = [[0 for i in range(n)] for i in range(n)]

        for i in range(n-1, -1, -1):
            for j in range(i + 2, n):
                for last in range(i + 1, j):
                    v = dp[i][last] + dp[last][j] + \
                        nums[i] * nums[last] * nums[j]
                    if v > dp[i][j]: dp[i][j] = v
        return dp[0][n-1]
__________________________________________________________________________________________________
sample 13452 kb submission
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums) + nums[0] * nums[1]
        
    
        dp = [[0] * n for i in range(n+1)]
        
        dp[0][0] = nums[0] * nums[1]
        for i in range(1, n-1):
            dp[i][i] = nums[i-1] * nums[i] * nums[i+1]
        dp[n-1][n-1] = nums[n-2] * nums[n-1]
        
        for step in range(2, n + 1):
            for i in range(n-step+1):
                #nums[i:i+step]
                if i == 0:
                    prev = 1
                else:
                    prev = nums[i-1]
                if i + step == n:
                    post = 1
                else:
                    post = nums[i+step]
                    
                maxValue = 0
                for j in range(i, i+step):
                    maxValue  = max(maxValue, prev * nums[j] * post + dp[i][j-1] + dp[j+1][i+step-1])
                dp[i][i+step-1] = maxValue
        return dp[0][n-1]
__________________________________________________________________________________________________
