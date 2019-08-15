__________________________________________________________________________________________________
sample 28 ms submission

class Solution:
    def bulbSwitch(self, n: int) -> int:
        return int(n ** 0.5)
__________________________________________________________________________________________________
sample 12972 kb submission
from math import sqrt 
class Solution:
    def bulbSwitch(self, n: int) -> int:
        # only squared numbers will be "on" in the end
        # the problem is the same as to find the int square root
        return int(sqrt(n))        
__________________________________________________________________________________________________
