__________________________________________________________________________________________________
sample 28 ms submission
import math

class Solution:
  def preimageSizeFZF(self, K: int) -> int:
    def f(x):
      ans = 0
      while x:
        x = x // 5
        ans += x
      return ans

    l = 0
    r = 2 ** 63 - 1

    while l < r:
      m = l + (r - l) // 2
      if f(m) < K:
        l = m + 1
      else:
        r = m
        
    return 5 if f(l) == K else 0
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def preimageSizeFZF(self, K: int) -> int:
        # Note that a number x has at least x/5 trailing zeors.
        
        # Given x, find the smallest n such that n! has x trailing zeros 
        def bsearch(x):
            l = 0 # left bound of search space
            r = 5 * x # right bound of search space, since this number must have x zeros 
            while l < r:
                mid = l + (r - l) // 2
                if self.trailingZeros(mid) >= x:
                    r = mid
                else:
                    l = mid + 1
            return l if self.trailingZeros(l) == x else -1
        
        k_zeros = bsearch(K)
        if k_zeros == -1: return 0 # There is no number with k trailing zeros
        cur = K + 1 # It is possible that the there is no number with k + 1 0s, so find the next number with more 0s
        while True:
            cur_zeros = bsearch(cur)
            if cur_zeros == -1:
                cur += 1
            else:
                return cur_zeros - k_zeros
        
        
    # Given number n, count the number of trailing 0s in n!
    # This is Leetcode 172
    def trailingZeros(self, n):
        zeroCnt = 0
        while n > 0:
            n = n // 5
            zeroCnt += n
        return zeroCnt
__________________________________________________________________________________________________
