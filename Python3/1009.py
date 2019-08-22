__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        e = bin(N)
        res = '0b'
        for s in e[2:]:
            if s == '1':
                res += '0'
            else:
                res += '1'
        return int(res,2)
__________________________________________________________________________________________________
sample 13032 kb submission
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        c = 1
        while c < N: # Construct Mask
            c = (c << 1) + 1
        return N ^ c
__________________________________________________________________________________________________
