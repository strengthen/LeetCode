__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        set_j = set(list(J))
        set_s = set(list(S))
        common = set_j.intersection(set_s)
        count = 0
        for i in S:
            if i in common:
                count += 1
        return count
__________________________________________________________________________________________________
sample 12952 kb submission
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        num_jewels = 0
        j_set = set(J)
        
        for s in S:
            if s in j_set:
                num_jewels += 1
        
        return num_jewels
__________________________________________________________________________________________________
