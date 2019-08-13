__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while l+1 < r:
            mid = (l+r)//2
            if nums[mid] == nums[l]:
                l += 1
            elif nums[mid] <= nums[r]:
                r = mid
            else:
                l = mid 
        if nums[l] < nums[r]:
            return nums[l] 
        else:
            return nums[r]        
__________________________________________________________________________________________________
sample 13216 kb submission
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        
        low, high = 0, len(nums)
        mid = (low + high) // 2
        if nums[low] == nums[high-1]:
            return min(self.findMin(nums[low:mid]),self.findMin(nums[mid:high]))
        
        if nums[low] < nums[high-1]:
            return nums[low]
        
        if nums[low] > nums[high-1]:
            if nums[mid]<nums[high-1]:
                return self.findMin(nums[low:mid+1])
            if nums[mid]==nums[high-1]:
                return min(self.findMin(nums[low:mid]),self.findMin(nums[mid:high]))            
            else:
                return self.findMin(nums[mid:high])
__________________________________________________________________________________________________
