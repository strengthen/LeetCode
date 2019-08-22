__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        cnt=0
        ocnt=0
        oncnt=0
        
        for i in S:
            if i=='0':
                if oncnt==0:
                    continue                
                else:
                    cnt+=1                    
            else:
                oncnt+=1
            
            
            if cnt>oncnt:
                cnt=oncnt                
        
        return cnt
__________________________________________________________________________________________________
sample 13248 kb submission
class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        result = float('inf')
        
        leftone = S.count('1')
        rightzero = 0
        
        for i in range(len(S), -2, -1):
            flip = 0
            if i == len(S):
                flip = leftone
            elif i == -1:
                flip = rightzero
            else:
                if S[i] == '1':
                    leftone -= 1
                else:
                    rightzero += 1
                flip = leftone + rightzero
                
            if flip < result:
                result = flip
        
        return result
__________________________________________________________________________________________________
