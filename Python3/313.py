__________________________________________________________________________________________________
sample 140 ms submission
from heapq import heappush, heappop
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        if n == 1:
            return 1
        
        ret = [1] * n
        idx = [0] * n
        prime_idx = [0] * len(primes)
        q = list()
        
        for i, num in enumerate(primes):
            heappush(q, (num, i))

        for index in range(1, n):
            top, k = heappop(q)
            ret[index] = top
            idx[index] = k    # ???
            prime_idx[k] += 1
            while idx[prime_idx[k]] > k:
                prime_idx[k] += 1
            heappush(q, (primes[k]*ret[prime_idx[k]], k))
        
        return ret[-1]
__________________________________________________________________________________________________
sample 22552 kb submission
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        if n == 1:
            return 1
        result = [1]
        pointers = [0]*len(primes)
        added = set()
        initial = float("inf")
        while len(result) < n:
            next_candidate = initial
            added_index = 0
            for i in range(len(pointers)):
                possible = primes[i]*result[pointers[i]]
                while possible in added:
                    pointers[i] += 1
                    possible = primes[i]*result[pointers[i]]
                if possible < next_candidate and possible not in added:
                    next_candidate = possible
                    added_index = i
                

            pointers[added_index] += 1
            added.add(next_candidate) 
            result.append(next_candidate)    
        return result[-1]
__________________________________________________________________________________________________
