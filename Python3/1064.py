__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        for i, n in enumerate(A):
            if i == n:
                return i
        return -1        
__________________________________________________________________________________________________
class Solution:
    def fixedPoint(self, A: List[int]) -> int:
        s,e = 0, len(A)-1
        while s < e:
            mid = (s+e)//2
            if A[mid]-mid<0: s += 1
            elif A[mid]-mid>0: e -= 1
            else: return mid
        return -1
__________________________________________________________________________________________________
