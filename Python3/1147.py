__________________________________________________________________________________________________
Runtime: 72 ms
Memory Usage: 14.1 MB
class Solution:
    def longestDecomposition(self, text: str) -> int:
        self.memo = {}
        def dp(i,j):
            if i > j:
                return 0
            if i == j:
                return 1
            if (i,j) not in self.memo:
                k = 0
                tmp = 1
                while i+k< j-k:
                    if text[i:i+k+1] == text[j-k:j+1]:
                        tmp = max(tmp,2+dp(i+k+1,j-k-1))
                    k += 1
                self.memo[(i,j)] = tmp
            return self.memo[(i,j)]
        return dp(0,len(text)-1)
__________________________________________________________________________________________________

__________________________________________________________________________________________________
