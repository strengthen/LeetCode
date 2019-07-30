__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def stoneGameII(self, A: List[int]) -> int:
        N = len(A)
        for i in range(N - 2, -1, -1):
            A[i] += A[i + 1]
        
        import functools
        
        @functools.lru_cache(None)
        def dp(i, m):
            if i + 2 * m >= N: return A[i]
            return A[i] - min(dp(i + x, max(m, x)) for x in range(1, 2 * m + 1))
        return dp(0, 1)
__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        pos = [0] * len(piles)
        N = len(piles)
        pos[-1] = piles[-1]
        for i in range(N-2,-1,-1):
            pos[i] = pos[1+i] + piles[i]
        # print(pos)
        from functools import lru_cache
        @lru_cache(None)
        def helper(i,M):
            if i + 2*M >= len(piles):
                return pos[i]
            ans = float('-inf')
            for j in range(1,2*M+1):
                ans = max(ans,pos[i]-helper(i+j,max(j,M)))
            return ans
        return helper(0,1)
__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def stoneGameII(self, A) -> int:
        N = len(A)
        for i in range(N - 2, -1, -1):
            A[i] += A[i + 1]
        from functools import lru_cache
        rcd = {}
        def dp(i, m):
            if (i,m) in rcd:
                return rcd[(i,m)]
            if i + 2 * m >= N: return A[i]
            ans =  A[i] - min(dp(i + x, max(m, x)) for x in range(1, 2 * m + 1))
            rcd[(i,m)] = ans
            return ans
        return dp(0, 1)