__________________________________________________________________________________________________
sample 180 ms submission
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        # dp
        """     
        m, n = len(A), len(B)
        # dp[i][j]: max common prefix length of A[:(i + 1)], B[:(j + 1)]
        dp = [
            [0] * n
            for _ in range(m)
        ]
        max_len = 0
        
        for j in range(n):
            dp[0][j] = int(A[0] == B[j])
            max_len = max(max_len, dp[0][j])
        
        for i in range(m):
            dp[i][0] = int(A[i] == B[0])
            max_len = max(max_len, dp[i][0])
        
        for i in range(1, m):
            for j in range(1, n):
                if A[i] == B[j]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                    max_len = max(max_len, dp[i][j])
                    
        return max_len
        """
        
        # binary search
        m, n = len(A), len(B)
        
        def check(k):
            if k == 0:
                return True
            
            # calculating hash values of k-subarray in O(len) time
            # hs[i] = hash(A[i:(i + k)])
            #     = sum(A[i + j] * (P ** (k - j - 1)) for j in range(k)) % M
            # hs[i + 1] = hash(A[(i + 1):(i + k + 1)])
            #           = ((hs[i] - A[i] * (P ** (k - 1))) * P + A[i + k]) % M
            P, M = 113, 10**9 + 7
            pows = [1] * k
            
            for j in range(1, k):
                pows[j] = (pows[j - 1] * P) % M
                
            h = 0
            
            for j in range(k):
                h = (h + A[j] * pows[k - j - 1]) % M
                
            hs = {h}
            
            for i in range(1, m - k + 1):
                h = (((h - A[i - 1] * pows[k - 1]) * P) + A[i + k - 1]) % M
                hs.add(h)
                
            h = 0
            
            for j in range(k):
                h = (h + B[j] * pows[k - j - 1]) % M
            
            if h in hs:
                return True
            
            for i in range(1, n - k + 1):
                h = (((h - B[i - 1] * pows[k - 1]) * P) + B[i + k - 1]) % M
                
                if h in hs:
                    return True

            return False
        
        l, r = 0, min(m, n) + 1
        
        while l + 1 < r:
            k = (l + r) >> 1
            
            if check(k):
                l = k
            else:
                r = k
                
        return l
__________________________________________________________________________________________________
sample 13636 kb submission
class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        def check(length):
            d = {A[i:i+length] for i in range(len(A)-length+1)}
            return any(B[j:j+length] in d for j in range(len(B)-length+1))
        A = ''.join(map(chr, A))
        B = ''.join(map(chr, B))
        l, r = 0, min(len(A), len(B))+1
        while l<r:
            mid = (l+r)//2
            if check(mid):
                l=mid+1
            else:
                r=mid
        return l-1
__________________________________________________________________________________________________
