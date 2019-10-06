__________________________________________________________________________________________________
sample 108 ms submission
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        # a -> e
        # e -> a, i
        # i -> a, e, o, u
        # o -> i, u
        # u -> a
        mod = 1000000007
        a, e, i, o, u = 1, 1, 1, 1, 1
        for _ in range(n - 1):
            a, e, i, o, u = (e + i + u) % mod, (a + i) % mod, (e + o) % mod, i, (i + o) % mod
        return (a + e + i + o + u) % mod
__________________________________________________________________________________________________
sample 160 ms submission
import numpy as np

class Mint:
    def __init__(self, value):
        self.value = value % (10**9 + 7)
    def __add__(self, other):
        return Mint(self.value + other.value)
    def __mul__(self, other):
        return Mint(self.value * other.value)

class Solution:
    
    def countVowelPermutation(self, n: int) -> int:
        
        O = Mint(0)
        I = Mint(1)
        
        transition = np.matrix([
            [O, I, O, O, O],
            [I, O, I, O, O],
            [I, I, O, I, I],
            [O, O, I, O, I],
            [I, O, O, O, O]
        ], dtype=object)
        
        x = transition**(n - 1)
        res = np.sum(x)
        return res.value if type(res) != int else res
__________________________________________________________________________________________________
sample 804 ms submission
from functools import lru_cache
m = 10**9 + 7

import sys

sys.setrecursionlimit(10**6)

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        
        @lru_cache(None)
        def dp(idx, last):
            if idx == n: return 1
            if last == 'a':
                return dp(idx + 1, 'e') % m
            if last == 'e':
                return (dp(idx + 1, 'a') + dp(idx + 1, 'i')) % m
            if last == 'i':
                return sum(dp(idx + 1, j) for j in 'aeou') % m
            if last == 'o':
                return (dp(idx + 1, 'u') + dp(idx + 1, 'i')) % m
            if last == 'u':
                return dp(idx + 1, 'a') % m
            
        return sum(dp(1, i) for i in 'aeiou') % m
