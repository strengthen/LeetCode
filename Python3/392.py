__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        
        for a in s:
            if a in t:
                l = t.index(a)
                t=t[l+1:]
            else:
                return False
            
        return True
__________________________________________________________________________________________________
sample 14980 kb submission
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        
        sIndex = 0
        tIndex = 0
        while tIndex < len(t):
            if sIndex == len(s):
                return True
            
            if s[sIndex] == t[tIndex]:
                sIndex += 1
                tIndex += 1
            else:
                tIndex += 1
                
        return sIndex == len(s)
__________________________________________________________________________________________________
