__________________________________________________________________________________________________
sample 368 ms submission
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        for i, n in enumerate(A):
            if abs(i-n) > 1: return False
        return True    
__________________________________________________________________________________________________
sample 13408 kb submission
class Solution:   
    def isIdealPermutation(self, A: List[int]) -> bool:
        min_expected = -1
        for i in range(len(A)):
            if i + 2 >= len(A):
                break
            min_expected = max(min_expected, A[i])
            if A[i+2] < min_expected:
                return False
        return True
__________________________________________________________________________________________________
