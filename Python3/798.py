__________________________________________________________________________________________________
sample 196 ms submission
# [4 1 3 2 0]
class Solution(object):
    def bestRotation(self, A):
        n = len(A)
        out = [1] * n

        for i in range(n):
            out[(i - A[i] + 1) % n] -= 1

        for i in range(1, n):
            out[i] += out[i-1]

        return out.index(max(out))
__________________________________________________________________________________________________
sample 14972 kb submission
class Solution:
    def bestRotation(self, A: List[int]) -> int:
        n = len(A)
        accu = [0] * (n+1)
        for i, a in enumerate(A):
            if a >= n:
                continue
                
            if i <= a:
                # a <= i+K <= n-1
                accu[a-i] += 1
                accu[n-i] -= 1
            else:
                # 
                accu[0] += 1
                accu[n-i] -= 1
                #  i + K >= n + a
                accu[n+a-i] += 1
                accu[n] -= 1
 
        realk = 0 # realk if left rotate, k is right rotate
        maxsums = 0
        sums = 0
        for k, a in enumerate(accu[:-1]):
            sums += a
            if sums > maxsums or (sums == maxsums and realk != 0):
                realk = (n - k ) % n
                maxsums = sums
     
        return realk
__________________________________________________________________________________________________
