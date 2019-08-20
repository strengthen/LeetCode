__________________________________________________________________________________________________
sample 212 ms submission
class Solution:
    
    # 思路：最少要排序的长度，是从左第一个下降点，和从右第一个上升点间的距离。
    # 而不用排序又要满足条件，左边最大值小于右边所有，右边最小值大于左边所有，
    # 边界问题是最麻烦的，思路其实懂了就很简单
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return 0
        l = len(nums)
        left = 0
        while left < l-1:
            if nums[left] <= nums[left+1]:
                left += 1
            else:
                break
        right = l-1
        while right > left:
            if nums[right] >= nums[right-1]:
                right -= 1
            else:
                break
        if left >= right:
            return 0
        leftMin = min(nums[left+1:])
        rightMax = max(nums[:right])
        while left >= 0:
            if nums[left] > leftMin:
                left -= 1
            else:
                break
        while right < l:
            if nums[right] < rightMax:
                right += 1
            else:
                break
        
        return right - left - 1
__________________________________________________________________________________________________
sample 13844 kb submission
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        if nums == sorted(nums):
            return 0
        
        left = 0
        right = 0
        
        sort_arr = sorted(nums)
        for i in range(0, len(nums)):
            if nums[i] != sort_arr[i]:
                left = i
                break
        for j in range(len(nums) - 1, left, -1):
             if nums[j] != sort_arr[j]:
                right = j
                break
        
        return right - left + 1
__________________________________________________________________________________________________
