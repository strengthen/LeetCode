__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def mySqrt(self, x: int) -> int:
        from math import sqrt
        assert x>=0
        return int(sqrt(x))
__________________________________________________________________________________________________
sample 13008 kb submission
class Solution:
    def mySqrt(self, x: int) -> int:
        # 4 = 2*2
        # 9 = 3*3
        return int(x ** (1/2))
__________________________________________________________________________________________________
