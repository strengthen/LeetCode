__________________________________________________________________________________________________
sample 44 ms submission
inf = float('inf')

class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        costs = [[0] * (n + 1) for i in range(n)]
        
        for ij in range(2, n+n):
            c = 0
            z = (ij >> 1)

            # ij = 2 -> :1 -1:
            # ij = 3 -> :1 -1:
            # ij = 4 -> :2 -2:

            for j, i in zip(range(ij-z, min(ij, n)), range(z-1, -1, -1)):
                if s[i] != s[j]:
                    c += 1
                costs[i][j+1] = c

        # at k = 1, n = 1..n
        dp = costs[0]
        # print('k=', 1, '\n', dp)
        
        # for k = 2 .. k
        for p in range(2, k+1):            
            for l in range(n+p-k, p, -1):
                x = min(dp[head] + costs[head][l] for head in range(p-1, l))
                dp[l] = x
            
            dp[p] = 0
            # dp[p-1] = inf
        
        return dp[-1]
__________________________________________________________________________________________________
sample 52 ms submission
class Solution2:
    def palindromePartition(self, s: str, k: int) -> int:
        
        def changesNeeded(s):
            if len(s) == 1:
                return 0
            
            count = 0
            for i, val in enumerate(s[:int(len(s)//2)-1:-1]):
                if s[i] != val:
                    count += 1
            return count
        
        mem = {}
        l = len(s)
            
        def search(index, l, k):
            if l <= k:
                return 0
            if (index, k) in mem:
                return mem[index, k]
            if k == 1:
                return changesNeeded(s[index:])
            
            ret = search(index + 1, l-1, k-1)
            for i in range(2, l-k+2):            
                ret = min(ret, search(index + i, l-i, k-1)+changesNeeded(s[index:index+i]))
            mem[index, k] = ret
            return ret
            
        return search(0, l, k)
    
inf = float('inf')

class Solution3:
    def palindromePartition(self, s: str, k: int) -> int:
        l = len(s)
        
        m = [[0 for j in range(l)] for i in range(l)] #cost map from s[i] to s[j]
        for ii in range(1, l+l-2):
            if ii%2 == 1:
                i = int(ii//2)
                j = i+1
            else:
                i = ii/2
                j = i+2
                
            count = 0
            while i>0 and j<l:
                if s[i] == s[j]:
                    count += 1
                i-=1
                j += 1
                
        dp = m[0]
        
        # for k = 2 .. k
        for p in range(2, k+1):            
            for j in range(l+p-k, p, -1):
                x = min(dp[head] + m[head][j] for head in range(p-1, j))
                dp[j] = x
            
            dp[p] = 0
        
        return dp[-1]
    
inf = float('inf')

class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        costs = [[0] * (n + 1) for i in range(n)]
        
        for ij in range(2, n+n):
            c = 0
            z = (ij >> 1)

            # ij = 2 -> :1 -1:
            # ij = 3 -> :1 -1:
            # ij = 4 -> :2 -2:

            for j, i in zip(range(ij-z, min(ij, n)), range(z-1, -1, -1)):
                if s[i] != s[j]:
                    c += 1
                costs[i][j+1] = c

        # at k = 1, n = 1..n
        dp = costs[0]
        # print('k=', 1, '\n', dp)
        
        # for k = 2 .. k
        for p in range(2, k+1):            
            for l in range(n+p-k, p, -1):
                x = min(dp[head] + costs[head][l] for head in range(p-1, l))
                dp[l] = x
            
            dp[p] = 0
            # dp[p-1] = inf
        
        return dp[-1]
__________________________________________________________________________________________________
