__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        A = A + ' ' + B
        words = A.split()
        table = {word: 0 for word in words}
        res = []
        
        for word in words:
            if table[word] is 0:
                table[word] = 1
            else:
                table[word] += 1
        
        for k,v in table.items():
            if v == 1:
                res.append(k)
                
        return res
__________________________________________________________________________________________________
sample 12948 kb submission
from collections import defaultdict

class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        freq1, freq2 = defaultdict(int), defaultdict(int)
        for w in A.split(' '):
            freq1[w] += 1
        for w in B.split(' '):
            freq2[w] += 1
        res = []
        for key in freq1:
            if key not in freq2 and freq1[key] == 1:
                res.append(key)
        for key in freq2:
            if key not in freq1 and freq2[key] == 1:
                res.append(key)
        return res
__________________________________________________________________________________________________
