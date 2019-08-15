__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for num in nums:
            if nums[abs(num)] < 0:
                return abs(num)
            else:
                nums[abs(num)] = -nums[abs(num)]
__________________________________________________________________________________________________
sample 14232 kb submission
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        low, high = 1, len(nums) - 1
        while low <= high:
            mid = (low + high) >> 1
            cnt = sum(x <= mid for x in nums)
            if cnt > mid:
                high = mid - 1
            else:
                low = mid + 1
        return low
__________________________________________________________________________________________________
