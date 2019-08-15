__________________________________________________________________________________________________
sample 148 ms submission
from bisect import bisect_left, bisect_right, insort
class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        if(lower > upper):
            return 0
        prev_sums, curr_sum, res = [0], 0, 0
        for num in nums:
            curr_sum += num
            left, right = curr_sum - upper, curr_sum - lower
            l, r = bisect_left(prev_sums, left), bisect_right(prev_sums, right)
            insort(prev_sums, curr_sum)
            res += r - l
			
        return res        
__________________________________________________________________________________________________
sample 152 ms submission
class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        # lower <= thisSum - prevSum <= upper, which also becomes:
        # thisSum - upper <= prevSum <= thisSum - lower
        prefix = [0]
        currsum = 0
        res = 0
        for n in nums:
            currsum += n
            res += bisect.bisect_right(prefix, currsum - lower) - bisect.bisect_left(prefix, currsum - upper) 
            bisect.insort(prefix, currsum)
        return res
__________________________________________________________________________________________________
