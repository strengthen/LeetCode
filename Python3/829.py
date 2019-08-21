__________________________________________________________________________________________________
sample 56 ms submission
import collections
import itertools

def prime_factors(n):
    while n % 2 == 0:
        n //= 2
        yield 2
    
    p = 3
    while n >= p * p:
        while n % p == 0:
            n //= p
            yield p
        p += 2
    
    if n > 1:
        yield n
        

class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        while N % 2 == 0:
            N //= 2
        
        factors = collections.Counter(p for p in prime_factors(N))
        ret = 1
        for c in factors.values():
            ret *= c + 1
        return ret
__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        if N == 1: 
            return 1
        res = 1
        for i in range(2, int(N ** .5 + 1)):   
            if N % i == 0:
                if i % 2 == 1: # If i is odd, then we can form a sum of length i
                    res += 1
                j = (N // i) # Check the corresponding N // i
                if i != j and j % 2 == 1:
                    res += 1
        if N % 2 == 1: # If N is odd(2k + 1). Then N = k + k + 1, not included above
            res += 1
        
        return res
__________________________________________________________________________________________________
