__________________________________________________________________________________________________
sample 64 ms submission
#
# @lc app=leetcode id=224 lang=python3
#
# [224] Basic Calculator


def my_calculate(expr: str) -> int:
    stack = []
    operand = result = 0
    sign = 1
    for ch in expr:
        if ch in "0123456789":
            operand = (operand * 10) + int(ch)
        elif ch in "+-":
            result = result + (sign * operand)
            operand = 0
            sign = 1 if ch == '+' else -1
        elif ch in '()':
            if ch == '(':
                stack.append(result)
                stack.append(sign)
                operand = result = 0
                sign = 1
            elif ch == ')':
                result = result + (sign * operand)
                result = (result * stack.pop()) + stack.pop()
                operand = 0
                sign=1
    return result + (sign * operand)


class Solution:
    def calculate(self, s: str) -> int:
        return my_calculate(expr=s)
__________________________________________________________________________________________________
sample 13152 kb submission
class Solution:
    def calculate(self, s: str) -> int:
        res = 0
        sign = 1
        num = 0
        stack = []
        
        for i in range(len(s)):
            if s[i].isdigit():
                num = num * 10 + int(s[i])
                
            if s[i] == "+" or s[i] == "-":
                res += num * sign 
                num = 0
                sign = 1 if s[i] == "+" else -1
                
            if s[i] == "(":
                stack.append(res)
                stack.append(sign)
                res = 0
                sign = 1
                
            if s[i] == ")":
                res += num * sign
                res *= stack.pop()
                res = res + stack.pop()
                num = 0
                sign = 1
                
        return res + num*sign
__________________________________________________________________________________________________
