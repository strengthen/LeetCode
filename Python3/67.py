__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a,2) + int(b,2))[2:]
__________________________________________________________________________________________________
sample 12972 kb submission
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans = ""
        carrier = 0
        
        if len(a) > len(b): 
            a,b = b,a
        if not a :
            return b
        for i in range(1,len(a)+1):
            s = int(a[-i]) + int(b[-i]) + carrier
            if s > 1:                
                carrier = 1
                s = 0 if s == 2 else 1
            else:
                carrier = 0
            ans = str(s) + ans
        
            
        for j in range(len(a)+1,len(b)+1):
            s = int(b[-j]) + carrier
            if s > 1:
                carrier = 1
                s = 0
            else:
                carrier = 0
            ans = str(s) + ans
        if carrier > 0:
            ans = '1' + ans
        return ans       
__________________________________________________________________________________________________
