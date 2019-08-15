__________________________________________________________________________________________________
sample 372 ms submission
class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        ans = []

        if not words:
            return ans

        rev = {s[::-1]: i for i, s in enumerate(words)}

        for i, s in enumerate(words):
            if s:
                for j in range(len(s)):
                    pre, suf = s[:j], s[j:]

                    if pre in rev and i != rev[pre] and suf == suf[::-1]:
                        ans.append([i, rev[pre]])

                    if suf in rev and i != rev[suf] and pre == pre[::-1]:
                        ans.append([rev[suf], i])
            else:
                for j, t in enumerate(words):
                    if i != j and t == t[::-1]:
                        ans.append([i, j])

        return ans
__________________________________________________________________________________________________
sample 14144 kb submission
class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        
        wordict = {}
        res = [] 
        for i in range(len(words)):
            wordict[words[i]] = i
            
        for i in range(len(words)):
            for j in range(len(words[i])+1):            
                tmp1 = words[i][:j]
                tmp2 = words[i][j:]
                if tmp1[::-1] in wordict and wordict[tmp1[::-1]]!=i and tmp2 == tmp2[::-1]:
                    res.append([i,wordict[tmp1[::-1]]])
                if j!=0 and tmp2[::-1] in wordict and wordict[tmp2[::-1]]!=i and tmp1 == tmp1[::-1]:
                    res.append([wordict[tmp2[::-1]],i])
                    
        return res
__________________________________________________________________________________________________
