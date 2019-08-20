__________________________________________________________________________________________________
sample 156 ms submission
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if not nums:
            return -1
        right = sum(nums)
        left = 0
        for i, num in enumerate(nums):
            right -= num
            if left == right:
                return i
            left +=num
        else:
            return -1
__________________________________________________________________________________________________
sample 13876 kb submission
#
# @lc app=leetcode id=724 lang=python3
#
# [724] Find Pivot Index
#
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return -1

        pivot_index = 0
        l_sum = 0
        r_sum = sum(nums[1:])

        while l_sum != r_sum and pivot_index < len(nums) - 1:
            l_sum += nums[pivot_index]
            pivot_index += 1
            r_sum -= nums[pivot_index]

        return pivot_index if l_sum == r_sum else -1

__________________________________________________________________________________________________
