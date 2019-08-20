__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def optimalDivision(self, A: List[int]) -> str:
        
        if len(A) <= 2: return '/'.join(str(i) for i in A)
        return '{}/({})'.format(str(A[0]), '/'.join(str(i) for i in A[1:]))
__________________________________________________________________________________________________
sample 13124 kb submission
class Solution:
    def optimalDivision(self, A: List[int]) -> str:
        A = [str(a) for a in A]
        if len(A) <= 2: return '/'.join(A)
        return '{}/({})'.format(A[0], '/'.join(A[1:]))
__________________________________________________________________________________________________
