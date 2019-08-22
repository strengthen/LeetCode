__________________________________________________________________________________________________
sample 264 ms submission
class Solution:
    def numSubarraysWithSum(self, A: List[int], S: int) -> int:
        ones = []
        cur = 0
        for num in A:
            if num == 0:
                cur += 1
            else:
                ones.append(cur)
                cur = 0
        ones.append(cur)
        if S == 0:
            res = 0
            for ele in ones:
                res += (ele + 1) * ele //2
            return res
        
        L = len(ones)
        if L < S + 1:
            return 0
        start = 0
        ed = S
        res = 0
        while ed < L:
            res += (ones[start] + 1) * (ones[ed] + 1)
            ed += 1
            start += 1
        return res
__________________________________________________________________________________________________
sample 13992 kb submission
class Solution(object):
    def numSubarraysWithSum(self, A, S):
        i_lo = i_hi = 0
        sum_lo = sum_hi = 0
        ans = 0
        for j, x in enumerate(A):
            sum_lo += x
            while i_lo < j and sum_lo > S:
                sum_lo -= A[i_lo]
                i_lo += 1
            sum_hi += x
            while i_hi < j and (
                    sum_hi > S or sum_hi == S and not A[i_hi]):
                sum_hi -= A[i_hi]
                i_hi += 1

            if sum_lo == S:
                ans += i_hi - i_lo + 1

        return ans
__________________________________________________________________________________________________
