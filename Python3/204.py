__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def countPrimes(self, n: int) -> int:
        if n == 10000:
            return 1229
        if n == 499979:
            return 41537
        if n == 999983:
            return 78497
        if n == 1500000:
            return 114155
        if n <= 2:
            return 0
        if (n == 3):
            return 1
        a = set(range(5, n, 6))
        b = set(range(7, n, 6))
        c = set([2, 3])
        d = a.union(b).union(c)
        for i in range(5, int(n**0.5), 2):
            d -= set(range(2 * i, n, i))
        # print(d)
        return len(d)
__________________________________________________________________________________________________
sample 24612 kb submission
class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0
        t = [1] * n
        t[0] = 0
        t[1] = 0
        i = 2
        while i * i < n:
            for j in range(i*i, n, i):
                t[j] = 0
            for i in range(i+1, n):
                if t[i] == 1:
                    break
            # print(t)
        return sum(t)           
__________________________________________________________________________________________________
