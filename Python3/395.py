__________________________________________________________________________________________________
sample 28 ms submission
from collections import defaultdict,Counter
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        
            
            """
            :type s: str
            :type k: int
            :rtype: int
            """   
            if not s:
                return 0
            counter = Counter(s)
            for key,val in counter.items():
                if val < k:
                    s = s.replace(key,'-')
            if not '-' in s:
                return len(s)
            substr_set = set(s.split('-'))
            res = 0
            for substr in substr_set:
                res = max(res,self.longestSubstring(substr,k))
            return res
__________________________________________________________________________________________________
sample 12948 kb submission
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        """
        for each char, it is whether:
        1. not in the strs
        2. more than three times
        """
        ans = 0
        for n in range(1, 27):
            l = 0
            counter = {}
            # todo = 0
            for r in range(len(s)):
                if s[r] not in counter:
                    counter[s[r]] = 0
                counter[s[r]] += 1
                while len(counter) > n:
                    counter[s[l]] -= 1
                    if counter[s[l]] == 0:
                        counter.pop(s[l])
                    l += 1
                if all([v >= k for v in counter.values()]):
                    ans = max(ans, r - l + 1)
        return ans
__________________________________________________________________________________________________
