__________________________________________________________________________________________________
sample 36 ms submission
from collections import defaultdict
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        total = 1
        dic = defaultdict(int)
        m = 10 ** 9 + 7
        for c in S:
            t = total
            total += total - dic[c]
            total %= m
            dic[c] = t
        return (total - 1) % m
__________________________________________________________________________________________________
sample 13096 kb submission
class Solution:
    def distinctSubseqII(self, S):
        N = len(S)
        dp, seen = [1] + [0] * N, dict()
        for i, c in enumerate(S, start = 1):
            dp[i] = (dp[i-1] * 2) % (10**9 + 7)
            if c in seen:
                dp[i] -= dp[seen[c] - 1]
            seen[c] = i
        return (dp[N] - 1) % (10**9 + 7)
__________________________________________________________________________________________________
