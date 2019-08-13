__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dic = dict()
        def helper(s):
            if not s: return True
            elif s in dic: return dic[s]
            else:dic[s]=any(helper(s[len(w):]) for w in wordDict if w==s[:len(w)])
            return dic[s]
        return helper(s)
__________________________________________________________________________________________________
sample 12964 kb submission
class Solution:
    def wordBreak(self, s: 'str', wordDict: 'List[str]') -> 'bool':
        n = len(s)
        if not wordDict:
            return False
        max_word_size = max([len(i) for i in wordDict])
        wordDict = set(wordDict)
        memo = [False] * (n+1)
        memo[n] = 1
        for i in range(n-1, -1, -1):
            next_max = min(i+1+max_word_size, n+1)
            for j in range(i+1, next_max):
                if s[i: j] in wordDict and memo[j] == True:
                    memo[i] = True
        return memo[0]
__________________________________________________________________________________________________
