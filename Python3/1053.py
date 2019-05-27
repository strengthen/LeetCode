__________________________________________________________________________________________________
sample 140 ms submission
class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        i = len(A) - 2
        while i >= 0:
            if A[i] <= A[i + 1]:
                i -= 1
            else:
                break
        if i < 0:
            return A
        j = len(A) - 1
        while A[j] >= A[i]:
            j -= 1
        while A[j - 1] == A[j]:
            j -= 1
        A[i], A[j] = A[j], A[i]
        return A        
__________________________________________________________________________________________________
sample 144 ms submission
class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        n = len(A)
        for left in range(n-2, -1, -1):
            if A[left] > A[left+1]:
                break
        else:
            return A
        right = A.index(max(a for a in A[left+1:] if a < A[left]), left)
        A[left], A[right] = A[right], A[left]
        return A
__________________________________________________________________________________________________