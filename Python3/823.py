__________________________________________________________________________________________________
sample 148 ms submission
class Solution:
    def numFactoredBinaryTrees(self, A: List[int]) -> int:
        local_counts = {}
        result = 0
        for a in sorted(A):
            local_counts[a] = self.internalNumFactoredBinaryTrees(local_counts, a)
            result += local_counts[a]
        return result % (10**9 + 7)
    
    def internalNumFactoredBinaryTrees(self, local_counts, a):
        result = 1
        for k, v in local_counts.items():
            if k * k > a:
                break
            if a % k != 0:
                continue
            b = int(a / k)
            if b in local_counts:
                result += (v * local_counts[b]) * (2 if b != k else 1)
        return result
__________________________________________________________________________________________________
sample 13048 kb submission
class Solution:
    def numFactoredBinaryTrees(self, A: List[int]) -> int:
        # init
        n = len(A)
        A.sort()
        
        # build dp
        dp = [1] * n
        
        for i in range(1,n):
            target = A[i]
            left = 0
            right = i-1
            
            while left <= right:
                prod = A[left] * A[right]
                
                if prod == target:
                    if left != right:
                        dp[i] += dp[left] * dp[right] * 2
                    else:
                        dp[i] += dp[left] * dp[right]
                    
                    left += 1
                    right -= 1
                elif prod < target:
                    left += 1
                else:
                    right -= 1
        
        # return sum
        return sum(dp) % (10**9+7)
__________________________________________________________________________________________________
