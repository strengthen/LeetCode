__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        return len(set(zip(s, t))) == len(set(s)) == len(set(t))
__________________________________________________________________________________________________
sample 13100 kb submission
class Solution:
    def check(self, s, t):
        if len(s) != len(t):
            return False
        d = {}
        for i in range(len(s)):            
            if s[i] in d and d[s[i]] != t[i]:
                return False
            if s[i] not in d:
                d[s[i]] = t[i]
        return True
    def isIsomorphic(self, s: str, t: str) -> bool:
        return self.check(s, t) and self.check(t, s)
__________________________________________________________________________________________________
