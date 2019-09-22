__________________________________________________________________________________________________
sample 36 ms submission
import functools, operator
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        # this is a binary search
        # 2 3 3
        # 2 3 4 6 8
        lo, hi = 1, 2 * 1000000000
        # factors = list({a, b, c})
        # factors.sort()
        # print(factors)
        a, b, c = sorted([a, b, c])
        
        def count(num):
            return num // a + num // b + num // c - num // (a * b // math.gcd(a, b)) - num // (a * c // math.gcd(a, c)) - num // (b * c // math.gcd(b, c)) + num // (a * b * c // (max( math.gcd(a, b) * math.gcd(b, c), math.gcd(a, c) * math.gcd(b, c), math.gcd(a, b) * math.gcd(a, c)) )  )
        
        while lo < hi:
            mid = (lo + hi) >> 1
            cnt = count(mid)
            if cnt < n:
                lo = mid + 1
            else:
                hi = mid
        return lo
        
__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        from math import gcd
        
        def count(num):
            return num // a + num // b + num // c - num // ab - num // ac - num // bc + num // abc
        
        ab, ac, bc = a * b // gcd(a, b), a * c // gcd(a, c), b * c // gcd(b, c)
        abc = ab * c // gcd(ab, c)
        lo, hi = 1, 2 * 10 ** 9
        while lo < hi:
            mi = (lo + hi) // 2
            if count(mi) >= n:
                hi = mi
            else:
                lo = mi + 1
        return lo
__________________________________________________________________________________________________
