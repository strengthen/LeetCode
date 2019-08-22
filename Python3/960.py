__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        remained = [1] * len(A[0])
        for i in range(len(A[0]) - 2, -1, -1):
            for j in range(i + 1, len(A[0])):
                all_good = True
                for row in A:
                    if row[i] > row[j]:
                        all_good = False
                        break
                if all_good:
                    remained[i] = max(remained[i], remained[j] + 1)
        return len(A[0]) - max(remained)
__________________________________________________________________________________________________
sample 112 ms submission
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        n = len(A[0])
        dp = list(range(n))
        for r in range(1, n):
            for l in range(r - 1, -1, -1):
                good = True
                for s in A:
                    if s[l] > s[r]:
                        good = False
                        break
                if good:
                    dp[r] = min(dp[r], dp[l] + r - l - 1)
                    
        mn = n
        for i,d in enumerate(dp):
            mn = min(mn, d + n - (i + 1))
        return mn
__________________________________________________________________________________________________
