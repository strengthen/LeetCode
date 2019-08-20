__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def longestWord(self, words: List[str]) -> str:
        ans = ""
        word_set = set(words)
        for word in words:
            if len(word) > len(ans) or len(word) == len(ans) and word < ans:
                can_built = True
                for k in range(1, len(word)):
                    if word[:k] not in word_set:
                        can_built = False
                        break
                if can_built:
                    ans = word
        return ans
__________________________________________________________________________________________________
sample 13324 kb submission
class Solution:
    def longestWord(self, words: List[str]) -> str:
        out=[]
        for w in words:
            x=[w[:i] for i in range(1,len(w))]
            if x==[]:
                continue
            else:
                if all(i in words for i in x):
                    out.append(w)
        if out==[]:
            return sorted(words)[0]
        maxlen=max([len(x) for x in out])
        out2=[x for x in out if len(x)==maxlen]
        out2=sorted(out2)
        return out2[0]
__________________________________________________________________________________________________
