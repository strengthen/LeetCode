__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        cnt = 0
        m = 0
        for c in S:
            if c == '(':
                cnt += 1
            else:
                if cnt > 0:
                    cnt -= 1
                else:
                    m += 1
        return cnt + m
__________________________________________________________________________________________________
sample 12924 kb submission
class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        stack = []
        count = 0
        for c in S:
            if c == '(':
                stack.append(c)
            elif c == ')':
                if stack:
                    stack.pop()
                else:
                    count += 1
        return count + len(stack)        
__________________________________________________________________________________________________
