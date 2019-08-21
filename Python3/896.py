__________________________________________________________________________________________________
sample 516 ms submission
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        
        return all(A[i] <= A[i+1] for i in range(len(A) - 1)) or all(A[i] >= A[i+1] for i in range(len(A) - 1))
__________________________________________________________________________________________________
sample 17172 kb submission
class Solution:
    def isMonotonic(self, A: 'List[int]') -> 'bool':
        hasInc, hasDec = False, False
        for i in range(len(A) - 1):
            if A[i] < A[i + 1]:
                hasInc = True
            elif A[i] > A[i + 1]:
                hasDec = True
            if hasInc and hasDec:
                return False
        return True            
__________________________________________________________________________________________________
