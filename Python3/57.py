__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        if not intervals:
            return [newInterval]
        
        ans = []
        st, et = newInterval
        new_start = -1
        for idx, (start_t, end_t) in enumerate(intervals):
            if st > end_t:
                ans.append(intervals[idx])
            elif st <= end_t:
                new_start = min(st, start_t)
                break
        
        if new_start == -1:
            return ans + [newInterval]
        
        new_end = -1
        for k in range(idx, len(intervals)):
            start_t, end_t = intervals[k]
            if et <= end_t:
                if et < start_t:
                    new_end = et
                elif et >= start_t:
                    new_end = end_t
                    k += 1
                break
                
        # if new_end == -1:
        #     new_end = et
        if new_end == -1:
            return ans + [[new_start, et]]
        
        return ans + [[new_start, new_end]] + intervals[k:]
__________________________________________________________________________________________________
sample 14636 kb submission
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        start, end = newInterval[0], newInterval[1]
        right = left = 0
        while right < len(intervals):
            if start <= intervals[right][1]:
                if end < intervals[right][0]: break
                start = min(start, intervals[right][0])	
                end = max(end, intervals[right][1])
            else: left += 1
            right += 1
        return intervals[:left] + [[start, end]] + intervals[right:]
        
__________________________________________________________________________________________________
