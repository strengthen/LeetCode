__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def isValid(self, S: str) -> bool:
        if (len(S) % 3 != 0) or (S[0] != 'a') or (S[-1] != 'c'):
            return False
        stack = []
        S = S.replace('abc', '')
        for c in S:
            if c == 'c':
                if (len(stack) < 2) or (stack[-1] != 'b' or stack[-2] != 'a'):
                    return False
                else:
                    stack.pop()
                    stack.pop()
            else:
                stack.append(c)
        return len(stack) == 0
__________________________________________________________________________________________________
sample 13204 kb submission
class Solution:
    def isValid(self, S: str) -> bool:
        h = []
        def try_clean():
            if len(h)>=3 and h[-2]=='b' and h[-3]=='a':
                h.pop()
                h.pop()
                h.pop()
            
        for c in S:
            h.append(c)
            if h[-1]=='c':
                try_clean()
        return len(h)==0
__________________________________________________________________________________________________
