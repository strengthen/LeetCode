__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        d = {}
        for word in words:
            n = len(word)
            if n in d:
                d[n].add(word)
            else:
                d[n]  = set([word])
        keys = list(d.keys())
        keys.sort()
        n = len(keys)
        res = 0
        for i in range(n-1, -1, -1):
            if i == n-1:
                s = d[keys[i]]
                L = len(d[keys[i]])
                res += L * keys[i] + L
            else:  
                s = set([item[-keys[i]:] for item in s])
                L1 = len(s)
                s = s | d[keys[i]]
                L3 = len(s)
                res += (L3 - L1) * keys[i] + (L3 - L1)
        return res        
__________________________________________________________________________________________________
sample 15540 kb submission
from functools import reduce
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        T = lambda: collections.defaultdict(T)
        root = T()
        end = []
        for w in set(words):
            end.append(reduce(lambda x,y: x[y], w[::-1], root) )
            end[-1]['#'] = len(w)+1
        
        return sum(w['#'] for w in end if len(w)==1)
__________________________________________________________________________________________________
