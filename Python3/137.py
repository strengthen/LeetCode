__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        a = 0
        b = 0
        for n in nums:
            last_b = b
            b = ~a & (b^n)
            a = (a^last_b) & (a^n)
        return ~a & b        
__________________________________________________________________________________________________
sample 13944 kb submission
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a, b = 0, 0
        for c in nums:
            a, b = (~a & b & c) | (a & ~b & ~c), (~a & b & ~c) | (~a & ~b & c)
        return b
__________________________________________________________________________________________________
