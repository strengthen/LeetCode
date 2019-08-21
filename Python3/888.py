__________________________________________________________________________________________________
sample 396 ms submission
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        x, y = sum(A), sum(B)
        z = (x + y) // 2
        
        B = set(B)
        for a in A:
            b = a + z - x
            if b in B:
                return [a, b]
__________________________________________________________________________________________________
sample 14536 kb submission
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        sumA = sum(A)
        sumB = sum(B)
        d = abs(sumA-sumB)
        
        lenA = len(A)
        lenB = len(B)
        i = j = 0
        
        A.sort()
        B.sort()
        
        while i < lenA and j < lenB:
            if sumA < sumB:
                if B[j]-A[i]==d/2:
                    return [A[i], B[j]]
                elif B[j]-A[i] > d/2:
                    i+=1
                else:
                    j+=1
            else:
                if A[i]-B[j]==d/2:
                    return [A[i], B[j]]
                elif A[i]-B[j] > d/2:
                    j+=1
                else:
                    i+=1
__________________________________________________________________________________________________
