__________________________________________________________________________________________________
sample 172 ms submission
class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        re = 0
        intervals_sorted = sorted(intervals,key=lambda x:x[1])
        select_begin,select_end = -1,-1
        for interval in intervals_sorted:
            cur_begin = interval[0]
            cur_end = interval[1]
            if cur_begin > select_end:
                re += 2
                select_begin,select_end = cur_end-1,cur_end
            elif cur_begin > select_begin:
                re += 1
                if select_end==cur_end:
                    select_begin = cur_end-1
                else:
                    select_begin = select_end
                select_end = cur_end
        return re
__________________________________________________________________________________________________
sample 176 ms submission
class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        
        intervals.sort()
        out, last_start, one_end, two_end = 0, -1, float('Inf'), float('Inf')
        for a, b in intervals:
            if a == last_start: continue
            last_start = a
            
            if a >= two_end:
                out += 2
                if a > two_end: one_end, two_end = float('Inf'), b
                else: one_end, two_end = b, float('Inf')
            else:
                if a > one_end:
                    out += 1
                    one_end, two_end = two_end, float('Inf')
                if b < two_end: two_end = b

        if two_end != float('Inf'): return out + 2
        else: return out + int(one_end != float('Inf'))
__________________________________________________________________________________________________
