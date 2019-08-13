__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def make_results(index,pallindromes, result, results):
            if index >= len(s):
                results += result[:],
            else:
                for pallindrome in pallindromes[index]:
                    make_results(index + len(pallindrome), pallindromes, result + [pallindrome], results)
        
        
        n = len(s)
        is_pallindrome = set()
        pallindromes   = collections.defaultdict(list)
        for i in range(0,len(s)):
            for j in range(i+1):
                if s[i] == s[j] and ((i-j) <= 1 or (j+1,i-1) in is_pallindrome ):
                    is_pallindrome.add( (j,i) )
                    substring = s[j:i+1]
                    pallindromes[j] += substring,
                
        results = []
        make_results(0,pallindromes,[],results)
        return results
__________________________________________________________________________________________________
sample 13288 kb submission
class Solution:
    rst = []
    def partition(self, s: str) -> List[List[str]]:
        self.rst = []
        n = len(s)
        out = []
        dp = [[False for _ in range(n)] for _ in range(n)]
        
        for i in range(n):
            for j in range(0, i + 1):
                if s[i] == s[j] and (i - j <= 2 or dp[j+1][i-1]):
                    dp[j][i] = True
                    
        self.helper(s, 0, dp, out)
        return self.rst
    
    
    def helper(self, s, start, dp, out):
        out = out[:]
        if start == len(s):
            self.rst.append(out)
            return
        
        for i in range(start, len(s)):
            if not dp[start][i]:
                continue
                
            out.append(s[start:i + 1])
            self.helper(s, i + 1, dp, out)
            out.pop()
__________________________________________________________________________________________________
