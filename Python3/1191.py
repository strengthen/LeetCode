__________________________________________________________________________________________________
sample 364 ms submission
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        if k <= 2:
            dp = [0]
            for a in arr * k:
                if dp[-1] <= 0:
                    dp.append(a)
                else:
                    dp.append(dp[-1] + a)
            return max(dp)
        SUM, dp = sum(arr), [0]
        for a in arr * 2:
            if dp[-1] <= 0:
                dp.append(a)
            else:
                dp.append(dp[-1] + a)
        return max(dp) % (10 ** 9 + 7) if SUM <= 0 else (max(dp) + (k - 2) * SUM) % (10 ** 9 + 7)
__________________________________________________________________________________________________
sample 412 ms submission
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        def helper(arr):
            mx = 0
            cur = 0
            for num in arr:
                cur = max(cur + num, num)
                mx = max(cur, mx)
            return mx
        if k >= 2:
            ans = helper(arr + arr)
            total = sum(arr)
            if total > 0:
                ans += total * (k - 2)
            return ans % 1000000007
        else:
            return helper(arr) % 1000000007
__________________________________________________________________________________________________
