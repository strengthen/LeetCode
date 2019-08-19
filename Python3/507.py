__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        return num in (6, 28, 496, 8128, 33550336)
__________________________________________________________________________________________________
sample 12948 kb submission
class Solution:
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        res = 1
        if num == 1:
            return False
        i = 2
        while i * i <= num:
            if num % i == 0:
                res += i
                if i != num // i:
                    res += (num // i)
            i += 1
        return num == res
__________________________________________________________________________________________________
