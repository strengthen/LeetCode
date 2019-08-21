__________________________________________________________________________________________________
sample 32 ms submission
class Solution(object):
    def largeGroupPositions(self, S):
        # do itertools.groupby in python 
        ans = []
        
        i, j = 0, 0
        
        while j < len(S):
            if j == len(S) - 1 or S[j] != S[j+1]:
                if j - i + 1 >= 3:
                    ans.append([i, j])
                i = j + 1
            j += 1
        
        return ans
__________________________________________________________________________________________________
sample 13208 kb submission
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        result = []
        S = list(S)
        S.insert(0,0)
        S.append(0)
        for i in range(1,len(S)-1):
            if len(set(S[i:i+3])) == 1 and S[i-1] != S[i]:
                start = i-1
            if len(set(S[i-2:i+1])) == 1 and S[i+1] != S[i]:
                end = i-1
                result.append([start,end])
        return result                
__________________________________________________________________________________________________
