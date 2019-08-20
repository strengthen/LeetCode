__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def checkRecord(self, s: str) -> bool:
        s=s.replace('LLL','XX')
        return s.count('A')<=1 and s.count('XX') == 0 
__________________________________________________________________________________________________
sample 13116 kb submission
class Solution:
    def checkRecord(self, s: str) -> bool:
        hasA = False
        curL = 0
        for c in s:
            if c == 'A':
                if hasA:
                    return False
                hasA = True
                curL = 0
            elif c == 'L':
                curL += 1
                if curL > 2:
                    return False
            else:
                curL = 0
        return True
__________________________________________________________________________________________________
