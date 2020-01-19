__________________________________________________________________________________________________
sample 256 ms submission
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        import functools
        return functools.reduce(math.gcd, nums, nums[0])==1
__________________________________________________________________________________________________
sample 260 ms submission
import math
import functools

class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        return functools.reduce(math.gcd, nums) < 2
__________________________________________________________________________________________________
