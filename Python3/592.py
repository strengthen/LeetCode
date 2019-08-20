__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def fractionAddition(self, expression: str) -> str:
        def toInt(x):
            x = x.split('/')
            
            return [int(x[0]), int(x[1])]
        
        exp = expression.replace('-', '+-')
        
        exp = [x for x in exp.split('+') if x]
        exp = list(map(lambda x: toInt(x), exp))
        
        while len(exp) > 1:
            num1, den1 = exp.pop(0)
            num2, den2 = exp.pop(0)
            
            lcm = den1 * den2 // math.gcd(den1, den2)
            
            num1 *= lcm // den1
            num2 *= lcm // den2
            
            exp.append([num1 + num2, lcm])
            
            
        num, den = exp[0]
        
        if num == 0:
            return '0/1'
        else:
            gcd = math.gcd(num, den)
            return '{}/{}'.format(num//gcd, den//gcd)
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def fractionAddition(self, expression):
        ints = map(int, re.findall('[+-]?\d+', expression))
        A, B = 0, 1
        for a in ints:
            b = next(ints)
            A = A * b + a * B
            B *= b
            g = math.gcd(A, B)
            A //= g
            B //= g
        return '%d/%d' % (A, B)
__________________________________________________________________________________________________
