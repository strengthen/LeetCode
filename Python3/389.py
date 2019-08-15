__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        import collections
        c_s = collections.Counter(s)
        c_t = collections.Counter(t)
        
        key_s = set(c_s.keys())
        key_t = set(c_t.keys())
        
        if len(key_t-key_s):
            return list(key_t-key_s)[0]
        
        else:
            for ks in key_s:
                if c_s[ks] != c_t[ks]:
                    return ks
__________________________________________________________________________________________________
sample 12960 kb submission
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        code = 0
        for ch in s+t:
            code ^= ord(ch)
        return chr(code)        
__________________________________________________________________________________________________
