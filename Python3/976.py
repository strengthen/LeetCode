__________________________________________________________________________________________________
sample 212 ms submission
import heapq

class Solution:
    def largestPerimeter(self, lengths):
        heapq._heapify_max(lengths)
        b, c = map(heapq._heappop_max, [lengths] * 2)
        while lengths:
            a, b, c = b, c, heapq._heappop_max(lengths)
            if b + c > a:
                return a + b + c
        return 0
__________________________________________________________________________________________________
sample 13900 kb submission
import heapq
from collections import deque
class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        A = list(map(lambda x:-x,A))
        heapq.heapify(A)
        res = []
        for i in range(3):
            res.append(heapq.heappop(A))
        res = deque(res)
        while A and res[0]<=res[1]+res[2]:
            res.popleft()
            res.append(heapq.heappop(A))
            
        return -sum(res) if res[0]>res[1]+res[2] else 0
__________________________________________________________________________________________________
