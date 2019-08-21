__________________________________________________________________________________________________
sample 340 ms submission
class Solution:
    def sumSubseqWidths(self, A):
        A = sorted(A)
        ans = 0
        mod = 10 ** 9 + 7
        for i, v in enumerate(A):
            ans *= 2
            ans += A[~i] - A[i]
            ans %= mod
        return ans
__________________________________________________________________________________________________
sample 348 ms submission
class Solution:
    def sumSubseqWidths(self, A: List[int]) -> int:
        N = len(A)
        # there are 2**N subsequences of A (including empty and single elements), so we can't iterate over them all for large N
        A.sort()
        # the original order of A doesn't matter, and since the sub-sequence property we're interesting in 'width' needs (only) the min/max value, sorting A seems like a reasonable first step
        
        # now, consider all the subsequences that contain both A[0] and A[-1] (the min and max elements). there are 2**(N-2) of these, all with the same width, and we need not construct/consider them any more. progress?
        # it seems like the width is uniquelly determined by how many leading/trailing elements are *not in the set*. after that on each end, we know the width is constant, so we need not consider all the sub-strings. so we can do something N^2 on the sorted array, and adjust width by (2-to-the-power-of-) the number of 'inner' elements.
        
        # okay, next step -- split the calculation into the min and max halves; thus we need only total the maxes and mins of all subsequences seperatly, and then take the delta. we use the same trick to calculate the number of sub-sequenced with a given min/max based on how many elements there are before/after it.
        
        # FIXME: seems like we could maybe still use the const-factor optimization to reduce the number of bignum ops?
        tot_wid = 0
        num_seqs = 1 
        for i in range(N): # first included element index
            tot_wid += (A[i]-A[N-i-1]) * (num_seqs - 1) # num_seqs can't be zero by fermat's little theorem
            num_seqs = (num_seqs << 1) % (10**9 + 7)
            
            
            
        return tot_wid % (10**9 + 7)
__________________________________________________________________________________________________
