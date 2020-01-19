__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals: return 0
        intervals.sort()
        L, R = intervals[0]
        for i in range(1, remaining := len(intervals)):
            l, r = intervals[i]
            if L <= l and R >= r: remaining -= 1
            else: L, R = l, r
        return remaining
__________________________________________________________________________________________________
sample 88 ms submission
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        remain_lst = []
        cur_left, cur_right = intervals[0]
        count = 1
        for interval in intervals:
            if cur_left == interval[0]:
                cur_right = interval[1]
            else:
                if cur_right >= interval[1]:
                    continue
                else:
                    cur_left, cur_right = interval
                    count += 1
                    
        return count
__________________________________________________________________________________________________
