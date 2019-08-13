__________________________________________________________________________________________________
sample 172 ms submission
class Solution:
        
    def majorityElement(self, nums: List[int]) -> int:      
        max_count = 0
        max_num = 0
        setofn = set(nums)
        for val in setofn:
            if nums.count(val) > max_count:
                max_count = nums.count(val)
                max_num = val
            
        return max_num
__________________________________________________________________________________________________

__________________________________________________________________________________________________
