__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def smallestGoodBase(self, n: str) -> str:
        n = int(n)
        for k in range(2, math.ceil(math.log(n, 2)))[::-1]:
            x = int(n**k**-1)
            if (x**(k + 1) - 1) // (x - 1) == n:
                return str(x)
        return str(n - 1)
__________________________________________________________________________________________________
sample 13132 kb submission
class Solution:
    def smallestGoodBase(self, n: str) -> str:
        n = int(n)
        ans = str(n-1)
        for k in range(1,int(math.log(n, 2))+1):
            a = int(n ** k ** -1)
            if (1 - a ** (k + 1)) // (1 - a) == n:
                ans = str(a)
        
        return ans
__________________________________________________________________________________________________
