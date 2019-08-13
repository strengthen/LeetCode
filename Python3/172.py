__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def trailingZeroes(self, n: int) -> int:
        f = 5
        pieces = int(n / f)
        result = 0
        while pieces >= 1:
            result += pieces
            f *= 5
            pieces = int(n / f)
        return result
__________________________________________________________________________________________________
sample 13120 kb submission
class Solution:
    def trailingZeroes(self, n: int) -> int:
        
        result = 0
        
        while n > 0:
            result += (n // 5)
            n = n // 5
            
        return result
__________________________________________________________________________________________________
