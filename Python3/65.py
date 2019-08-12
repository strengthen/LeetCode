__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            float(s)
            return True
        except:
            return False        
__________________________________________________________________________________________________
sample 13072 kb submission
class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            float(s.strip())
            return True
        except ValueError:
            return False
__________________________________________________________________________________________________
