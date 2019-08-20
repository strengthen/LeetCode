__________________________________________________________________________________________________
sample 608 ms submission
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        #   1  2  3  4 ... n
        #      2     4    ...  2 * n
        #         3     6  ....       3 * n 
        if m > n:
            m, n = n, m
        def enough(x):
            return sum([min(x//i, n) for i in range(1, m+1)]) >= k
        lo, hi = 1, m*n
        while lo < hi:
            mi = (lo+hi) // 2
            if not enough(mi):
                lo = mi + 1
            else:
                hi = mi
        return lo
__________________________________________________________________________________________________
sample 13168 kb submission
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        
        def enough(x):
            ans = 0 
            for i in range(1, m + 1):
                ans += min(n, x//i )
                if ans >= k:
                    return True
                
            return False
        
        
        low, hi = 1, n*m
        
        while low < hi:
            mid = (low + hi) >> 1
            if enough(mid) == False:
                low = mid + 1
            else:
                hi = mid
        
        return low        
__________________________________________________________________________________________________
