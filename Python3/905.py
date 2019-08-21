__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        b = []
        c = []
        for i in A:
            if i%2 == 0:
                b.append(i)
            else:
                c.append(i)
        return (b+c)
        # B = (lambda x: x%2==1)
        # print (B)        
__________________________________________________________________________________________________
sample 13304 kb submission
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        oddnums = [];
        evennums = [];
        for i in range(0,len(A)):
            if(A[i]%2 ==0):
                evennums.append(A[i]);
            else:
                oddnums.append(A[i]);
        print(evennums,oddnums)
        return evennums+oddnums;
__________________________________________________________________________________________________
