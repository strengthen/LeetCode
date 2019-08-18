__________________________________________________________________________________________________
sample 80 ms submission
class Solution:
    def characterReplacement(self, s, k):
        from collections import defaultdict
        d = defaultdict(int)
        l = 0
        maxn = 0
        for r in range(len(s)):
            d[s[r]] += 1
            maxn = max(maxn, d[s[r]])
            if r - l + 1 > maxn + k:  # bc it is for loop, r += 1 is later than if clause
                d[s[l]] -= 1
                l += 1
        return len(s) - l
__________________________________________________________________________________________________
sample 13052 kb submission
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        chars = set(s)
        ans = 0
        
        for c in chars:    
            
            i = j = 0
            k1 = k
            
            while j < len(s):
            
                while j < len(s) and k1 >= 0:
                    if s[j] != c:
                        k1 -= 1
                    j += 1
                
                # print(s, c, i, j)
                ans = max(ans, j - i - (k1 < 0))

                while i < j and k1 < 0:
                    if s[i] != c:
                        k1 += 1
                    i += 1
                    
        return ans
__________________________________________________________________________________________________
