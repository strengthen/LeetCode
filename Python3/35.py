__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            if target > nums[0]:
                return 1
            return 0
        
        midpoint = len(nums) // 2
        if target >= nums[midpoint]:
            return midpoint + self.searchInsert(nums[midpoint:], target)
        else:
            return self.searchInsert(nums[:midpoint], target)
__________________________________________________________________________________________________
sample 13240 kb submission
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:        
        # for i, num in enumerate(nums):
        for i in range(len(nums)):
            if nums[i] >= target:
                return i
        return len(nums)
__________________________________________________________________________________________________
