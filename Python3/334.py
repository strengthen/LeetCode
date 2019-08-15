__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        mid, right = float('-inf'), float('-inf')
        
        
        for i in range(len(nums)-1, -1, -1):
            num = nums[i]
            
            if num >= right:
                right = num
            elif num >= mid:
                mid = num
            else:
                return True
            
        return False
__________________________________________________________________________________________________
sample 13284 kb submission
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        small = float('inf')
        large = float('inf')
        for num in nums:
            if num <= small:
                small = num
            elif num <= large:
                large = num
            else:
                return True
        return False
__________________________________________________________________________________________________
