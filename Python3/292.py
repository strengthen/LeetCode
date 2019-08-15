__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def canWinNim(self, n: int) -> bool:
        return bool(n%4)
__________________________________________________________________________________________________
sample 13072 kb submission
class Solution:
    def canWinNim(self, n: int) -> bool:
        if n % 4 == 0:
            return False
        else:
            return True        
__________________________________________________________________________________________________
