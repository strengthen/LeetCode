__________________________________________________________________________________________________
sample 88 ms submission
class Solution:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        n = len(A)
        swap, noswap = [n] * n, [n] * n
        swap[0], noswap[0] = 1, 0
        for i in range(1, len(A)):
            if A[i] > A[i-1] and B[i] > B[i-1] and A[i] > B[i-1] and B[i] > A[i-1]:
                noswap[i] = min(noswap[i-1], swap[i-1])
                swap[i] = min(noswap[i-1], swap[i-1]) + 1
            elif A[i] > A[i-1] and B[i] > B[i-1]:
                noswap[i] = noswap[i-1]
                swap[i] = swap[i-1] + 1
            elif A[i] > B[i-1] and B[i] > A[i-1]:
                noswap[i] = swap[i-1]
                swap[i] = noswap[i-1] + 1

        return min(swap[-1], noswap[-1])
__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        
        minSwap, minNotSwap= 1, 0
        for i in range(1, len(A)):
            swap, notSwap = len(A), len(A)
            
            if A[i] > B[i-1] and B[i] > A[i-1]:
                swap = 1 + minNotSwap
                notSwap = minSwap
            if A[i] > A[i-1] and B[i] > B[i-1]:
                swap = min(swap,1 + minSwap)
                notSwap = min(notSwap, minNotSwap)
            
            minSwap, minNotSwap = swap, notSwap
        
        return min(minSwap, minNotSwap)
__________________________________________________________________________________________________
