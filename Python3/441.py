__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def arrangeCoins(self, n: int) -> int:
        # 1, 2, 3, 4, 5, 6, ...
        # n = (steps**2 + steps)/2
        
        # sn = n * (n+1) / 2
        
        
        sqrt = math.sqrt(1 + (4*2*n))
        c1 = int((-1 + sqrt)//2)
        return c1        
__________________________________________________________________________________________________
sample 13088 kb submission
class Solution:
    def arrangeCoins(self, n: int) -> int:
        
        if n == 0:
            return 0
        sm = 0
        for i in range(1,n+1):
            sm = sm+i
            if sm>n:
                sm = sm-i
                return i-1 
        
        #sm = k*(k+1)/2
        return i
__________________________________________________________________________________________________
