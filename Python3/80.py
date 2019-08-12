__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        for num in nums:
            if i < 2 or nums[i-2] < num:
                nums[i] = num
                i += 1
        return i
__________________________________________________________________________________________________
sample 12948 kb submission
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        for n in nums:
            if i < 2 or n > nums[i-2]:
                nums[i] = n
                i += 1
        return i
__________________________________________________________________________________________________
