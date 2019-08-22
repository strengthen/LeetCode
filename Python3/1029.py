__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        return sum([v[i // (len(costs)//2)] for i, v in enumerate(sorted(costs, key=lambda x: x[0] - x[1]))])
__________________________________________________________________________________________________
sample 13044 kb submission
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda x: (x[0]-x[1]))
        cost = 0
       # print(costs)
        N = int(len(costs)/2)
        for i in range(N):
            cost += (costs[i][0])
        for i in range(N, 2*N):
            cost += (costs[i][1])
        return cost
__________________________________________________________________________________________________
