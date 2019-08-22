__________________________________________________________________________________________________
sample 384 ms submission
class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        low = max(max(weights),sum(weights)//D)
        high = int(1.5 * low)
        while low <= high:
            threshold = (low + high) // 2
            days = cur_weight = 0
            for w in weights:
                cur_weight += w
                if cur_weight > threshold:
                    days += 1
                    cur_weight = w
            #print(threshold,days)
            if days < D:
                high = threshold - 1
            else:
                low = threshold + 1
        return low
__________________________________________________________________________________________________
sample 14820 kb submission
class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        m = max(weights)
        ub, lb = m*len(weights), m
        while ub - lb > 1:
            mid = (ub + lb) // 2
            if self.has_enough_capacity(weights, D, mid):
                ub = mid
            else:
                lb = mid
        return lb if self.has_enough_capacity(weights, D, lb) else ub


    def has_enough_capacity(self, weights: List[int], D: int, cap: int):
        rem = cap
        for w in weights:
            if rem < w:
                D -= 1
                if D < 1:
                    return False
                rem = cap - w
            else:
                rem -= w
        return True
__________________________________________________________________________________________________
