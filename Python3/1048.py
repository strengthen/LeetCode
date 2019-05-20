__________________________________________________________________________________________________
sample 56 ms submission
from functools import lru_cache
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        lookup = collections.defaultdict(set)
        for word in words:
            lookup[len(word)].add(word)
        keys = list(lookup.keys())
        keys.sort(reverse=True)
        
        @lru_cache(None)
        def depth(word):
            cnt = len(word)-1
            if cnt not in lookup:
                return 1
            res = 1
            for i in range(len(word)):
                temp = word[:i]+word[i+1:]
                if temp in lookup[cnt]:
                    res = max(res, depth(temp)+1)
            return res
        
        res = 1
        for cnt in keys:
            candicates = lookup[cnt]
            for word in candicates:
                res = max(res, depth(word))
            if res > cnt:
                break
        return res            
__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        
        
        length = collections.defaultdict(set)
        for w in words:
            length[len(w)].add(w)
        
        Ls = sorted(list(length.keys()))
        res = collections.defaultdict(int)
        for i, L in enumerate(Ls):
            if i == 0:
                for w in length[L]:
                    res[w] = 1
            else:
                if L-1 != Ls[i-1]:
                    for w in length[L]:
                        res[w] = 1
                else:
                    for w in length[L]:
                        tmp = 1
                        for j,ch in enumerate(w):
                            shorter = w[:j] + w[j+1:]
                            if shorter in res and res[shorter]+1 > tmp:
                                tmp = res[shorter] + 1
                        res[w] = tmp
        return max(res.values())
__________________________________________________________________________________________________
sample 92 ms submission
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        def hasParent(wordset, word):
            for i in range(len(word)):
                temp = word[:i] + word[i+1:]
                if temp in wordset:
                    return temp
            return None
            
        wordset = set(words)
        longest = {}
        ans = 0
        for word in words:
            longest[word] = 1
            
        for word in list(sorted(words, key = len, reverse=True)):
            parent = hasParent(wordset, word)
            if parent is not None:
                longest[parent] = max(longest[parent], longest[word]+1)
            ans = max(ans, longest[word])
                
        return ans