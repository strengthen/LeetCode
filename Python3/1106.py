__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        for i in range(len(expression)):
            open_parens = 0
            if expression[i] == 'f':
                return False
            elif expression[i] == 't':
                return True
            elif expression[i] == '!':
                return not self.parseBoolExpr(expression[i+2:len(expression)-1])
            elif expression[i] == '&':
                start = i + 2
                for j in range(i+2,len(expression)):
                    if expression[j] == ')' and open_parens == 0:
                        return self.parseBoolExpr(expression[start:j])
                    elif expression[j] == ',' and open_parens == 0:
                        if not self.parseBoolExpr(expression[start:j]):
                            return False
                        start = j + 1
                    elif expression[j] == '(':
                        open_parens += 1
                    elif expression[j] == ')':
                        open_parens -= 1
            elif expression[i] == '|':
                start = i + 2
                for j in range(i+2,len(expression)):
                    if expression[j] == ')' and open_parens == 0:
                        return self.parseBoolExpr(expression[start:j])
                    elif expression[j] == ',' and open_parens == 0:
                        if self.parseBoolExpr(expression[start:j]):
                            return True
                        start = j + 1
                    elif expression[j] == '(':
                        open_parens += 1
                    elif expression[j] == ')':
                        open_parens -= 1
__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def parseBoolExpr(self, expression):
        if len(expression)==1:
            if expression[0]=='t':
                return True
            else:
                return False
        if expression[0]=='!':
            return not self.parseBoolExpr(expression[2:-1])

        elif expression[0]=='|':
            level = 0
            start = 0
            for i,exp in enumerate(expression[2:-1]):
                if level==0 and exp in ['t','f']:
                    if self.parseBoolExpr(expression[i+2]):
                        return True
                if exp=='(':
                    if level==0:
                        start = i + 1
                    level+=1

                elif exp==')':
                    level-=1
                    if level==0:
                        if self.parseBoolExpr(expression[start:i+3]):
                            return True
            return False
        else:
            level = 0
            start = 0
            for i, exp in enumerate(expression[2:-1]):
                if level==0 and exp in ['t','f']:
                    if not self.parseBoolExpr(expression[i+2]):
                        return False
                if exp == '(':
                    if level==0:
                        start = i + 1
                    level += 1

                elif exp == ')':
                    level -= 1
                    if level==0:
                        if not self.parseBoolExpr(expression[start:i + 3]):
                            return False
            return True


if __name__=="__main__":
    solution = Solution()
    print(solution.parseBoolExpr("|(&(!(f),t,f),&(t,t))"))
__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        
        def helper(s):
            #print(s)
            if len(s) == 1:
                if s == "t":
                    return True
                else:
                    return False
            elif s[0] == "!":
                return not helper(s[2:len(s)-1])
            elif s[0] == "&":
                ss = s[2:len(s)-1]
                p = 0
                exp = ""
                for i,c in enumerate(ss):
                    if c == "(":
                        p+=1
                    elif c== ")":
                        p-=1
                    if c == "," and p == 0:
                        if helper(exp):
                            exp = ""
                            continue
                        else:
                            return False
                    else:
                        exp += c
                if not helper(exp):
                    return False
                return True
            elif s[0] == "|":
                ss = s[2:len(s)-1]
                #print(ss)
                p = 0
                exp = ""
                for i,c in enumerate(ss):
                    if c == "(":
                        p+=1
                    elif c== ")":
                        p-=1
                    if c == ","  and p == 0:
                        if helper(exp):
                            return True
                            
                        else:
                            exp = ""
                            continue
                    else:
                        exp += c
                if helper(exp):
                    return True
                return False

        return helper(expression)