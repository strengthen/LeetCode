__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def solveEquation(self, equation: str) -> str:
        z = eval(equation.replace('x', 'j').replace('=', '-(') + ')', {'j': 1j})
        a, x = z.real, -z.imag
        return 'x=%d' % (a / x) if x else 'No solution' if a else 'Infinite solutions'
__________________________________________________________________________________________________
sample 13072 kb submission
class Solution:
    def solveEquation(self, equation: str) -> str:
        lcoe, lcons = 0, 0
        ccoe, ccons = 0, 0
        sign = 1
        val = None
        left = True
        for i in range(len(equation)):
            if equation[i] == '-': 
                if val != None:
                    if left: lcons += sign*val
                    else: ccons += sign*val
                sign = -1
                val = None
            elif equation[i] == '+':
                if val != None:
                    if left: lcons += sign*val
                    else: ccons += sign*val
                sign = 1
                val = None
            elif equation[i] == 'x':
                if val == None: val = 1
                if left: lcoe += sign*val
                else: ccoe += sign*val
                sign = 1
                val = None
            elif equation[i] == '=':
                if val != None: lcons += sign*val
                left = False
                sign = 1
                val = None
            else:
                if val == None: val = int(equation[i])
                else: val = 10*val + int(equation[i])
        if val != None: ccons += sign*val
        if lcoe != ccoe:
            val = (ccons-lcons)//(lcoe-ccoe)
            return 'x=' + str(val)
        elif lcons == ccons:
            return 'Infinite solutions'
        else: return 'No solution'                
__________________________________________________________________________________________________
