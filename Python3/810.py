__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        if len(nums) % 2 == 0:
            return True
        else:
            res = 0
            for num in nums:
                res ^= num
            return res == 0
__________________________________________________________________________________________________
sample 88 ms submission
import functools
class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        return not len(nums)%2 or not functools.reduce(lambda x, y: x^y, nums)
__________________________________________________________________________________________________
