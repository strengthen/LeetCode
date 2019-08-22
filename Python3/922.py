__________________________________________________________________________________________________
sample 224 ms submission
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        j = 1
        for i in range(0, len(A), 2):
            if A[i] % 2:
                while A[j] % 2:
                    j += 2
                A[i], A[j] = A[j], A[i]
        return A
__________________________________________________________________________________________________
sample 15192 kb submission
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:

    
        odd=[]
        even=[]

        for i in range(0,len(A)):
            if A[i]%2 == 0:
                even.append(A[i])
            else:
                odd.append(A[i])

        for i in range(0,len(A)-1,2):
            A[i]=even[int(i/2)]
            A[i+1]=odd[int(i/2)]

            
        return A 
__________________________________________________________________________________________________
