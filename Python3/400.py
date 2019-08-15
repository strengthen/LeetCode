__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def findNthDigit(self, n: int) -> int:
        length = 1
        cnt = 9
        start = 1
        while n > cnt*length:
            n -= cnt*length
            length += 1
            cnt *= 10
            start *= 10
            
        start += (n-1)//length
        s = str(start)
        return int(s[(n-1) % length])
__________________________________________________________________________________________________
sample 13064 kb submission
#
# @lc app=leetcode id=400 lang=python3
#
# [400] Nth Digit
#


class Solution:
    def findNthDigit(self, n: int) -> int:

        length = 1
        times = 1
        while n > length * 9 * times:
            n -= length * 9 * times
            length += 1
            times *= 10

        offset_num = (n-1) // length
        offset_digit = (n-1) % length

        digit = str(times + offset_num)[offset_digit]
        return int(digit)
__________________________________________________________________________________________________
