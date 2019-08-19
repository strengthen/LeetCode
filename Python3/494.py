__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        s=sum(nums)
        if (s+S)%2 or s<S:
            return 0
        target=(s+S)//2
        dp=[0 for i in range(target+1)]
        dp[0]=1
        for n in nums:
            for i in range(target,n-1,-1):
                dp[i]+=dp[i-n]
        return dp[-1]
__________________________________________________________________________________________________
sample 13092 kb submission
class Solution(object):
    def findTargetSumWays(self, nums, S):
        if not nums:
            return 0
        dic = {nums[0]: 1, -nums[0]: 1} if nums[0] != 0 else {0: 2}
        for i in range(1, len(nums)):
            tdic = {}
            for d in dic:
                tdic[d + nums[i]] = tdic.get(d + nums[i], 0) + dic.get(d, 0)
                tdic[d - nums[i]] = tdic.get(d - nums[i], 0) + dic.get(d, 0)
            dic = tdic
        return dic.get(S, 0)
__________________________________________________________________________________________________
