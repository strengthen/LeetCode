__________________________________________________________________________________________________
sample 208 ms submission
from heapq import nlargest, heappop, heappush
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        if W >= max(Capital):
            return W + sum(nlargest(k, Profits))

        n = len(Profits)
        projects = [(Capital[i], Profits[i]) for i in range(n)]

        projects.sort(key=lambda x: -x[0])

        available = []
        while k > 0:
            while projects and projects[-1][0] <= W:
                heappush(available, -projects.pop()[1])

            if available:
                W -= heappop(available)
            else:
                break

            k -= 1

        return W
__________________________________________________________________________________________________
sample 232 ms submission
from heapq import nlargest
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        # to speed up: if all projects are available
        if W >= max(Capital):
            return W + sum(nlargest(k, Profits))
        
        n = len(Profits)
        for i in range(min(n, k)):
            idx = -1 
            # if there are available projects,
            # pick the most profitable one
            for j in range(n):
                if W >= Capital[j]:
                    if idx == -1: 
                        idx = j
                    elif Profits[idx] < Profits[j]: 
                        idx = j
                        
            # not enough capital to start any project
            if idx == -1:
                break
            
            # add the profit from chosen project
            # and remove the project from further consideration
            W += Profits[idx]
            Capital[idx] = float('inf')
            
        return  W
__________________________________________________________________________________________________
