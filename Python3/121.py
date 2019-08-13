__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float("inf")
        max_profit = 0
        for price in prices:
            if price < min_price:
                min_price = price
            if price - min_price > max_profit:
                max_profit = price - min_price
        return max_profit        
__________________________________________________________________________________________________
sample 13708 kb submission
import sys

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        if len(prices) == 0:
            return 0
        
        max_diff = 0
        max_price = prices[-1]
        
        for i in range(len(prices))[::-1]:
            if prices[i] > max_price:
                max_price = prices[i]
            else:
                max_diff = max(max_diff, max_price - prices[i])
        
        return max_diff
__________________________________________________________________________________________________
