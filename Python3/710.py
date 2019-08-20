__________________________________________________________________________________________________
sample 320 ms submission  
import math
import random
class Solution:

    def __init__(self, N: int, blacklist: List[int]):
        b_set = set(blacklist)
        self.N = N
        self.r = r = N - len(blacklist)
        upper_whitelist = [i + self.r for i in range(len(blacklist)) if (i + self.r) not in b_set]
        lower_blacklist = [b for b in blacklist if b < r]
        self.map = {}
        for i, b in enumerate(lower_blacklist):
            self.map[b] = upper_whitelist[i]
    
    def pick(self) -> int:
        rand = math.floor(random.random() * self.r)
        if rand not in self.map:
            return rand
        return self.map[rand]
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
__________________________________________________________________________________________________
sample 21992 kb submission
class Solution:

    def __init__(self, N: int, blacklist: List[int]):
        blacklist = set(blacklist)
        self.length = N - len(blacklist)
        self.remap = {}
        need_remap = []
        
        for i in blacklist:
            # 这里的i既在blacklist中，同时也是会被random函数选的潜在数值。所以要remap
            # 到whitelist中的某个数.
            # i < self.length的意思是length表示whitelist的长度，i 比length小是可能被选到的
            # 所以要加到需要被remap的名单里
            if i < self.length:
                need_remap.append(i)
                
        j = 0
        
        for i in range(self.length, N):
            if i not in blacklist:
                self.remap[need_remap[j]] = i
                j += 1

    def pick(self) -> int:
        idx = random.randrange(self.length)
        return self.remap[idx] if idx in self.remap else idx

# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
__________________________________________________________________________________________________
