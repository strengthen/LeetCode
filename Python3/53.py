__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        m=msf=nums[0]
        for num in nums[1:]:
            msf=num+max(0,msf)
            m=max(m,msf)
        return m
__________________________________________________________________________________________________
sample 13104 kb submission
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = float('-inf')
        cur_sum = 0
        for num in nums:
            cur_sum += num
            if cur_sum > max_sum:
                max_sum = cur_sum
            if cur_sum < 0:
                cur_sum = 0
        return max_sum
__________________________________________________________________________________________________
