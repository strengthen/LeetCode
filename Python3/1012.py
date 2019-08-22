__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        res, L, k = 0, map(int, str(N + 1)), len(str(N + 1))
        seen = set()
        def nCr(m, n):
            return 1 if n == 0 else nCr(m, n - 1) * (m - n + 1)

        for i, v in enumerate(L):
            for j in range((0, 1)[i == 0], v):
                if j not in seen:
                    res += nCr(9-i, k - i - 1)
            if v in seen: break
            seen.add(v)

        for i in range(1, k):
            res += 9 * nCr(9, i - 1)
        return N - res
__________________________________________________________________________________________________
sample 13132 kb submission
from functools import lru_cache

@lru_cache(None)
def P(n, k):
    if k == 0:
        return 1
    return n * P(n - 1, k - 1)

class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        digits = [int(d) for d in str(N)]
        ndigits = len(digits)
        if ndigits < 2:
            return 0
        ans = 0
        for k in range(ndigits - 1):
            ans += 9 * P(9, k)
        ans += (digits[0] - 1) * P(9, ndigits - 1)
        selected = {digits[0]}
        idx = 1
        for d in digits[1:]:
            idx += 1
            nchoice = d - sum(x < d for x in selected)
            ans += nchoice * P(10 - idx, ndigits - idx)
            if d in selected:
                break
            selected.add(d)
        else:
            ans += 1
        return N - ans
__________________________________________________________________________________________________
