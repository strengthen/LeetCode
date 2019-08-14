__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        if len(nums) == 2: return max(nums)

        dp = [0]*len(nums)
        dp[0], dp[1] = nums[0], max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            dp[i] = max(dp[i-2]+nums[i], dp[i-1])
        
        return dp[-1]
__________________________________________________________________________________________________
sample 12932 kb submission
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if len(nums) <= 2:
            return max(nums)
        
        dp = [0, nums[0]] + [0] * (len(nums)-1)
        for i in range(1, len(nums)):
            dp[i+1] = max(dp[i], dp[i-1]+nums[i])
        return dp[-1]        
__________________________________________________________________________________________________
