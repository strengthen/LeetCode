__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if s.strip():          
            return len(s.split()[-1])
        return 0
        
__________________________________________________________________________________________________
sample 12944 kb submission
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        if "" == s:
            return 0
        return len(s.split()[-1])
__________________________________________________________________________________________________
