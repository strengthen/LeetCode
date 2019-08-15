__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        piles = []
        for n in nums:
            pile = bisect.bisect_left(piles, n)
            if pile == len(piles):
                piles.append(n)
            else:
                piles[pile] = n
        return len(piles)
__________________________________________________________________________________________________
sample 13048 kb submission
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        dp = [1]
        for i in range(1, len(nums)):
            max_so_far = 1
            for j in range(0, i):
                if nums[i] > nums[j]:
                    max_so_far = max(max_so_far, dp[j] + 1)
            dp.append(max_so_far)
        return max(dp)
__________________________________________________________________________________________________
