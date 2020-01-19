__________________________________________________________________________________________________
sample 4 ms submission
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        a = 0
        b = 1
        for i in [int(i) for i in str(n)]:
            b *= i
            a += i
        return  b - a
__________________________________________________________________________________________________
sample 8 ms submission
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        p, s = 1, 0
        if n == 0:
            return 0
        while(n > 0):
            t = n % 10
            p *= t
            s += t
            n = n//10
        return p-s
__________________________________________________________________________________________________
