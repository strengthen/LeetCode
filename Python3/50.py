__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
        # if not n:
            return 1
        if n < 0:
            return 1 / self.myPow(x, -n)
        if n % 2:
            return x * self.myPow(x, n-1)
        return self.myPow(x*x, n//2)
        # return self.myPow(x**2,n//2) if n%2 == 0 else x*self.myPow(x,n-1)
__________________________________________________________________________________________________
sample 12776 kb submission
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x ==0 or x == 1 or n ==1:
            return x
        if n == 0:
            return 1
        if n < 0:
            x, n =1/x, abs(n)
        if n%2 ==0:
            return self.myPow(x*x, n/2)
        return self.myPow(x, n-1)*x   
__________________________________________________________________________________________________
