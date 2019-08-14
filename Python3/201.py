__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        bit_move = 0
        while m != n:
            m >>= 1
            n >>= 1
            bit_move += 1
        return n << bit_move
__________________________________________________________________________________________________
sample 52 ms submission
class Solution:
    def rangeBitwiseAnd1(self, m: int, n: int) -> int:
        res = m
        for i in range(m+1, n+1):
            res &= i
            if res == 0:
                return 0
        return res
    
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        if m == n:
            return m
        if m == 0 and n == 1:
            return 0
        mc, nc = bin(m), bin(n)
        ml, nl = len(mc), len(nc)
        if nl > ml:
            return 0
        else:
            return self.rangeBitwiseAnd(m-(1<<(ml-3)), n-(1<<(nl-3)))+(1<<(ml-3))
__________________________________________________________________________________________________
