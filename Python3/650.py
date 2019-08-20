__________________________________________________________________________________________________
sample 28 ms submission
import math

class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        if n == 2:
            return 2
        
        def gcd(num):
            greatest = 1
            
            for i in range(2, num // 2):
                if num % i == 0:
                    greatest = i
                    
            return greatest
        
        def rec(num):
            if gcd(num) == 1:
                return num
            
            g = gcd(num)
            got = rec(g)
            return got + num // g
        
        return rec(n)
__________________________________________________________________________________________________
sample 12972 kb submission
class Solution:
    def minSteps(self, n: int) -> int:
        ans = 0
        f = 2
        while n > 1:
            while n % f == 0:
                ans += f
                n /= f
            f += 1
        return ans
__________________________________________________________________________________________________
