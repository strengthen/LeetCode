__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        
        if not nums:
            return 0
        
        length = 1
        up = None 
        
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1] and up != True:
                length += 1
                up = True
            if nums[i] < nums[i - 1] and up != False:
                length += 1
                up = False
        return length
__________________________________________________________________________________________________
sample 13008 kb submission
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        size = len(nums)
        inc = dec = 1
        for x in range(1, size):
            if nums[x] > nums[x - 1]:
                inc = dec + 1
            elif nums[x] < nums[x - 1]:
                dec = inc + 1
        return max(inc, dec) if size else 0
__________________________________________________________________________________________________
