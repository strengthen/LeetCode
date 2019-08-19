__________________________________________________________________________________________________
sample 1396 ms submission
from bisect import bisect_right, insort_right

class Solution:
    def reversePairs(self, nums):
        if not nums: return 0
        
        seen = []
        res = 0
        for x in nums:
            res += len(seen) - bisect_right(seen, 2*x)
            idx = bisect_right(seen, x)
            seen[idx:idx] = [x]
        return res
__________________________________________________________________________________________________
sample 18000 kb submission
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        
        return self.merge_and_count(nums, 0, len(nums)-1)
        
    def merge_and_count(self, nums, l, r):
        if l >= r:
            return 0
        
        mid = (l + r) // 2
        
        left_count = self.merge_and_count(nums, l, mid)
        right_count = self.merge_and_count(nums, mid+1, r)
        
        cnt = 0
        j = mid + 1
        for i in range(l, mid+1):
            while j <= r and nums[i] > 2*nums[j]:
                j += 1
            cnt += j - mid - 1
        
        leftnums = nums[l : mid+1]
        rightnums = nums[mid+1 : r+1]
        
        i = 0
        j = 0
        
        while i + j <= r - l:
            if j >= r - mid or (i <= mid - l and leftnums[i] <= rightnums[j]):
                nums[l+i+j] = leftnums[i]
                i += 1
            else:
                nums[l+i+j] = rightnums[j]
                j += 1
        
        return cnt + left_count + right_count
__________________________________________________________________________________________________
