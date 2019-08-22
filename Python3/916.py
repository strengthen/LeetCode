__________________________________________________________________________________________________
sample 528 ms submission
class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        ans=set(A)
        dns={}
        
        for i in B:
            for j in i:
                if j not in dns or i.count(j)>dns[j]:
                     dns[j]=i.count(j)
                   
        
        for i in A:
            for j in dns:
                if i.count(j)<dns[j]:   
                        ans.remove(i)
                        break
                
        return list(ans)            
__________________________________________________________________________________________________
sample 15968 kb submission
class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        
        def count(word):
            
            ans = [0]*26
            
            for ele in word:
                ans[ord(ele) - ord('a')]+=1
            return ans
        bmax = [0]*26
        for word in B:
            for i , ele in enumerate(count(word)):
                bmax[i] = max(bmax[i] , ele)
        
        res = []
        for words in A:
            flag = True
            for i , ele in enumerate(count(words)):
                if ele < bmax[i]:
                    flag = False
                    break
            if flag:
                res.append(words)
        
        return res
__________________________________________________________________________________________________
