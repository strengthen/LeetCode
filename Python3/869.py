__________________________________________________________________________________________________
sample 28 ms submission
from collections import Counter
class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        L = math.floor(math.log(N,10))+1
        log2of10 = math.log(10,2)
        
        def areRearrangements(adict,b):            
            bdict = Counter(str(b))
            return bdict == adict
                
        
        adict = Counter(str(N))
        
        # if N has k digits, then its rearrangements are between 10^(k-1) and 10^k
        # so the powers of 2 it could be have powers between (k-1)log_2(10) and klog_2(10)
        exp = math.ceil((L-1)*log2of10)
        power = 2**exp
        while exp < math.ceil(L*log2of10):
            if areRearrangements(adict,power):
                return True
            else:
                power *= 2
                exp += 1
        return False
__________________________________________________________________________________________________
sample 13040 kb submission
class Solution:
    # 模範解答をベースに高速化
    def __init__(self):
        self.memo = set([''.join(sorted(str(2**i))) for i in range(30)])

    def reorderedPowerOf2(self, N: int) -> bool:
        return ''.join(sorted(str(N))) in self.memo
__________________________________________________________________________________________________
