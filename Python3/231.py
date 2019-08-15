__________________________________________________________________________________________________
sample 20 ms submission
import itertools

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        s = bin(n)[2:]
        print(s)
        if s.count('1') > 1:
            return False
        return True
__________________________________________________________________________________________________
sample 13032 kb submission
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 1:
            return True
        if n%2==0:
            x=0
            while True:
                x+=1
                if 2**x > n:
                    break
                if 2**x == n:
                    return True
        return False
__________________________________________________________________________________________________
