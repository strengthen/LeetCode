__________________________________________________________________________________________________
sample 24 ms submission
class Solution:

    def isAnagram(self,s,t):

        if len(s) != len(t):

            return False

        for char in set(s):

            if s.count(char) != t.count(char):

                return False

        return True
__________________________________________________________________________________________________
sample 13092 kb submission
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        if len(s) != len(t):
            return False
        
        d = {}
        
        for ch in s:
            if ch in d:
                d[ch] +=1
            else:
                d[ch] = 1
        
        for ch in t:
            if ch not in d or d[ch] == 0:
                return False
            d[ch] -= 1
        
        if any(x != 0 for x in d.values()):
            return False
        return True
__________________________________________________________________________________________________
