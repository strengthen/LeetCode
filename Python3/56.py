__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sort_list = sorted(intervals)
        merged = []
        
        for i in sort_list:
            
            if not merged or merged[-1][1] < i[0]:
                merged.append(i)
            
            else:
                merged[-1][1] = max(merged[-1][1], i[1])
        return merged
__________________________________________________________________________________________________
sample 13856 kb submission
'''
Merge overlaping intervals:
Input: [[1,3],[2,6],[8,10],[15,18]]
                       
		[[1,6], [8,10], [15,18]]
		           ^     ^

	   [[1,3], [1,6]]
		        
Output: [[1,6],[8,10],[15,18]]

1) sort by start times:
	intervals.sort()

2) if overlap --> merge() and append res

	else --> append each interval

	p_first ++
 	p_second ++

 	s1 -------- e1
 	       s2 ----------e2
'''

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        intervals.sort()

        merged = []
        for interval in intervals:
            # if the list of merged intervals is empty or if the current
            # interval does not overlap with the previous, simply append it.
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
            # otherwise, there is overlap, so we merge the current and previous
            # intervals.
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged
__________________________________________________________________________________________________
