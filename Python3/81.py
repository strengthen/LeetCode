__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def search(self, A: List[int], target: int) -> int:
        lo = 0
        hi = len(A) - 1
        
        while lo <= hi:
            mid = (lo + hi) // 2
            
            if A[mid] == target:
                return True
            
            while lo < mid and A[lo] == A[mid]: # tricky part
                lo += 1
            
            if A[lo] <= A[mid]:
                if A[lo] <= target < A[mid]:
                    hi = mid - 1
                else:
                    lo = mid + 1
            else:
                if A[mid] < target <= A[hi]:
                    lo = mid + 1
                else:
                    hi = mid - 1
        return False
__________________________________________________________________________________________________
sample 13300 kb submission
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if not nums:
            return False
        
        l, r = 0, len(nums) - 1
        while l <= r:
            while l < r and nums[l] == nums[r]:
                l += 1
            
            mid = (l + r) // 2
            if nums[mid] == target:
                return True
            
            if nums[l] <= nums[mid]:
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return False
__________________________________________________________________________________________________
