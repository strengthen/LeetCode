__________________________________________________________________________________________________
sample 180 ms submission
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        nums.sort()
        lo, hi = 1, 10**6
        while lo < hi:
            m = lo + (hi - lo) // 2
            s = self.cal_sum(nums, m)
            if s > threshold:
                lo = m + 1
            else:
                hi = m
        return lo
    
    def cal_sum(self, nums, div):
        x = 1
        i = 0
        s = 0
        while True:
            j = bisect.bisect_right(nums, x * div)
            s += (j - i) * x
            i = j
            x += 1
            if j == len(nums):
                break
        return s
__________________________________________________________________________________________________
sample 184 ms submission
import functools
import math
import bisect


class Solution:
    def cal_sum(self, nums, div):
        x = 1
        i = 0
        s = 0
        while True:
            j = bisect.bisect_right(nums, x * div)
            s += (j - i) * x
            i = j
            x += 1
            if j == len(nums):
                break
        return s

    def smallestDivisor(self, ns, t):
        ns.sort()
        lo, hi = 1, 1e6
        while lo < hi:
            mi = (lo + hi) // 2
            if self.cal_sum(ns, mi) <= t:
                hi = mi
            else:
                lo = mi + 1
        return int(lo)
__________________________________________________________________________________________________
