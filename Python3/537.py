__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        A = [int(x) for x in a.replace('i','').split('+')]
        B = [int(x) for x in b.replace('i','').split('+')]
        return str(A[0]*B[0]-A[1]*B[1])+'+'+str(A[0]*B[1]+A[1]*B[0])+'i'
__________________________________________________________________________________________________
sample 13124 kb submission
class Solution:
    def getrc(self, strs):
        val = ''
        r, c = 0, 0
        positive = True
        for char in strs:
            if char == '-':
                positive = False
            elif char != '+' and char != 'i':
                val += char
            else:
                val = int(val)
                if not positive: val = -val
                if char == '+': r = val
                else: c = val
                val = ''
                positive = True
        return (r, c)
                
    def complexNumberMultiply(self, a: str, b: str) -> str:
        ra, ca = self.getrc(a)
        rb, cb = self.getrc(b)
        r = ra*rb-ca*cb
        c = ra*cb+rb*ca
        if r >= 0: r = str(r)
        else: r = '-' + str(-r)
        if c >= 0: c = str(c)
        else: c = '-' + str(-c)
        return r + '+' + c + 'i'
__________________________________________________________________________________________________
