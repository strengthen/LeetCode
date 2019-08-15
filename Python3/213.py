__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def rob(self, nums: List[int]) -> int:
        
        if  not nums: return 0
            
        n = len(nums)
        
        dp_w = [0]*(n+1)
        
        dp_w[1] = nums[0]
        
        dp_wo = [0]*(n+1)
        
        ans = dp_w[1]
        
        for i in range(1,n):
            
            if i<n-1: dp_w[i+1] = max(dp_w[i-1]+nums[i],dp_w[i])
            
            dp_wo[i+1] = max(dp_wo[i-1]+nums[i],dp_wo[i])
            
            ans = max(dp_w[i+1],dp_wo[i+1],ans)
        
        return ans
__________________________________________________________________________________________________
sample 12924 kb submission
class Solution:
    def rob(self, nums: List[int]) -> int:
        def dp(nums):
            l, n =0, 0
            for i in nums:
                l, n = n, max(l+i,n)
            return n
        return max(dp(nums[len(nums) != 1:]),dp(nums[:-1]))
__________________________________________________________________________________________________
