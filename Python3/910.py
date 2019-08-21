__________________________________________________________________________________________________
sample 156 ms submission
class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int:
        K = K * 2
        if K == 0: return max(A) - min(A)
        A = sorted(set(A))
        if len(A)==1: return 0
        mi, ma = A[0], A[-1]
        diff = ma - mi
        for i in range(len(A)-1):
            if A[i] > mi:
                break
            A[i] += K
            new_ma = max(ma, A[i])
            new_mi = min(A[i], A[i+1], A[0])
            new_diff = new_ma - new_mi
            ma, mi, diff = new_ma, new_mi, min(diff, new_diff)
        return diff
__________________________________________________________________________________________________
sample 164 ms submission
class Solution:
    def smallestRangeII(self, A: List[int], K: int) -> int: 
        A = sorted(set(A))
        if len(A) == 1: return 0
        min_ = A[-1] - A[0]
        for i in range(len(A)-1):
            tmp = max(A[0]+K, A[i]+K, A[i+1]-K, A[-1]-K) - min(A[0]+K, A[i]+K, A[i+1]-K, A[-1]-K)
            if tmp < min_: min_ =  tmp
        return min_
__________________________________________________________________________________________________
