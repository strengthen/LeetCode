__________________________________________________________________________________________________
sample 72 ms submission
from collections import defaultdict
from heapq import heappush, heappop
class Solution:
    ## topological sort + Use Heap to pick up the smallest lexicographical city to visit next
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        tovisit = defaultdict(list)
        for t in tickets:
            h = tovisit[t[0]]
            heappush(h, t[1])
            
        res = []
        def dfs(from1, tovisit, res):
            while len(tovisit[from1]) != 0:
                to1 = heappop(tovisit[from1])
                dfs(to1, tovisit, res)
            res.append(from1)
                
        dfs("JFK", tovisit, res)
        return res[::-1]
__________________________________________________________________________________________________
sample 12972 kb submission
from collections import defaultdict
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        d=collections.defaultdict(list)
        for x,y in sorted(tickets):
            d[x].append(y)
        res,stack=[],['JFK']
        while stack:
            while d[stack[-1]]:
                stack.append(d[stack[-1]].pop(0))
            res.append(stack.pop())
        return res[::-1]
__________________________________________________________________________________________________
