__________________________________________________________________________________________________
sample 28 ms submission
from collections import Counter
import math

class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        if not set(B).issubset(set(A)):
                return -1

        base = math.ceil(len(B) / len(A))
        for i in range(2):
            if B in A*(base + i):
                return base + i
        return -1        
__________________________________________________________________________________________________
sample 13012 kb submission
class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        if not set(B).issubset(A): return -1
        n_repeat = (int(len(B)/len(A)))
        res = A*n_repeat
        for n in [0,1,2]:
            if (B in res): return (n+n_repeat)
            res += A
        return -1
__________________________________________________________________________________________________
