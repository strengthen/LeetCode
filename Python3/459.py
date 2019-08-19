__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        
        return s in (s+s)[1:-1]        
__________________________________________________________________________________________________
sample 13168 kb submission
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        '''
        Check if a given non-empty string can be constructed by taking 
        a substring of it and appending multiple copies of the substring together.
        '''
        
        # 00. Special case
        l = len(s)
        if l in [0, 1]:
            return False
        
        # 01. Find all factors of len(s) that < len(s)
        slicePoints = []
        
        for i in range(1, l // 2 + 1):
            if not l % i:
                slicePoints.append(i)
        
        # 02. Use s[:i], where i is a factor of len(s), as
        #     a piece and find if it can construct s
        for i in slicePoints:
            if s[:i]*int(l/i) == s:
                return True
        return False
__________________________________________________________________________________________________
