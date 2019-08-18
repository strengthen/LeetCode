__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        removes = 0
        end = float("-inf")
        
        for i in sorted(intervals):
            if i[0] >= end:
                end = i[1]
            else:
                removes += 1 
                end = min(end, i[1])
                
        return removes
__________________________________________________________________________________________________
sample 14724 kb submission
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key=lambda x: x[0])
        prev = intervals[0]
        sol = 0
        for i in intervals[1:]:
            if i[0] < prev[1]:
                sol += 1
                prev[1] = min(i[1], prev[1])
            else:
                prev = i
        return sol
__________________________________________________________________________________________________
