__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def largestSumAfterKNegations(self, A, K):

        A.sort()
        l = len(A)
        i = 0
        while i < l and A[i] < 0 and K > 0:
            A[i] = -A[i]
            K -= 1
            i += 1
        if K == 0:
            return sum(A)


        if i < l:
            if K % 2 :
                return sum(A) - 2*(min(A[i],A[i-1]))
            else:
                return sum(A)
        return sum(A)
__________________________________________________________________________________________________
sample 13056 kb submission
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        
        while K != 0:
            x = min(A)
            x_index = A.index(x)
            A[x_index] = x * -1
            K -= 1
        return sum(A)            
__________________________________________________________________________________________________
