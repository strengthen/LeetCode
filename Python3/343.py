__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1
        if n == 3:
            return 2
        ans = 1
        while n > 4:
            ans *= 3
            n -= 3
        ans *= n
        return ans      
__________________________________________________________________________________________________
sample 13120 kb submission
class Solution:
    def integerBreak(self, n: int) -> int:
        memo = [-1]*(n+1)
        memo[1] = 1
        for i in range(2,n+1):
            for j in range(1,i):
                memo[i] = max(max(memo[i],j*(i-j)),j*memo[i-j])
        return memo[n]
__________________________________________________________________________________________________
