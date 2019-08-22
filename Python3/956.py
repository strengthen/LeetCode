__________________________________________________________________________________________________
sample 52 ms submission
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        rods.sort(reverse=True)
        for l in range(len(rods), 1, -1):
            for comb in itertools.combinations(rods, l):
                s = sum(comb)
                if s % 2 == 0:
                    s //= 2
                    X = set([s])
                    for x in comb:
                        if x in X:
                            return s
                            
                        else:
                            Y = [y - x for y in X if y > x]
                            X.update(Y)
        return 0
__________________________________________________________________________________________________
sample 13108 kb submission
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        
        s = sum(rods)
        
        dp = [-1] * (s+1)

        dp[0] = 0
        for rod in rods:
            curr = copy.copy(dp)
            for height in range(s - rod + 1):
                if curr[height] < 0:
                    continue
                dp[height+rod] = max(curr[height], dp[height + rod])
                dp[abs(height-rod)] = max(dp[abs(height-rod)], curr[height] + min(height, rod))
                
                
        return dp[0]
__________________________________________________________________________________________________
