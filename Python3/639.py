__________________________________________________________________________________________________
sample 216 ms submission
class Solution:
    d3_9 = set(("3","4","5","6","7","8","9"))
    d = set(("0","1","2","3","4","5","6","7","8","9"))
    d0_6 = set(("0","1","2","3","4","5","6"))
    modulus = (10**9+7)
    from functools import reduce
    def numDecodingsHidden(self, s: str) -> int:
        prevchar = None
        oneago = 1
        twoago = 1
        for newchar in reversed(s):
            result = 0
            if prevchar is None:
                if newchar == "*":
                    result = 9
                elif newchar == "0":
                    result = 0
                elif newchar in self.d:
                    result = 1
            else:
                if newchar in self.d3_9:
                    if prevchar == "0":
                        result = 0
                    else:
                        result = oneago
                elif newchar == "1":
                    if prevchar in self.d:
                        result = (oneago+twoago)% self.modulus
                    elif prevchar == "*":
                        result = (oneago + 9*twoago)%self.modulus
                elif newchar == "2":
                    if prevchar in self.d0_6:
                        result = (oneago+twoago)%self.modulus
                    elif prevchar == "*":
                        result = (oneago+6*twoago)%self.modulus
                    else:
                        result = oneago
                elif newchar == "*":
                    if prevchar in self.d0_6:
                        result = (9*oneago+2*twoago)%self.modulus
                    elif prevchar == "*":
                        result = (9*oneago+15*twoago)%self.modulus
                    else:
                        result = (9*oneago+twoago)%self.modulus
            prevchar = newchar
            twoago = oneago
            oneago = result      
        return oneago
    def numDecodings(self, s: str) -> int:
        return self.numDecodingsHidden(s)
__________________________________________________________________________________________________
sample 13544 kb submission
class Solution:
    def numDecodings(self, S: str) -> int:
        MOD = 10**9 + 7
        e0, e1, e2 = 1, 0, 0
        for c in S:
            if c == '*':
                f0 = 9*e0 + 9*e1 + 6*e2
                f1 = e0
                f2 = e0
            else:
                f0 = (c > '0') * e0 + e1 + (c <= '6') * e2
                f1 = (c == '1') * e0
                f2 = (c == '2') * e0
            e0, e1, e2 = f0 % MOD, f1, f2
        return e0
__________________________________________________________________________________________________
