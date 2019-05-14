__________________________________________________________________________________________________
sample 152 ms submission
class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        dp = [0]*len(A)
        max_val = 0
        for i in range(K):
            if max_val < A[i]:
                max_val = A[i]
            dp[i] = max_val * (i+1)
        for i in range(K, len(A)):
            max_val=0
            for p in range(0, K):
                if A[i-p] > max_val:
                    max_val = A[i-p]
                update = dp[i-p-1] + max_val * (p+1) 
                if update > dp[i]:
                    dp[i] = update
        return dp[-1]
__________________________________________________________________________________________________
sample 204 ms submission
class Solution:
    def helper(self, A, K, i, mem):
        if i== len(A):
            return
        if i < K:
            mem.append(max(A[:i+1])*(i+1))
            self.helper(A, K, i+1, mem)
        else:
            best = 0
            best_index = None
            running = 0
            for j in range(i, i-K,-1):
                running = max(running,A[j])
                r = running*(i-j+1)
                l = mem[j-1]
                if r+l > best:
                    best = r+l
                    best_index = j 
            mem.append(best)
            self.helper(A, K, i+1, mem)
                
    
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        if len(A) == 0:
            return 0
        mem = []
        self.helper(A, K, 0 ,mem)

        return mem[-1]
__________________________________________________________________________________________________
sample 232 ms submission
class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        dp_array = []
        
        #First part
        max_so_far = A[0]
        for i in range(K):
            max_so_far = max(max_so_far, A[i])
            dp_array.append(max_so_far * (i + 1))
        #Second part
        for i in range(K, len(A)):
            best_option = 0
            max_so_far = A[i]
            for j in range(i - 1, i - K - 1, -1):
                this_option = dp_array[j] + (max_so_far * (i - j))
                best_option = max(this_option, best_option)
                max_so_far = max(max_so_far, A[j])
            dp_array.append(best_option)
        return dp_array[-1]