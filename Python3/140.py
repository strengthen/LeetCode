__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        
        # dfs + memo
        # sentence(i)(or memo[i]) means all sentences we can build from s[i:]
        # memo[len(s)] = ['']
        # Time O
        memo = collections.defaultdict(list)
        wordDict=set(wordDict)
        len_w = set(len(w) for w in wordDict)
        n = len(s)
        memo[n] = ['']
        def sentence(i):
            if i not in memo:
                for j in len_w:
                    if s[i:i+j] in wordDict:
                        #print(s[i:j])
                        for tail in sentence(i+j):
                            if tail == '':
                                memo[i].append(s[i:i+j])
                            else:
                                memo[i].append(s[i:i+j] + ' ' + tail)
                            #print(i,memo)
            return memo[i]
        return sentence(0)            
__________________________________________________________________________________________________
sample 13140 kb submission
class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a list of strings
    def check(self, s, dict):
        dp = [False for i in range(len(s)+1)]
        dp[0] = True
        for i in range(1, len(s)+1):
            for k in range(0, i):
                if dp[k] and s[k:i] in dict:
                    dp[i] = True
        return dp[len(s)]
        
    def dfs(self, s, dict, stringlist):
        if self.check(s, dict):
            if len(s) == 0: Solution.res.append(stringlist[1:])
            for i in range(1, len(s)+1):
                if s[:i] in dict:
                    self.dfs(s[i:], dict, stringlist+' '+s[:i])
    
    def wordBreak(self, s, dict):
        Solution.res = []
        self.dfs(s, dict, '')
        return Solution.res
__________________________________________________________________________________________________
