__________________________________________________________________________________________________
sample 416 ms submission
class Solution:
    def threeEqualParts(self, A: List[int]) -> List[int]:
        n=len(A)
        l=[]
        for i in range(n):
            if A[i] == 1:
                l.append(i)
                
        if len(l) == 0:
            return [0,2]
        elif len(l) % 3 != 0:
            return [-1,-1]
        else:
            m=len(l)//3
            res=[A[l[0]:l[m-1]+1],A[l[m-1]+1:l[m]],A[l[m]:l[2*m-1]+1],A[l[2*m-1]+1:l[2*m]],A[l[2*m]:l[3*m-1]+1],A[l[3*m-1]+1:]]
            if res[0] == res[2] == res[4] and len(res[1]) >= len(res[5]) and len(res[3]) >= len(res[5]):
                i=l[m-1]+1+len(res[5])-1
                j=l[2*m-1]+1+len(res[5])
                return [i,j]
            else:
                return [-1,-1]
__________________________________________________________________________________________________
sample 416 ms submission
class Solution:
    def threeEqualParts(self, A: List[int]) -> List[int]:
        n=len(A)
        l=[]
        for i in range(n):
            if A[i] == 1:
                l.append(i)
                
        if len(l) == 0:
            return [0,2]
        elif len(l) % 3 != 0:
            return [-1,-1]
        else:
            m=len(l)//3
            res=[A[l[0]:l[m-1]+1],A[l[m-1]+1:l[m]],A[l[m]:l[2*m-1]+1],A[l[2*m-1]+1:l[2*m]],A[l[2*m]:l[3*m-1]+1],A[l[3*m-1]+1:]]
            if res[0] == res[2] == res[4] and len(res[1]) >= len(res[5]) and len(res[3]) >= len(res[5]):
                i=l[m-1]+1+len(res[5])-1
                j=l[2*m-1]+1+len(res[5])
                return [i,j]
            else:
                return [-1,-1]
__________________________________________________________________________________________________
