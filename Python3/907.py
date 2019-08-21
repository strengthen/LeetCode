__________________________________________________________________________________________________
sample 468 ms submission
class Solution:
    def sumSubarrayMins(self, A: List[int]) -> int:
        A = [0] + A + [0]
        stack = []
        res = 0
        
        for hi, num in enumerate(A):
            while stack and A[stack[-1]] > num:
                idx = stack.pop()
                lo = stack[-1]
                res += A[idx] * (idx - lo) * (hi - idx)
            stack.append(hi)
        
        return res % (10 ** 9 + 7)
__________________________________________________________________________________________________
sample 16040 kb submission
class Solution:
    def sumSubarrayMins(self, A):
        MOD = 10**9 + 7

        stack = []
        ans = dot = 0
        for j, y in enumerate(A):
            # Add all answers for subarrays [i, j], i <= j
            count = 1
            while stack and stack[-1][0] >= y:
                x, c = stack.pop()
                count += c
                dot -= x * c

            stack.append((y, count))
            dot += y * count
            ans += dot
        return ans % MOD
__________________________________________________________________________________________________
