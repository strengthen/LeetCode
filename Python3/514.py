__________________________________________________________________________________________________
sample 88 ms submission
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        prev, m = {0 : 0}, len(ring)
        ldict = {}
        for i, l in enumerate(ring):
            if not l in ldict:
                ldict[l] = [i]
            else:
                ldict[l].append(i)
        
        for target in key:
            cur = {}
            for previ in prev:
                tlist, midi = ldict[target], None
                if tlist[0] > previ or tlist[-1] < previ:
                    lefti, righti = tlist[-1], tlist[0]
                else:
                    for i in tlist:
                        if i == previ:
                            midi = i
                            break
                        elif i < previ:
                            lefti = i
                        else:
                            righti = i
                            break
                if midi != None:
                    stepinc = min(abs(midi - previ), m - abs(midi - previ))
                    if not midi in cur:
                        cur[midi] = prev[previ] + stepinc
                    else:
                        cur[midi] = min(cur[midi], prev[previ] + stepinc)
                else:
                    stepinc = min(abs(lefti - previ), m - abs(lefti - previ))
                    if not lefti in cur:
                        cur[lefti] = prev[previ] + stepinc
                    else:
                        cur[lefti] = min(cur[lefti], prev[previ] + stepinc)
                    if righti != lefti:
                        stepinc = min(abs(righti - previ), m - abs(righti - previ))
                        if not righti in cur:
                            cur[righti] = prev[previ] + stepinc
                        else:
                            cur[righti] = min(cur[righti], prev[previ] + stepinc)
            prev = cur
        
        return min(prev.values()) + len(key)
__________________________________________________________________________________________________
sample 13072 kb submission
# Input: ring = "godding", key = "gd"
# Output: 4
# Explanation:
# For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
# For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
# Also, we need 1 more step for spelling.
# So the final output is 4.
class Solution:
    # "pqwcx"
    #  01234
    #  3-1 or 5-3 or 
    def shortestRotationStep(self, ring, begin, end):
        size = len(ring)
        return min(abs(begin - end), min(begin, end) + size - max(begin, end))
        
    def decideSteps(self, dp, ring, key, id):
        for i in [i for i, r in enumerate(ring) if r == key[id]]:
            steps = 0x7FFFFFFF
            for j in dp[id - 1]:
                s = dp[id - 1][j] + self.shortestRotationStep(ring, j, i) + 1
                steps = min(steps, s)
            dp[id][i] = steps
        return dp
        
    def findRotateSteps(self, ring: str, key: str) -> int:
        # can be solve by a DP
        # dp table: len(key) x len(ring)
        dp = [{} for i in range(len(key))]
        # explain: dp[key i] = {ring pos -> steps}
        
        for i in [i for i, r in enumerate(ring) if r == key[0]]:
            dp[0][i] = self.shortestRotationStep(ring, 0, i) + 1
            
        for i in range(1, len(key)):
            dp = self.decideSteps(dp, ring, key, i)
            
        steps = [dp[-1][x] for x in dp[-1]]
        return min(steps)
__________________________________________________________________________________________________
