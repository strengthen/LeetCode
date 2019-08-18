__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums = list(set(nums))
        nums.sort(reverse=True)
        if len(nums) <3:
            return max(nums)
        return nums[2]
__________________________________________________________________________________________________
sample 13632 kb submission
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        
        
        one = -float('inf')
        two = -float('inf')
        three = -float('inf')
        
        for num in nums:
            if num > one:
                one, two, three = num, one, two
            elif two < num < one:
                two, three = num, two
            elif three < num < two:
                three = num
                
        if three == -float('inf'):
            return one
        else:
            return three
__________________________________________________________________________________________________
