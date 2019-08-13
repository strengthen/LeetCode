__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        lams = {
            "+": lambda a,b: a+b,
            "-": lambda a,b: a-b,
            "*": lambda a,b: a*b,
            "/": lambda a,b: int(a/b),
        }
        for k in tokens:
            if k in lams:
                b = stack.pop()
                a = stack.pop()
                n = lams[k](a,b)
                stack.append(n)
            else:
                n = int(k)
                stack.append(n)
        return stack.pop()
__________________________________________________________________________________________________
sample 13048 kb submission
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        result = 0
        if len(tokens) == 1: 
            return int(tokens[0]) 
        for token in tokens:
            stack.append(token)
            if(stack and token in ['+', '-', '*', '/']):
                stack.pop()
                if token == '+':
                    result = int(stack.pop()) + int(stack.pop())
                if token == '-':
                    a = int(stack.pop())
                    b = int(stack.pop())
                    result = b - a
                if token == '*':
                    result = int(stack.pop()) * int(stack.pop())
                if token == '/':
                    a = int(stack.pop())
                    b = int(stack.pop())
                    result = int(operator.truediv(b, a))
                stack.append(result)
        return result
__________________________________________________________________________________________________
