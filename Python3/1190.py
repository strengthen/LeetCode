__________________________________________________________________________________________________
class Solution:
    def reverseParentheses(self, s: str) -> str:
        while '(' in s:
            posopen=s.rfind('(')
            posclose=s.find(')',posopen+1)
            s=s[:posopen]+s[posopen+1:posclose][::-1]+s[posclose+1:]
        return s
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def reverseParentheses(self, s: str) -> str:
        n, stack, i = len(s), [], 0
        while i < n:
            j = i + 1
            if s[i] == "(":
                stack.append(s[i])
            elif s[i] == ")":
                temp = []
                while stack[-1] != "(":
                    temp.append(stack.pop()[::-1])
                stack.pop()
                stack.append("".join(temp))
            else:
                while j < n and s[j] not in ["(", ")"]:
                    j += 1
                stack.append(s[i:j])
            i = j
        return "".join(stack)
__________________________________________________________________________________________________
