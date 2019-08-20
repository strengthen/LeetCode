__________________________________________________________________________________________________
sample 260 ms submission
from bisect import bisect_left
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        try:
            ind = bisect_left(nums, target)
            return ind if nums[ind]==target else -1
        except:
            return -1
__________________________________________________________________________________________________
sample 13992 kb submission
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)-1
        while l <= r:
            mid = (l+r)//2
            if nums[mid] < target:
                l = mid+1
            elif nums[mid] > target:
                r = mid-1
            else:
                return mid
        return -1
__________________________________________________________________________________________________
