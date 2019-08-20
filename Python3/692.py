__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        l1 = {}
        ans = []
        
        for w in words:
            if w in l1:
                l1[w] += 1
            else:
                l1[w] = 1
        
        l2 = {}
        
        for w in l1:
            if l1[w] in l2:
                l2[l1[w]].append(w)
            else:
                l2[l1[w]] = [w]
        
        for num in sorted(l2, reverse=True):
            for w in sorted(l2[num]):
                ans.append(w)
                if len(ans) == k:
                    return ans
        
        #return ans
__________________________________________________________________________________________________
sample 13004 kb submission
from collections import Counter
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        count = Counter(words)
        candidates = count.keys()
        return sorted(candidates, key = lambda w: (-count[w], w))[:k]
__________________________________________________________________________________________________
