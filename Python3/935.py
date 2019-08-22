__________________________________________________________________________________________________
sample 60 ms submission
cache = [[1]*10]
moves = [[4,6],[6,8],[7,9],[4,8],[0,3,9],[],[0,1,7],[2,6],[1,3],[2,4]]
mod = 10**9 + 7

class Solution:
    def knightDialer(self, N: int) -> int:
        while len(cache) < N:
            dp = [0]*10
            for d,s in enumerate(cache[-1]):
                for nei in moves[d]:
                    dp[nei] += s
            cache.append(dp)
        return sum(cache[N-1])%mod
__________________________________________________________________________________________________
sample 12936 kb submission
class Solution:
    def knightDialer(self, N: int) -> int:
        allowable = {1: [6, 8],
             2: [7, 9],
             3: [4, 8],
             4: [3, 9, 0],
             5: [],
             6: [1, 7, 0],
             7: [2, 6],
             8: [1, 3],
             9: [4, 2],
             0: [4, 6]}

#         dp = [[0] * N for i in range(10)]
        dp = [1] * 10
        for j in range(N - 1):
            dp2 = [0] * 10
            for i in range(10):
                for nei in allowable[i]:
                    dp2[i] += dp[nei]
            dp = dp2       
        return sum(dp) % (10 ** 9 + 7)
__________________________________________________________________________________________________
