__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def longestPalindrome(self, s: str) -> int:
        
        counter = {}
        for c in s:
            if c in counter:
                counter[c] += 1
            else:
                counter[c] = 1
        
        has_isolated = False
        
        l = 0
        for _, v in counter.items():
            if v % 2 == 1:
                has_isolated = True
                l += v - 1
            else:
                l += v
                
        if has_isolated:
            l += 1
        return l
__________________________________________________________________________________________________
sample 13004 kb submission
from collections import defaultdict

class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = defaultdict(int)
        for c in s:
            d[c] += 1
            
        count = 0
        for v in d.values():
            n = v // 2 * 2
            count += n
            
        if len(s) > count:
            count += 1
            
        return count
__________________________________________________________________________________________________
