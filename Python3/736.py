__________________________________________________________________________________________________
sample 36 ms submission
from contextlib import contextmanager

class Solution:
    def evaluate(self, expression: str) -> int:
        tokens = expression.replace('(', '( ').replace(')', ' )').split(' ')[::-1]
        scope = {}
        
        def expr():
            if tokens[-1] == '(':
                return s_expr()
            
            token = tokens.pop()
            if 'a' <= token[0] <= 'z':
                return scope[token]
            else:
                return int(token)
        
        def s_expr():
            tokens.pop()
            func = tokens.pop()
            
            if func == 'let':
                out = let()
            elif func == 'add':
                out = add()
            elif func == 'mult':
                out = mult()
            
            tokens.pop()
            return out
        
        @contextmanager
        def with_assignment(var: str, val: int):
            prev = scope.get(var)
            scope[var] = val
            yield
            scope[var] = prev
        
        def let():
            if tokens[-1] == '(' or tokens[-2] == ')':
                return expr()

            var = tokens.pop()
            val = expr()

            with with_assignment(var, val):
                return let()
            
        def add():
            e1 = expr()
            e2 = expr()
            return e1 + e2
        
        def mult():
            e1 = expr()
            e2 = expr()
            return e1 * e2
        
        return expr()
__________________________________________________________________________________________________
sample 13104 kb submission
class Solution:
    def evaluate(self, expression: str) -> int:

        def parse(s):

            w0 = ""
            stack = []
            
            while (s):
                if s[0] == "(":
                    s1, s = parse(s[1:])
                    stack += [s1]
                    w0=""
                    continue

                elif s[0] == " ":
                    if w0:  stack += [w0]
                    w0 =""

                elif s[0] == ")":
                    if w0:  stack += [w0]
                    s = s[1:]
                    #print("#2", [s], stack)
                    break

                else:
                    w0+=s[0]

                s = s[1:]     
            return  stack, s
        
        def eval_var(v, varr):
            #v is either variable or digit.
            #print("EVAL_VAR: v=", v, "varr=", varr)
            if type(v) == str:
                try:                    v = int(v)
                except ValueError:      v = int(varr[v])
            #v is expression
            else:
                v = eval(v, varr)
            return v
                    
                    
        def eval(e, varr):
            #print("EVAL(e):", e, "varr:", varr)
            if not e:   return 0
            elif type(e[0])==list: return eval(e[0], varr)

            opr = e.pop(0)
            if opr=="let":
                #ln_e = len(e)
                stack = []
                while len(e)>1:
                    #save older varrs in stack.
                    try:            stack.append([e[0], varr[e[0]]])
                    except:         None
                    
                    varr[e[0]] = eval_var(e[1], varr)
                    e = e[2:]
                ans = eval_var(e[0], varr)
                #print("EVAL(e):", debug_e, "varr=", varr, "ans:", ans)
                
                #restore varrs from stack, then delete stack
                for v,n in stack:   varr[v]=n
                del stack
                
            else:
                a = eval_var(e.pop(0), varr)
                b = eval_var(e.pop(0), varr)
                
                if      opr=="add":           ans = a+b
                elif    opr=="mult":          ans = a*b
                else:       
                    print("INVALID INPUT:", e)
                    raise ValueError

            return ans
        
        #parse input string.
        p, s1 = parse(expression)
        
        #eval the string
        ans = eval(p, {})
        
        #print(ans)
        return ans
__________________________________________________________________________________________________
