__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        if not nums:
            return 0

        sell = [0] * len(nums)
        buy = [0] * len(nums)
        buy[0] = -nums[0]
        #if len(nums) >= 2:
        #    buy[1] = max(buy[0], -nums[1])
        
        for i in range(1, len(nums)):
            buy[i] =  max(buy[i - 1], sell[i - 2] - nums[i])
            sell[i] = max(sell[i - 1], buy[i - 1] + nums[i])

        return sell[-1]
__________________________________________________________________________________________________
sample 13124 kb submission
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        sell=[0 for i in range(len(prices))]
        buy=[0 for i in range(len(prices))]
        buy[0]=-prices[0]
        for i in range(1,len(prices)):
            sell[i]=max(sell[i-1],buy[i-1]+prices[i])
            buy[i]=max(buy[i-1],sell[i-2]-prices[i] if i>=2 else -prices[i])
        return sell[-1]
__________________________________________________________________________________________________
