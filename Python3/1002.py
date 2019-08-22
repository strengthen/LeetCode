__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        
        if len(A)==0:
            return []
        
        common = set(A[0])
        
        for s in A[1:]:
            common &= set(s)
        
        ans = {}
        for s in A:
            for c in common:
                
                if c not in ans:
                    ans[c] = s.count(c)
                else:
                    ans[c] = min(ans[c], s.count(c))
        nans = []
        for c in ans:
            nans += [c]*ans[c]
            
        return nans
__________________________________________________________________________________________________
sample 13060 kb submission
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        ans=[]
        chars=set(A[0]) #create set of characters
        for char in chars:
            appears=[]
            for word in A:
                appears.append(word.count(char))
            n=min(appears)
            if n!=0:
                for i in range(n):
                    ans.append(char)
        return ans
__________________________________________________________________________________________________
