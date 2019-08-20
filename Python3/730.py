__________________________________________________________________________________________________
sample 472 ms submission
class Solution:
    def countPalindromicSubsequences(self, S: str) -> int:
        dp0, dp1 = [0] * len(S), [0] * len(S)
        ans = 0
        for i in range(len(S)):
            x = 1
            for j in range(i-1,-1,-1):
                if S[j] == S[i]:
                    n = dp0[j] + 1
                    dp0[j] += x
                    x = n - dp1[j]
                    dp1[j] = n
                else:
                    dp0[j] += x
            ans += x
        return ans % 1000000007
__________________________________________________________________________________________________
sample 816 ms submission
from functools import lru_cache

class Solution:
    def countPalindromicSubsequences(self, s):
        n = len(s)
        prefix = [[None] * n for _ in range(4)]
        suffix = [[None] * n for _ in range(4)]

        latest = [None] * 4
        char_map = {c: i for (c, i) in zip(['a', 'b', 'c', 'd'], range(4))}

        for i in range(n - 1, -1, -1):
            c = s[i]
            loc = char_map[c]
            latest[loc] = i
            for letter_index in range(4):
                suffix[letter_index][i] = latest[letter_index]

        latest = [None] * 4
        for i in range(n):
            c = s[i]
            loc = char_map[c]
            latest[loc] = i
            for letter_index in range(4):
                prefix[letter_index][i] = latest[letter_index]

        @lru_cache(None)
        def dp(i, j):
            tot = 1
            if i <= j:
                for letter_index in range(4):
                    first = suffix[letter_index][i]
                    last = prefix[letter_index][j]

                    if first is not None and i <= first <= j:
                        tot += 1

                    if first is not None \
                    and last is not None \
                    and first < last:
                        tot += dp(first + 1, last - 1)
            return tot % (10 ** 9 + 7)

        return dp(0, n - 1) - 1
__________________________________________________________________________________________________
