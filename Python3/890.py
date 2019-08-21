__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        result = []
        for w in words:
            error = False
            if len(w) == len(pattern):
                p2w = {}
                w2p = {}
                for i in range(len(w)):
                    if w[i] not in w2p and pattern[i] not in p2w:
                        w2p[w[i]] = pattern[i]
                        p2w[pattern[i]] = w[i]
                    elif w[i] in w2p and w2p[w[i]] != pattern[i]:
                        error = True
                        break
                    elif pattern[i] in p2w and p2w[pattern[i]] != w[i]:
                        error = True
                        break
            if not error:
                result.append(w)
            
        return result
__________________________________________________________________________________________________
sample 13024 kb submission
class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        matches = []
        
        for word in words:
            match = {}
            used = set()
            
            for i, c in enumerate(word):
                pc = pattern[i]
                expected = match.get(pc)
                
                if expected is not None:
                    if c != expected:
                        break
                else:
                    if c in used:
                        break
                    
                    used.add(c)
                    match[pc] = c
            else:
                matches.append(word)
        
        return matches
__________________________________________________________________________________________________
