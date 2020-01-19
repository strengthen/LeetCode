__________________________________________________________________________________________________
sample 376 ms submission
from collections import Counter
import heapq
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        sm =sum(nums)
        ln = len(nums)
        if ln%k==0 and ((sm-(ln//k)*((k*k-k)//2)) ==(sm-(ln/k)*(k*k-k)/2)) and (sm-(ln//k)*((k*k-k)//2)) %k ==0:
            numC = Counter(nums)
            while numC:
                mc = min(numC)
                cc = numC[mc]
                for i in range(mc,mc+k):
                    if i in numC:
                        if cc==numC[i]:
                            numC.pop(i)
                            continue
                        else:
                            numC[i]-=cc
                        if numC[i]<0:
                            return False
                    else:
                        return False                    
            return True
        else:
            return False
__________________________________________________________________________________________________
sample 396 ms submission
import collections
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if not nums: return True
        if len(nums)%k != 0: return False
        
        c = collections.Counter(nums)
        while c:
            cur = min(c)
            count = c[cur]
            for i in range(k):
                if c[cur + i] == count:
                    c.pop(cur + i)
                    continue
                else:
                    c[cur + i] -= count                
                if c[cur + i] < 0:
                    return False
        return True           
__________________________________________________________________________________________________
