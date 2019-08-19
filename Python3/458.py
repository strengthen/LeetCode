__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        import math
        return math.ceil(math.log(buckets,(minutesToTest//minutesToDie) + 1))
__________________________________________________________________________________________________
sample 13092 kb submission
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        return math.ceil(math.log(buckets, minutesToTest//minutesToDie + 1))
__________________________________________________________________________________________________
