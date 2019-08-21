__________________________________________________________________________________________________
sample 44 ms submission
from functools import lru_cache
class Solution:    
    cache = {0:0}
    @lru_cache(None)
    def racecar(self, target: int) -> int:
        #这里用dp，记录下来从0到任意一个点的距离，因为很多点不会经过，所以不用循环用递归
        #Dijkstra?
        if target in self.cache:
            return self.cache[target]
        
        k = target.bit_length()
        
        if target == (1<<k) - 1:
            self.cache[target] = k
        
        else:
            #走K步，掉头
            self.cache[target] = self.racecar((1<<k)-1-target) + k + 1
            
            #走K-1步,掉头， 然后往回走m步后掉头，等效的target是 target - (1 << (k-1) -1 - ((1 << m ) - 1))
            for m in range(k-1):
                self.cache[target] = min(self.cache[target], self.racecar(target+(1<<m)-(1<<(k-1))) + m + k + 1)
                
        return self.cache[target]
        
        
        
    def racecar1(self, target: int) -> int:
        #bfs + dp
        res = 0
        q=[(0, 1), (None, None)]
        
        k = target.bit_length() + 1
        
        while q:
            pos, spd = q.pop(0)
            if pos is None:
                res += 1
                q.append((None, None))
            else:
                if pos == target:
                    return res
                else:
                    q.append((pos+spd, spd*2))
                    if pos < target:
                        if spd > 0:
                            if pos + spd > target:
                                q.append((pos, -1))
                        else:
                            q.append((pos, 1))
                    else:
                        if spd < 0:
                            if pos+spd < target:
                                q.append((pos, 1))
                        else:
                            q.append((pos, -1))
        return res
__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def racecar(self, target: int) -> int:
        # Idea: DP with optimal substructure:
        #           memo(target) = min of:
        #               n + 1 + memo(2 ^ n - 1 - target)        
        #               (n - 1) + 1 + memo(m) + memo(target - (2 ^ (n - 1) - 1 - m))
        #
        #           where:
        #               2 ^ (n - 1) - 1 <= target <= 2 ^ n - r
        #
        #   1. Driving distance of 'A' * n = 2 ^ n - 1
        #   2. Try to let the car accelerate as much as possible
        #   3. To reach target with shortest instruction, there're 2 ways defined:
        #       1. drive with 'A' * n passing target and then turn back to target
        #       2. drive with 'A' * (n - 1) arriving before target,
        #          then turn back with 'R' and drive 'A' * m,
        #          finally turn around with 'R' and drive 'A' * k to reach target
        #
        # Time:
        #
        # Space:

        # Define the max number of consecutive 'A's
        n = target.bit_length()
        # The car never pass through this position
        barrier = 1 << n
        memo = [None] * (barrier + 1)
        # Base case where '' to reach target position 0
        memo = {0:0}
        self.dp(target, memo)

        return memo[target]

    def dp(self, t, memo):
        if t in memo:
            return memo[t]

        n = t.bit_length()
        accelerateDist = (1 << n) - 1
        if accelerateDist == t:
            memo[t] = n

            return n

        # Keep accelerating (with 'A' * n) until reaching or passing target, then turn around
        minInst = n + 1 + self.dp(accelerateDist - t, memo)

        # Keep accelerating until close to target (with 'A' * (n - 1)),
        # then turn around (with 'R') and drive back for m distance,
        # finally turn around (with 'R') and drive to target
        accelerateDist = (1 << (n - 1)) - 1
        for m in range(n - 1):
            backDist = (1 << m) - 1
            minInst = min(minInst, n + m + 1 + self.dp(t - (accelerateDist - backDist), memo))

        memo[t] = minInst

        return minInst
__________________________________________________________________________________________________
