__________________________________________________________________________________________________
sample 20 ms submission
mod=((10**9)+7)
def factorial(n):
    ans=1
    for i in range(1,n+1):
        ans=(ans*i)%mod
    return ans
class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        arr=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,97]
        prime_nos=0
        for i in range(len(arr)):
            if arr[i]>n:
                break
            else:
                prime_nos+=1
        
        
        print(prime_nos)
        return (factorial(n-prime_nos)*factorial(prime_nos))%mod
__________________________________________________________________________________________________
sample 24 ms submission
import math

class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        if n <= 2:
            return 1
        prime_cnt = 1
        for m in range(3, n + 1):
            u = int(math.ceil(math.sqrt(m)))
            is_prime = True
            for f in range(2, u + 1):
                if m % f == 0:
                    is_prime = False
                    break
            if is_prime:
                prime_cnt += 1
        M = 10 ** 9 + 7
        r = 1
        p, np = prime_cnt, n - prime_cnt
        while p > 1:
            r *= p
            p -= 1
        r %= M
        while np > 1:
            r *= np
            np -= 1
        r %= M
        return r
__________________________________________________________________________________________________
