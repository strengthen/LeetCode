__________________________________________________________________________________________________
sample 40 ms submission
def binomial(n, k, cache={}):
    if k == 0: return 1
    if (n, k) not in cache:
        cache[n, k] = binomial(n-1, k-1) * n // k
    return cache[n, k]


class Solution:
    def countPrimeSetBits(self, L, R):
        return self.fast_count(R+1) - self.fast_count(L)
    
    def fast_count(self, N):
        S = bin(N)
        B = [len(S) + ~i for i, b in enumerate(S) if b == '1']
        res = 0
        for p in [2, 3, 5, 7, 11, 13, 17, 19]:
            if B[0] < p: break
            for i in range(min(p+1, len(B))):
                n = B[i]; k = p-i
                if n < k: break
                res += binomial(n, k)
        return res
__________________________________________________________________________________________________
sample 12928 kb submission
class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        num_prime_set = 0
        prime_numbers = [2, 3, 5, 7, 11, 13, 17, 19]
        for n in range(L, R+1):
            num_set_bit = 0
            while n > 0:

                num_set_bit += (n & 1)
                n = n >> 1
            if num_set_bit in prime_numbers:
                num_prime_set += 1
        return num_prime_set        
__________________________________________________________________________________________________
