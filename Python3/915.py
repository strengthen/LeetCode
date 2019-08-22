__________________________________________________________________________________________________
sample 192 ms submission
class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        ultramax=currmax=A[0]
        n,currlen=len(A),1
        for i in range(1,n):
            if A[i] < currmax:
                currmax,currlen=ultramax,i+1
            elif A[i] > ultramax:
                ultramax=A[i]
        return currlen
__________________________________________________________________________________________________
sample 15908 kb submission
class Solution:
    def partitionDisjoint(self, A: List[int]) -> int:
        max_cur = A[0]
        res = 0
        max_to_i = A[0]
        for i in range(1,len(A)):
            max_to_i = max(max_to_i,A[i])
            if A[i] < max_cur:
                res = i
                max_cur = max_to_i
        return res+1
__________________________________________________________________________________________________
