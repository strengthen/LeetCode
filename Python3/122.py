__________________________________________________________________________________________________
sample 52 ms submission
import sys


class Solution:
    
    def maxProfit(self, prices: List[int]) -> int:
        
        max_profit = 0
        
        if not prices:
            return 0
        
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                max_profit += prices[i] - prices[i - 1]
        
        return max_profit
__________________________________________________________________________________________________
sample 13656 kb submission
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0
        
        total_profit = 0
        current_price = float("inf")
        
        for price in prices:
            profit = price - current_price
            if profit > 0:
                total_profit += profit
            current_price = price
            
        return total_profit
__________________________________________________________________________________________________
