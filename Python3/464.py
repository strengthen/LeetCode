__________________________________________________________________________________________________
sample 352 ms submission
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        
        seen = {}
        def win(cs,target):
            if cs[-1]>=target:
                return True
            
            key = tuple(cs)
            if key in seen:
                return seen[key]
            
            
            for i in range(len(cs)):
                if not win(cs[:i]+cs[i+1:],target-cs[i]):
                    seen[key]=True
                    return seen[key]
            
            seen[key]=False
            return seen[key]
        
        if desiredTotal < maxChoosableInteger:
            return True
        
        total = (1+maxChoosableInteger)*maxChoosableInteger/2
        
        if total < desiredTotal:
            return False
        
        if total == desiredTotal:
            return maxChoosableInteger%2
        
        cs = [i+1 for i in range(maxChoosableInteger)]
        
        return win(cs,desiredTotal)        
__________________________________________________________________________________________________
sample 360 ms submission
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        
        seen = {}
        def win(cs,target):
            if cs[-1]>=target:
                return True
            
            key = tuple(cs)
            if key in seen:
                return seen[key]
            
            
            for i in range(len(cs)):
                if not win(cs[:i]+cs[i+1:],target-cs[i]):
                    seen[key]=True
                    return seen[key]
            
            seen[key]=False
            return seen[key]
        
        cs = [i+1 for i in range(maxChoosableInteger)]
        
        total = (1+maxChoosableInteger)*maxChoosableInteger/2
        
        if total < desiredTotal:
            return False
        
        if total == desiredTotal:
            return maxChoosableInteger%2
        
        return win(cs,desiredTotal)        
__________________________________________________________________________________________________
