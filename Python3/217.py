__________________________________________________________________________________________________
sample 120 ms submission
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))
__________________________________________________________________________________________________
sample 16208 kb submission
class Solution:
    def containsDuplicate(self, nums: 'List[int]') -> 'bool':
        nums = sorted(nums)
        for i in range(0,len(nums)-1):
            if nums[i] == nums[i+1]:
                return True
        return False
__________________________________________________________________________________________________
