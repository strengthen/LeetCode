__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        d= dict()
        al = []
        for i in range(len(S)):
            if S[i] in d:
                d[S[i]][1]= i
            else:
                al.append(S[i])
                d[S[i]]= [i,i]
                
        
        res = []
        m = d[al[0]][1]
      
        for i in range(len(al)-1):
            
            if d[al[i+1]][0] < m:
                if d[al[i+1]][1] > m:
                    m = d[al[i+1]][1] 
            else:
                res.append(m)
                m = d[al[i+1]][1]
        res.append(m) 
        start = 0
        final = []
        for i in res:
            final.extend([S[start:i+1]])
            start = i+1
        return [len(i) for i in final]
__________________________________________________________________________________________________
sample 12968 kb submission
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        if not S:
            return []
        charDictionary = collections.Counter(S)
        solution = []
        currentChars = set()
        currentString= ""
        for char in S:
            
            if not char in currentChars:
                currentChars.add(char)
                charDictionary[char] -= 1
                currentString += char
            elif char in charDictionary:
                charDictionary[char] -= 1
                currentString += char
            if charDictionary[char] == 0:
                del charDictionary[char]
                currentChars.remove(char)
                if len(currentChars) == 0:
                    solution.append(len(currentString))
                    currentString = ""
        
        return solution  
__________________________________________________________________________________________________
