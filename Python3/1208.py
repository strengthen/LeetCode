__________________________________________________________________________________________________
sample 88 ms submission
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        costs = [abs(ord(S) - ord(T)) for S, T in zip(s, t)]
        ans = 0
        tally = 0
        window = collections.deque()
        for cost in costs:
            tally += cost
            window.append(cost)
            while tally > maxCost:
                tally -= window.popleft()
            ans = max(ans, len(window))
        return ans
__________________________________________________________________________________________________
sample 104 ms submission
from collections import deque

class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        
        def distance(a, b):
            return abs(ord(a) - ord(b))
        
        changes = [distance(i, j) for i, j in zip(s, t)]
        
        s = 0
        d = deque()
        res = 0
        for i in changes:
            d.append(i)
            s += i
            while s > maxCost:
                s -= d.popleft()
            res = max(res, len(d))
        return res
__________________________________________________________________________________________________
sample 128 ms submission
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        cums = [0]
        ans = 0
        for S, T in zip(s, t):
            cost = abs(ord(S) - ord(T))
            cums.append(cums[-1] + cost)
            ans = max(ans, len(cums) - bisect.bisect_left(cums, cums[-1] - maxCost) - 1)
        return ans
    
