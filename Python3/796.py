__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False
        if not len(A):
            return True
        
        A = A + A
        bset = set()
        bset.add(B)
        
        for i in range(0, (len(A) - len(B))):
            print(A[i:i+len(B)])
            if A[i:i+len(B)] in bset:
                return True
            
        return False
__________________________________________________________________________________________________
sample 12944 kb submission
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        return A == B or any(A[i:] + A[:i] == B for i in range(1, len(A)))
__________________________________________________________________________________________________
