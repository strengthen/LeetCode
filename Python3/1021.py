__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        count = 0
        res = ''
        v = 0
        for i in range(len(S)):
            if S[i] == '(':
                count += 1
            elif S[i] == ')':
                count -= 1
                if count == 0:
                    res += S[v + 1 : i]
                    v = i + 1
        return res
__________________________________________________________________________________________________
sample 13016 kb submission
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        
        outter = 0
        x = ''

        for i in S:
            if i == '(' and outter > 0:
                x += i
                outter += 1
            if i == ')' and outter > 1:
                x += i
                outter -= 1
            outter += 1 if i == '(' else -1


        return x
__________________________________________________________________________________________________
