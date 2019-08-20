__________________________________________________________________________________________________
sample 48 ms submission
from functools import lru_cache

'''
T: O(N), where N is the length of cost
S: O(1)
'''
def minimum_cost(cost):
    f1 = f2 = 0
    for c in reversed(cost):
        f1, f2 = c + min(f1, f2), f1
    return min(f1, f2)

class Solution:
    @lru_cache(maxsize = 1024)
    def min_cost(self, i):
        if i >= len(self.c):
            return 0
        if i < 0:
            c = 0
        else:
            c = self.c[i]
        return c + min(self.min_cost(i + 1), self.min_cost(i + 2))

    def minCostClimbingStairs2(self, cost: List[int]) -> int:
        self.c = cost
        self.min_cost.cache_clear()
        return self.min_cost(-1)

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        return minimum_cost(cost)
__________________________________________________________________________________________________
sample 13096 kb submission
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        if len(cost) == 2: return 0
        for i in range(2, len(cost)):
            cost[i] = min(cost[i - 2], cost[i - 1]) + cost[i]
        return min(cost[len(cost) - 2], cost[len(cost) - 1])
__________________________________________________________________________________________________
