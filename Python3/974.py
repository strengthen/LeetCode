__________________________________________________________________________________________________
sample 320 ms submission

class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        acc = list(itertools.accumulate(A))
        modCnt = [0] * K
        for a in acc:
            modCnt[a % K] += 1
        modCnt[0] += 1
        ret = 0
        for cnt in modCnt:
            ret += cnt * (cnt - 1) // 2
        return ret
__________________________________________________________________________________________________
sample 15656 kb submission
from collections import defaultdict
class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        sum_idx = defaultdict(int)
        cur_sum = 0
        res = 0
        sum_idx[0] = 1
        for i, num in enumerate(A):
            cur_sum += A[i]
            if (cur_sum % K) in sum_idx:
                res += sum_idx[cur_sum%K]
                
            sum_idx[cur_sum % K] += 1
        
        return res
__________________________________________________________________________________________________
