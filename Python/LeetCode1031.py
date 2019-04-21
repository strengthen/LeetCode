__________________________________________________________________________________________________
48ms
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        n = len(A)
        startL, startM, endL, endM, sums = [float("-inf")] * L, [float("-inf")] * M, [float("-inf")] * L, [float("-inf")] * M, [0]
        for i in range(n):
            sums.append(sums[-1] + A[i])
        for i in range(L, n + 1):
            endL.append(max(endL[-1], sums[i] - sums[i - L]))
            startL.append(max(startL[-1], sums[n - i + L] - sums[n - i]))
        for i in range(M, n + 1):
            endM.append(max(endM[-1], sums[i] - sums[i - M]))
            startM.append(max(startM[-1], sums[n - i + M] - sums[n - i]))
        startL.append(float("-inf"))
        startM.append(float("-inf"))
        startL.reverse()
        startM.reverse()
        return max(max(endL[i] + startM[i + 1] for i in range(L, n - M + 1)), max(endM[i] + startL[i + 1] for i in range(M, n - L + 1)))
__________________________________________________________________________________________________
56ms
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        L_sum, M_sum = [sum(A[:L])], [sum(A[:M])]
        for i in range(1, len(A) - L + 1): 
            L_sum.append(L_sum[-1] + A[i + L - 1] - A[i - 1])
        for i in range(1, len(A) - M + 1): 
            M_sum.append(M_sum[-1] + A[i + M - 1] - A[i - 1])

        L_l2r, L_r2l, M_l2r, M_r2l = [None] * (L - 1), [None] * (L - 1), [None] * (M - 1), [None] * (M - 1)
        max_L_sum = float('-inf')
        for num in L_sum:
            if num > max_L_sum:
                max_L_sum = num
            L_l2r.append(max_L_sum)

        max_L_sum = float('-inf')
        for num in reversed(L_sum):
            if num > max_L_sum:
                max_L_sum = num
            L_r2l.append(max_L_sum)
        L_r2l.reverse()

        max_M_sum = float('-inf')
        for num in M_sum:
            if num > max_M_sum:
                max_M_sum = num
            M_l2r.append(max_M_sum)

        max_M_sum = float('-inf')
        for num in reversed(M_sum):
            if num > max_M_sum:
                max_M_sum = num
            M_r2l.append(max_M_sum)
        M_r2l.reverse()

        print(L_l2r, L_r2l, M_l2r, M_r2l)
        print(L - 1, len(A) - M - 1)
        print(M - 1, len(A) - L - 1)
        rtn = float('-inf')
        for i in range(L - 1, len(A) - M):
            print(L_l2r[i], M_r2l[i + 1])
            rtn = max(rtn, L_l2r[i] + M_r2l[i + 1])
        for i in range(M - 1, len(A) - L):
            print(M_l2r[i], L_r2l[i + 1])
            rtn = max(rtn, M_l2r[i] + L_r2l[i + 1])

        return rtn
__________________________________________________________________________________________________
72ms
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        lsum = [sum(A[i:i+L]) for i in range(len(A) - L + 1)]
        msum = [sum(A[i:i+M]) for i in range(len(A) - M + 1)]
        #print(lsum, msum)
        
        R = t1 = t2 = float('-inf')
        for i in range(len(A) - L - M + 1):
            
            t1 = max(t1, lsum[i])
            #print(i,t1,msum[i+L])
            R = max(R, t1 + msum[i+L])


            t2 = max(t2, msum[i])
            #print(i, t2,lsum[i+M])
            R = max(R, t2 + lsum[i+M])
                
        return R
__________________________________________________________________________________________________
268ms
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        
        psums = [0]
        for i in A:
            psums.append(psums[-1] + i)
            
        
        best = 0
        for i in range(len(psums) - L):
            cur = psums[i + L] - psums[i]
            for j in range(i + L, len(psums) - M):
                new = psums[j + M] - psums[j]
                best = max(best, cur + new)
                
        for i in range(len(psums) - M):
            cur = psums[i + M] - psums[i]
            for j in range(i + M, len(psums) - L):
                new = psums[j + L] - psums[j]
                best = max(best, cur + new)
        return best
__________________________________________________________________________________________________
288ms
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        if L < M:
            L, M = M, L
        accs = [0]
        acc = 0
        for num in A:
            acc += num
            accs.append(acc)
        n = len(accs)
        # print(n)
        ans = accs[L] + accs[-1] - accs[-M-1]
        for i in range(L, n):
            lacc = accs[i] - accs[i - L]
            macc = -math.inf
            for j in range(i - L + 1):
                if j >= M:
                    macc = max(macc, accs[j] - accs[j - M])
            for j in range(i, n):
                if j + M < n:
                    macc = max(macc, accs[j + M] - accs[j])
            # print(lacc, macc)
            ans = max(ans, lacc + macc)
        return ans
__________________________________________________________________________________________________
300ms
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        if L < M:
            L, M = M, L
        accs = [0]
        acc = 0
        for num in A:
            acc += num
            accs.append(acc)
        n = len(accs)
        ans = accs[L] + accs[-1] - accs[-M-1]
        for i in range(L, n):
            lacc = accs[i] - accs[i - L]
            macc = -math.inf
            for j in range(i - L + 1):
                if j >= M:
                    macc = max(macc, accs[j] - accs[j - M])
            for j in range(i, n):
                if j + M < n:
                    macc = max(macc, accs[j + M] - accs[j])
            ans = max(ans, lacc + macc)
        return ans