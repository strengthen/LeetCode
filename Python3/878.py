__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        
        mod = int(1e9+7)
        from math import gcd
        
        a, b = (A, B) if A<B else (B,A)
        lcm = a * b // gcd(a,b)
        
        lo, hi = a, b*N
        while lo < hi:
            mi = lo + (hi-lo)//2
            cnt = mi//a + mi//b - mi//lcm
            
            if cnt < N:
                lo = mi + 1
            else:
                hi = mi
        return lo % mod
__________________________________________________________________________________________________
sample 13156 kb submission
class Solution:
    def nthMagicalNumber(self, N: 'int', A: 'int', B: 'int') -> 'int':
        smaller = min(A, B)
        left, right = smaller, smaller * N

        while (left <= right):
            mid = left + (right - left) // 2
            count = self.countMagical(mid, A, B)

            if count == N:
                return int(max(mid // A * A, mid // B * B)) % int(10 ** 9 + 7)
            elif count > N:
                right = mid - 1
            else:
                left = mid + 1

        return -1

    def countMagical(self, X, A, B):
        return X // A + X // B - X // self.minCommonTimes(A, B)

    def minCommonTimes(self, A, B):
        smaller = min(A, B)
        bigger = max(A, B)
        while (smaller):
            left = bigger % smaller
            bigger = smaller
            smaller = left

        return A // bigger * B
__________________________________________________________________________________________________
