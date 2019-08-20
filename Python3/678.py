__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def checkValidString(self, s: str) -> bool:
        c_max = c_min = 0
        for char in s:
            c_max = c_max - 1 if char == ')' else c_max + 1
            c_min = c_min + 1 if char == '(' else max(c_min - 1, 0)
            """
            if char == '(':
                c_max += 1
                c_min += 1
            elif char == ')':
                c_max -= 1
                c_min = max(c_min - 1, 0)
            else:
                c_max += 1
                c_min = max(c_min - 1, 0)
            """
            
            if c_max < 0:
                return False
        
        return (c_min == 0)
__________________________________________________________________________________________________
sample 13028 kb submission
class Solution:
    def checkValidString(self, s: str) -> bool:
        lo,hi=0,0
        for c in s:
            lo += 1 if c=='(' else -1 # treat '*' as ')'
            hi += 1 if c!=')' else -1 # treat '*' as '('
            lo = max(lo, 0)  # treat '*' as empty
            if hi<0: return False # ')' more than '*'+'('
        return lo==0 # detect if more '(' than '*'
__________________________________________________________________________________________________
