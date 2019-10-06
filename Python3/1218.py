__________________________________________________________________________________________________
sample 660 ms submission
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        
        dp = {}
        
        for i in range(len(arr) - 1, -1, -1):
            dp[arr[i]] = dp.get(arr[i] + difference, 0) + 1
        
        return max(dp.values())
__________________________________________________________________________________________________
sample 720 ms submission
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        n, ans = len(arr), {}
        for a in arr:
            ans[a] = max(ans.get(a, 0), ans.get(a - difference, 0) + 1)
        return max(ans.values())
__________________________________________________________________________________________________
sample 752 ms submission
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        dp = collections.Counter()
        for num in arr:
            if (num - difference) in dp:
                dp[num] = max(dp[num], dp[num - difference] + 1)
            if num not in dp:
                dp[num] = 1
        return max(dp.values())
