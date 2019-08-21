__________________________________________________________________________________________________
sample 388 ms submission
class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        
        idxs = sorted(range(len(B)), key=B.__getitem__, reverse=True)
        
        A.sort()
        
        ai = len(A) -1
        res = [-1] * len(A)
        al = 0
        #print(b_sort, a_sort)
        for bi in idxs:
            if A[ai] > B[bi]:
                res[bi] = A[ai]
                ai -= 1
            else:
                res[bi] = A[al]
                al += 1
            #print(bi, res)
            
                
        return res
__________________________________________________________________________________________________
sample 15404 kb submission
class Solution:
    def advantageCount(self, A, B):
        A.sort()
        N = len(B)
        idxB = sorted(range(N), key = lambda i: -B[i])
        L, R, ans = 0, N - 1, [None] * N
        for i in idxB:
            if B[i] >= A[R]:
                ans[i] = A[L]
                L += 1
            else:
                ans[i] = A[R]
                R -= 1
        return ans
__________________________________________________________________________________________________
