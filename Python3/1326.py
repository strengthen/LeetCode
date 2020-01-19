__________________________________________________________________________________________________
sample 144 ms submission
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        pool, ans, cur, new = sorted([max(0, i - r), min(n, i + r)] for i, r in enumerate(ranges)), 0, 0, 0
        for i, j in pool:
            if i > cur:
                if new < i:
                    return -1
                cur, new = new, j
                ans += 1
            else:
                new = max(new, j)
            if new == n:
                return ans if cur == n else ans + 1
        return -1
__________________________________________________________________________________________________
sample 148 ms submission
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        pool, ans, cur, new = sorted([max(0, i - r), min(n, i + r)] for i, r in enumerate(ranges)), 0, 0, 0
        for i, j in pool:
            if i > cur:
                if new < i:
                    return -1
                cur, new = new, j
                ans += 1
            else:
                new = max(new, j)
            if new == n:
                return ans + 1
        return -1
__________________________________________________________________________________________________
