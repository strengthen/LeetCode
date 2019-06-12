__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        counter = collections.Counter(tiles)
        memo = {}
        return self.dfs(counter, memo)
    
    def dfs(self, counter, memo):
        key = ''
        for k, v in counter.items():
            key += k * v
        if key in memo:
            return memo[key]
        res = 0
        for k, v in counter.items():
            if v == 0:
                continue
            counter[k] -= 1
            res += 1
            res += self.dfs(counter, memo)
            counter[k] += 1
        memo[key] = res
        return res
__________________________________________________________________________________________________
sample 36 ms submission
from collections import Counter
class Solution:
    def numTilePossibilities(self, tiles):
        f = {0:1, 1:1, 2:2, 3:6, 4:24, 5:120, 6:720, 7:5040}
        cnt = list(Counter(tiles).values())
        N = len(cnt)
        def dfs(total, pros, i):
            if i == N:
                return f[total]//pros
            return sum(dfs(total + X, pros * f[X], i + 1) for X in range(cnt[i] + 1))
        return dfs(0, 1, 0) - 1
__________________________________________________________________________________________________
sample 40 ms submission
import itertools
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        r = 0
        for i in range(1, len(tiles) + 1):
            r += len(set(itertools.permutations(tiles, r=i)))
        return r