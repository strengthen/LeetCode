__________________________________________________________________________________________________
sample 796 ms submission
class Solution:
    def subarrayBitwiseORs(self, A: List[int]) -> int:
        Set = set()
        tmp  = {0}
        for cur in A:
            tmp = {cur | ele for ele in tmp}
            tmp.add(cur)
            Set.update(tmp)
 
        return len(Set)
__________________________________________________________________________________________________
sample 39212 kb submission
class Solution:
    def subarrayBitwiseORs(self, A: List[int]) -> int:
        
        ans = set()
        cur = {0}
        for x in A:
            cur = {x | y for y in cur} | {x}
            ans |= cur
        return len(ans)                
__________________________________________________________________________________________________
