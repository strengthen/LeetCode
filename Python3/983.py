__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        daysSet = set(days)
        durations = [1, 7, 30]
        res = [0] * (367)
        
        for i in range(max(daysSet),-1,-1):
            if i not in daysSet:
                res[i] = res[i+1]
            else:
                res[i] = res[i+1] + costs[0]
                for j in range(1,len(durations)):
                    if i + durations[j] <= 365:
                        res[i] = min(res[i], res[i+durations[j]] + costs[j])
        return res[0]
__________________________________________________________________________________________________
sample 13016 kb submission
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        day_set = set(days)
        dp = [0] * 366
        for i in range(366):
            if i not in day_set:
                dp[i] = dp[i-1]
            else:
                min_cost = min(dp[i-1] + costs[0], dp[max(i-7, 0)] + costs[1], dp[max(i-30, 0)] + costs[2])
                dp[i] = min_cost

        return dp[365]
__________________________________________________________________________________________________
