__________________________________________________________________________________________________
sample 40 ms submission
import functools
class Solution:
        def mergeStones(self, stones, K):
            n = len(stones) 
            if (n - 1) % (K - 1) != 0: # each merge removes K - 1 and must leave 1 remaining 
                return -1 
            prefix_sum = [0] * (n + 1) # prefix_sum allows calculation of the sum of stones in a subarray 
            for i in range(n): prefix_sum[i + 1] = prefix_sum[i] + stones[i]
            @functools.lru_cache(None)
            def helper(i, j): # merge stones[i:j + 1] 
                if j - i + 1 < K: # cannot merge length less than K 
                    return 0
                res = min(helper(i, mid) + helper(mid + 1, j) for mid in range(i, j, K - 1))
                if (j - i) % (K - 1) == 0: 
                    res += prefix_sum[j + 1] - prefix_sum[i]
                return res
            return helper(0, n - 1)
__________________________________________________________________________________________________
sample 13452 kb submission
from collections import defaultdict

class Solution:
    def mergeStones(self, stones: List[int], K: int) -> int:
        count = len(stones)
        if (count-1) % (K-1):
            return -1
        dp = defaultdict(lambda: defaultdict(lambda:(sys.maxsize, 0)))
        
        for x in range(1, count + 1):
            for i in range(0, count - x + 1):
                if x < K:
                    dp[i, i + x][x] = (0, sum(stones[i:i+x]))
                elif x == K:
                    dp[i, i + x][1] = (sum(stones[i:i+x]), sum(stones[i:i+x]))
                else:
                    for j in range(i + 1, i + x):
                        leftStones1 = dp[i, j]
                        leftStones2 = dp[j, i + x]
                        
                        for l1 in leftStones1:
                            for l2 in leftStones2:
                                if l1 + l2 < K:
                                    dp[i, i + x][l1+l2] = (min(leftStones1[l1][0] + leftStones2[l2][0], dp[i, i + x][l1+l2][0]), leftStones1[l1][1] + leftStones2[l2][1])
                                elif l1 + l2 == K:
                                    dp[i, i + x][1] = (min(leftStones1[l1][0] + leftStones1[l1][1] + leftStones2[l2][0] + leftStones2[l2][1], dp[i, i + x][1][0]), leftStones1[l1][1] + leftStones2[l2][1])
                            
        if 1 in dp[0, count]:
            return dp[0, count][1][0]
        else:
            return -1   
__________________________________________________________________________________________________
