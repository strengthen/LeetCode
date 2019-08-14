__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        repeats = []
        seen = set()
        for index in range(0, len(s)-9, 1):
            string = s[index:index+10]
            if string in seen:
                repeats.append(string)
            else:
                seen.add(string)
                
        return list(set(repeats))
        
__________________________________________________________________________________________________
sample 24904 kb submission
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        if not s or len(s)<10:
            return []
        res,lookup=set(),set()
        for i in range(10, len(s)+1):
            seq=s[i-10:i]
            if seq in lookup:
                res.add(seq)
            else:
                lookup.add(seq)
        return list(res)
__________________________________________________________________________________________________