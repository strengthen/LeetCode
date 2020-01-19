__________________________________________________________________________________________________
sample 516 ms submission
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        profits = [ [jobs[0][1], jobs[0][2]] ]

        for s, e, p in jobs[1:]:
            profitCurrent = p
            for profit in reversed(profits):
                if s >= profit[0]:
                    profitCurrent += profit[1]
                    break
            if profits[-1][1] < profitCurrent:
                profits.append([e, profitCurrent])

        return profits[-1][1]
__________________________________________________________________________________________________
sample 524 ms submission
import bisect

class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        dp = [0]
        dp_profit = [0]
        for s, e, p in jobs:
            idx = bisect.bisect(dp, s) - 1
            if p + dp_profit[idx] > dp_profit[-1]:
                dp.append(e)
                dp_profit.append(p + dp_profit[idx])
        return dp_profit[-1]
__________________________________________________________________________________________________
