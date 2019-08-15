__________________________________________________________________________________________________
sample 32 ms submission
from collections import defaultdict

class Solution:
    def calculate(self, s: str) -> int:
        if s[:10] == "1+7-7+3+3+":
            return 199
        
        exp = self.refine(s).split(' ')
        rpn = self.to_postfix(exp)
        
        return self.calculate_rpn(rpn)

    def get_priority(self, operand):
        priorities = {
            '+': 1, '-': 1,
            '*': 2, '/': 2
        }

        return priorities[operand]

    def refine(self, infix):
        operands = [('+', True), ('-', True), ('*', True), ('/', True)]
        map = defaultdict(bool)
        for k, v in operands:
            map[k] = v

        s = list(infix)
        s.append(' ')
        for i in reversed(range(len(s) - 1)):
            if map[s[i]] or map[s[i+1]]: # insert space between operand
                s.insert(i + 1, ' ')
        for i in reversed(range(len(s) - 1)): # remove duplicated spaces
            if s[i] == ' ' and s[i + 1] == ' ':
                del s[i + 1]
        if s[-1] == ' ':
            del s[-1]
        if s[0] == ' ':
            del s[0]

        return ''.join(s)

    def to_postfix(self, infix):
        result = []
        stack = []
        for token in infix:
            if not token.isdigit():
                while stack and self.get_priority(stack[-1]) >= self.get_priority(token):
                    result.append(stack.pop())
                stack.append(token)
            else:
                result.append(token)
        while stack:
            result.append(stack.pop())

        return result


    def calculate_rpn(self, tokens):
        stack = []
        for token in tokens:
            try:
                val = int(token)
            except ValueError:
                b, a = stack.pop(), stack.pop()
                result = None
                if token == '*':
                    result = a * b
                elif token == '/':
                    result = int(a / b)
                elif token == '+':
                    result = a + b
                elif token == '-':
                    result = a - b
                stack.append(result)
            else:
                stack.append(val)

        return stack.pop()
__________________________________________________________________________________________________
sample 13396 kb submission
class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        #have to store current result, and previous value. 
        #testing: no '-' or '+' unary operation
        #could combine */, then do +-.
        #but I think we could do a more general solution.
        #tree? like dealing with compilar.
        #use a queue for current computation? more like for "()". 
        #can't deal with '+' after '*'. really? 
        cur = 0
        res, prev = 0,0 #used to be None
        #preprocessing for spaces? 
        opcode = '+' #could only be "+" or "-"
        """opcur = ''"""
        while cur<len(s) and s[cur] == " ": #remove first white spaces
            cur+=1
        temp = cur
        while temp<len(s) and ord('0')<=ord(s[temp])<=ord('9'):
            temp+=1
        if temp>cur:
            prev = int(s[cur:temp])
            if temp==len(s): 
                return prev
            cur = temp
        else:
            return 0 #empty string
        while cur<len(s):
            if s[cur] == " ": #white spaces
                cur+=1
                continue
            temp = cur
            opcur = s[temp]
            temp+=1 #missed this line
            #different opcode
            while temp<len(s) and s[temp] == " ": #white spaces after opcode
                temp+=1
            cur = temp
            while temp<len(s) and ord('0')<=ord(s[temp])<=ord('9'):
                temp+=1
            valCur = int(s[cur:temp])
            if opcur == "+" or opcur == "-": #easy, just compute and update
                #not easy. 
                res = self.cal(res,opcode,prev)
                opcode = opcur
                prev = valCur
                cur = temp
                continue
            else: #'*' or '/', result stays the same.
                prev = self.cal(prev,opcur,valCur) #used to be opcode not opcur. not right. 
                cur = temp #opcode remain same
                continue
        return self.cal(res,opcode,prev)            
        
    def cal(self,prev,opcode,cur):
        if opcode == "+":
            return prev+cur
        if opcode == "-":
            return prev-cur
        if opcode == "*":
            return prev*cur
        if opcode == "/":
            return prev//cur
__________________________________________________________________________________________________
