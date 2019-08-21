__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def atMostNGivenDigitSet(self, D: List[str], N: int) -> int:
        N = str(N)
        n = len(N)
        m = len(D)
        res = 0
        # for integers with digits less than n
        for i in range(1, n):
            res += m ** i
        # for integers with digits equal to n
        for i in range(n):
            count = 0
            for num in D:
                if num < N[i]:
                    count += 1
            res += count * m ** (n - i - 1)
            if N[i] not in D:
                break
        
        if i == n - 1 and N[i] in D:
            res += 1
            
        return res
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def atMostNGivenDigitSet(self, D: List[str], N: int) -> int:
        N_str = str(N)
        n = len(N_str)
        dp = [0] * n + [1]
        
        for i in reversed(range(n)):
            for d in D:
                if d < N_str[i]:
                    dp[i] += len(D) ** (n - i - 1)
                elif d == N_str[i]:
                    dp[i] += dp[i + 1]
        
        return dp[0] + sum(len(D) ** i for i in range(1, n))
__________________________________________________________________________________________________
