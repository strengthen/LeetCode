__________________________________________________________________________________________________
sample 180 ms submission
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        mid=len(nums[::2])
        nums[::2],nums[1::2]=nums[:mid][::-1],nums[mid:][::-1]
__________________________________________________________________________________________________
sample 14024 kb submission
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        mid = (len(nums) + 1) // 2
        nums[::2], nums[1::2] = nums[:mid][::-1], nums[mid:][::-1]
__________________________________________________________________________________________________
