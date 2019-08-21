__________________________________________________________________________________________________
sample 164 ms submission
class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        def eat_all(K):
            return sum([(p - 1) // K + 1 for p in piles]) <= H 

        if H < len(piles):
            return -1
        elif H == len(piles):
            return max(piles)
        else:
            total = sum(piles)
            lo, hi = math.ceil(total / H), math.ceil((total) / (H - len(piles) + 1))
            while lo < hi:
                mid = (lo + hi) // 2
                if eat_all(mid):
                    hi = mid
                else:
                    lo = mid + 1
            return lo
__________________________________________________________________________________________________
sample 14116 kb submission
class Solution:
    def minEatingSpeed(self, piles, H):
        l, r = 1, max(piles)
        while l < r:
            m = (l + r) // 2
            if sum((p + m - 1) // m for p in piles) > H: l = m + 1
            else: r = m
        return l
__________________________________________________________________________________________________
