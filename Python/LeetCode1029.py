__________________________________________________________________________________________________
36ms
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key = lambda x: x[0]-x[1])
        return sum(i[0] for i in costs[:len(costs)//2]) + sum(j[1] for j in costs[len(costs)//2:])
__________________________________________________________________________________________________
36ms
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key = lambda x:  x[0]-x[1])

        N = len(costs) // 2
        cost = 0
        for i in range(N):
            cost += costs[i][0]
        for i in range(N):
            cost += costs[N+i][1]
        return cost
__________________________________________________________________________________________________
52ms
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        N = len(costs) / 2
        nums = [(b - a, i) for i, (a, b) in enumerate(costs)]
        cnt = 0
        ans = 0
        for _, i in sorted(nums):
            if cnt < N:
                ans += costs[i][1]
            else:
                ans += costs[i][0]
            cnt += 1
        return ans
__________________________________________________________________________________________________

__________________________________________________________________________________________________

__________________________________________________________________________________________________