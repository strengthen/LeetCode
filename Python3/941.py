__________________________________________________________________________________________________
sample 216 ms submission
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A)<3:
            return False
        
        l=len(A)
        i,j=0,l-1
        while i<j and A[i]<A[i+1]:
            i+=1
        while j>0 and A[j]<A[j-1]:
            j-=1
        if i==j and j!=l-1 and i!=0:
            return True
        return False        
__________________________________________________________________________________________________
sample 13848 kb submission
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        
        N = len(A)
        i = 0

        # walk up
        while i+1 < N and A[i] < A[i+1]:
            i += 1

        # peak can't be first or last
        if i == 0 or i == N-1:
            return False

        # walk down
        while i+1 < N and A[i] > A[i+1]:
            i += 1

        return i == N-1
__________________________________________________________________________________________________
