__________________________________________________________________________________________________
sample 52 ms submission
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 == 3**19 % n
__________________________________________________________________________________________________
sample 13076 kb submission
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        while n > 1:
            n, res = divmod(n, 3)
            if res:
                return False
        return True
__________________________________________________________________________________________________
