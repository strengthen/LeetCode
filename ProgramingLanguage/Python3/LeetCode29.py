__________________________________________________________________________________________________
40ms
import math

class Solution:
    def divide(self, dividend, divisor):
        if dividend * divisor < 0:
            res = (dividend //  (-1 * divisor)) * (-1)
            if res < (-2) ** 31:
                res = (-2) ** 31
        else:
            res = dividend // divisor
            if res > 2 ** 31 - 1:
                res = 2 ** 31 - 1
        return res
__________________________________________________________________________________________________
44ms
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2147483647
        if divisor == 0:
            return INT_MAX
        neg = dividend > 0 and divisor < 0 or dividend < 0 and divisor > 0
        a, b = abs(dividend), abs(divisor)
        ans, shift = 0, 31
        while shift >= 0:
            if a >= b << shift:
                a -= b << shift
                ans += 1 << shift
            shift -= 1
        if neg:
            ans = - ans
        if ans > INT_MAX:
            return INT_MAX
        return ans
__________________________________________________________________________________________________
48ms
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        neg = False
        total = 0
        
        if dividend == 0:
            return 0
        
        if (dividend < 0):
            dividend = eval('-' + str(dividend))
            neg = True
        if (divisor < 0):
            divisor = eval('-' + str(divisor))
            neg = True if neg == False else False
            
        if divisor > dividend:
            return 0
        newdivisor = divisor        
__________________________________________________________________________________________________
12248 kb
class Solution:
    def divide(self, dividend: 'int', divisor: 'int') -> 'int':
        MAX = 2**31-1
        MIN = -2**31
        # if divisor > dividend:
        #     return 0
        if divisor == 1:
            if dividend > MAX:
                return MAX
            elif dividend < MIN:
                return MIN
            else:
                return dividend
        elif divisor == -1:
            if dividend > MAX+1:
                return MIN
            elif dividend < MIN+1:
                return MAX
            else:
                return 0 - dividend
        else:
            return int(dividend/divisor)
__________________________________________________________________________________________________
12292 kb 
class Solution:
    def divide(self, dividend: 'int', divisor: 'int') -> 'int':
        if (dividend == -2147483648 and divisor == -1): 
            return 2147483647
        factor = 1
        if dividend < 0: 
            factor *= -1
            dividend = abs(dividend)
        if divisor < 0: 
            factor *= -1
            divisor = abs(divisor)

        res = 0
        
        for i in range(32)[::-1]:
            if (dividend >> i) - divisor >= 0:
                res += 1 << i
                dividend -= divisor << i

        return res*factor
__________________________________________________________________________________________________
