__________________________________________________________________________________________________
sample 248 ms submission
import numpy as np
from numpy import *
from scipy.spatial.distance import pdist, squareform

class Solution:   
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        a = squareform(pdist(np.array(points)))
        
        result = 0
        for i in a:#遍历每一行
            count = np.unique(i,return_counts=True)[1]
            result += sum(count*(count - 1))          
        return result
__________________________________________________________________________________________________
sample 13328 kb submission
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        from collections import defaultdict
        ans = 0
        for i in range(len(points)):
            p = points[i]
            d = defaultdict(int)
            for j in range(len(points)):
                if j != i:
                    q = points[j]
                    d[abs(complex(*p) - complex(*q))] += 1

            for k in d:
                ans += d[k]*(d[k]-1)
        return ans
__________________________________________________________________________________________________
