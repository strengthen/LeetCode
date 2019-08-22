__________________________________________________________________________________________________
sample 224 ms submission
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        return sorted([a*a for a in A])
__________________________________________________________________________________________________
sample 14496 kb submission
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        
        for i in range (0, len(A)):
            A[i] = A[i]*A[i]
            
        A.sort()
        return A
__________________________________________________________________________________________________
