__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        
        cs = [-len(S)] + [i for i in range(len(S)) if S[i]==C] + [2*len(S)]
        
        idx = 0
        res = []
        
        for i in range(len(S)):
            val = min(i-cs[idx], cs[idx+1]-i)
            if val==0:
                idx+=1
            res.append(val)
            
        return res
__________________________________________________________________________________________________
sample 13028 kb submission
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        ePosition = []
         
        result = []
        length = len(S)
        counter = 0
        
        for i in range(length):
            if S[i] == C:
                ePosition.append(i)
                
        eCounts = len(ePosition)
        
        for i in range(length):

            if counter == eCounts:
                result.append(abs(ePosition[counter - 1] - i))

            else:
                left = abs(ePosition[counter- 1] - i)
                right = abs(ePosition[counter] - i)
                result.append(min(left, right))
                if i >= ePosition[counter]:
                    counter += 1
            
        
        return result
__________________________________________________________________________________________________
