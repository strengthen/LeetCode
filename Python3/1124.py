__________________________________________________________________________________________________
class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        hours = [1 if h > 8 else -1 for h in hours]
        s = 0
        ans = 0
        memo = {0 : -1}
        for i, v in enumerate(hours):
            s += v
            if s > 0:
                ans = i + 1
            if s not in memo:
                memo[s] = i
            if (s - 1) in memo:
                ans = max(ans, i - memo[s - 1])
        return ans
                
__________________________________________________________________________________________________

__________________________________________________________________________________________________
