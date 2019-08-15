__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        d=1;
        preorder=preorder.split(',')
        for i in range(len(preorder)):
            if preorder[i]=='#':
                d-=1
            else:
                d+=1
                
            if d<0 or (d==0 and i!=len(preorder)-1):
                return False
        if d==0:
            return True
        return False
__________________________________________________________________________________________________
sample 13040 kb submission
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        
        need = 1
        for val in preorder.split(','):
            if not need:
                return False
            if val == '#':
                need -= 1
            else: 
                need +=1
        return not need
__________________________________________________________________________________________________
