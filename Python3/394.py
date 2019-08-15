__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        stack.append(["", 1])
        
        num = ''
        for ch in s:
            if ch.isdigit():
                num += ch
            elif ch == '[':
                stack.append(["", int(num)])
                num = ""         
            elif ch == ']':
                st, k = stack.pop()
                stack[-1][0] += st*k
            else:
                stack[-1][0] += ch
                
        return stack[0][0]
__________________________________________________________________________________________________
sample 12940 kb submission
class Solution(object):
    def decodeString(self, s):
        stack = []; curNum = 0; curString = ''
        for c in s:
            if c == '[':
                stack.append(curString)
                stack.append(curNum)
                curString = ''
                curNum = 0
            elif c == ']':
                num = stack.pop()
                prevString = stack.pop()
                curString = prevString + num*curString
            elif c.isdigit():
                curNum = curNum*10 + int(c)
            else:
                curString += c
        return curString
__________________________________________________________________________________________________
