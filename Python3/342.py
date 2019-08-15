__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num > 0:
            binary = str(bin(num))[2:]
            if binary.count('1') == 1:
                if binary.count('0') % 2 == 0:
                    return True
        return False
__________________________________________________________________________________________________
sample 13040 kb submission
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num == 1:
            return True
        if num%4 != 0:
            return False
        while(num > 1):
            if num%4 != 0:
                break
            num = num/4
        if num == 1:
            return True
        else: 
            return False
__________________________________________________________________________________________________
