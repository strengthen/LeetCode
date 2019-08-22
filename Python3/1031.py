__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        n = len(A)
        for i in range(1, n):
            A[i] += A[i-1]
        res = -1
        l_sum, m_sum = A[L-1], A[L+M-1] - A[L-1]
        mm_sum, ll_sum = A[M-1], A[L+M-1] - A[M-1]
        res = max(l_sum + m_sum, ll_sum + mm_sum)
        for i in range(L+M, n):
            l_sum = max(l_sum, A[i-M] - A[i-M-L])
            m_sum = A[i] - A[i-M]
            mm_sum = max(mm_sum, A[i-L] - A[i-M-L])
            ll_sum = A[i] - A[i-L]
            res = max(res, l_sum + m_sum, ll_sum + mm_sum)
        return res
__________________________________________________________________________________________________
sample 13088 kb submission
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:

        '''
        def solve(l,m):
            left = p = sum(A[:l]) 
            c = sum(A[l:l+m])
            ans = left + c
            for i in range(l, len(A) - m):
                p += A[i] - A[i-l]
                c += A[i+m] - A[i]
                left = max(left, p)
                ans = max(c + left, ans) 
            return ans 
        return max(solve(L,M), solve(M, L))
        '''
        for i in range(1, len(A)):
            A[i] += A[i-1]
        ans = A[L+M-1];
        Lmax=A[L-1]  # running max of L sequence
        Mmax=A[M-1]  # running max of M sequence
        for i in range(L+M, len(A)):
            Lmax = max(Lmax, A[i-M]-A[i-L-M])
            Mmax = max(Mmax, A[i-L]-A[i-L-M])
            ans=max(ans, Lmax+A[i]-A[i-M])
            ans=max(ans, Mmax+A[i]-A[i-L])
        return ans    
__________________________________________________________________________________________________
