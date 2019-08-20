__________________________________________________________________________________________________
sample 676 ms submission
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        min_price = float('inf')
        ans = 0
        for price in prices:
            if price + fee < min_price:
                min_price = price + fee
            elif price > min_price:
                ans += price - min_price
                min_price = price
                
        return ans
__________________________________________________________________________________________________
sample 17828 kb submission
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        
        dp_0 = 0
        dp_1 = -float('inf')
        
        for p in prices:
            dp_0 = max(dp_0, p + dp_1)
            dp_1 = max(dp_1, -p - fee + dp_0)
            
        return dp_0
__________________________________________________________________________________________________
