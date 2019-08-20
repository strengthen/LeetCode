__________________________________________________________________________________________________
sample 308 ms submission
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum(nums[::2])
__________________________________________________________________________________________________
sample 14740 kb submission
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        if not nums or len(nums) % 2 != 0:
            return 0
        nums.sort()
        s = sum([nums[i] for i in range(len(nums)) if i % 2 == 0])
        return s
__________________________________________________________________________________________________
