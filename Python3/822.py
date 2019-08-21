__________________________________________________________________________________________________
sample 104 ms submission
class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        #print(fronts + backs)
        same = {x for i,x in enumerate(fronts) if x == backs[i]}
        
        ans = float('inf')
        for x in fronts + backs:
            if x not in same:
                ans = min(ans, x)
        
        return ans if ans != float('inf') else 0
        
        # for x in itertools.chain(fronts, backs):
__________________________________________________________________________________________________
sample 112 ms submission
class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        ans = 1 << 32
        nums = set()
        ex = set()
        for a, b in zip(fronts, backs):
            if a == b:
                ex.add(a)
            else:
                nums.add(a)
                nums.add(b)
        diff = nums.difference(ex)
        return min(diff) if diff else 0
__________________________________________________________________________________________________
