__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid
        return nums[left]
__________________________________________________________________________________________________
sample 13016 kb submission
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums)>1:
            for i in range(len(nums)-1):
                if nums[i]>nums[i+1]:
                    return nums[i+1]
        return nums[0]
__________________________________________________________________________________________________
