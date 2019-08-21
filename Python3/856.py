__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        bal = ans = 0
        for i,x in enumerate(S):
            if x == '(':
                bal += 1
            else:
                bal -= 1
                if S[i-1] == '(':
                    ans += 1 << bal
        return ans
__________________________________________________________________________________________________
sample 12912 kb submission
class Solution:
    def scoreOfParentheses(self, S: str) -> int:
        
        # from solution
        ans = 0 
        bal = 0
        for i, c in enumerate(S):
            if c == "(": 
                bal += 1
            else: 
                bal -= 1
                if S[i-1] == '(':
                    ans += pow(2, bal)

        return ans
__________________________________________________________________________________________________
