__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def isSelfCrossing(self, x: List[int]) -> bool:
        x += [0, 0]
        for i in range(3, len(x) - 2):
            x1 = x[i-3] - x[i-1]
            if x1 < 0: continue
            x0 = x[i-2] - x[i]
            if x0 <= 0: return True
            if x[i-4] < x0: continue
            if not x1: return True
            if x[i-4] <= x[i-2] and x1 <= x[i-5]: return True
        return False
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def isSelfCrossing(self, x: List[int]) -> bool:
        if len(x) <= 3: return False
        
        for i in range(3, len(x)):
            if x[i] >= x[i-2] and x[i-1] <= x[i-3]: 
                return True 
            if i >= 4:
                if x[i-1] == x[i-3] and x[i] + x[i-4] >= x[i-2]: 
                    return True
            if i >=5:
                if x[i-2] - x[i-4] >= 0 and x[i] >= x[i-2] - x[i-4] and x[i-1] >= x[i-3] - x[i-5] and x[i-1] <= x[i-3]: 
                    return True
        return False
__________________________________________________________________________________________________
