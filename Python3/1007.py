__________________________________________________________________________________________________
sample 1224 ms submission
class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        def check_num(num):
            for i in range(len(A)):
                if(A[i] != num and B[i] != num):
                    return False
            return True
        
        if(check_num(A[0])):
            common = A[0]
        elif(check_num(B[0])):
            common = B[0]
        else:
            return -1
        
        return len(A) - max(A.count(common), B.count(common))
__________________________________________________________________________________________________
sample 13876 kb submission
class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        from collections import defaultdict
        a=defaultdict(int)
        l=[]
        for cnt in range(len(A)):
            if A[cnt]==B[cnt]:
                a[A[cnt]]+=1
                if a[A[cnt]]==len(A):
                    l.append(A[cnt])
                    break
            else:
                a[A[cnt]]+=1
                a[B[cnt]]+=1
                #if a[A[cnt]]==len(A):
                #    l.append(A[cnt])
                #    break
                #if a[B[cnt]]==len(B):
                #    l.append(B[cnt])
                #    break
        #l=[]
        #print(a)
        for k,v in a.items():
            if v==len(A):
                l.append(k)
        if l==[]: return -1
        
        def turn_d(aa,l1):
            c=0
            for cnt in range(len(aa)):
                if aa[cnt]==l1:
                    c+=1
            return len(aa)-c
        
        return min(turn_d(A,l[0]),turn_d(B,l[0]))
__________________________________________________________________________________________________
