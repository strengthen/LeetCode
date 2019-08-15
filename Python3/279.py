__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def numSquares(self, n: int) -> int:
        while not (n%4):       #results are the same for n and 4n
            n /= 4
        if n%8 == 7:
            return 4
        x = math.ceil(math.sqrt(n))
        for i in range(x):
            j = math.floor(math.sqrt(n - i*i))
            if i*i + j*j == n:
                if i > 0 and j > 0:
                    return 2
                else:
                    return 1           
        return 3  
__________________________________________________________________________________________________
sample 13244 kb submission
class Solution(object):
    _dp = [0]
    def numSquares(self, n):
        dp = self._dp
        while len(dp) <= n:
            dp += min(dp[-i*i] for i in range(1, int(len(dp)**0.5+1))) + 1,
        return dp[n]            
__________________________________________________________________________________________________
