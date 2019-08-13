__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        def check(start, end):

            prof2 = 0
            min2 = float("inf")

            for j in range(0, start):
                if (prices[j] <= min2):
                    min2 = prices[j]
                if (prices[j] - min2 > prof2):
                    prof2 = prices[j] - min2

            min2 = float("inf")

            for j in range(end + 1, len(prices)):
                if (prices[j] <= min2):
                    min2 = prices[j]
                if (prices[j] - min2 > prof2):
                    prof2 = prices[j] - min2

            return prof2

        min1 = float("inf")

        marker = 0
        start = 0
        end = 0

        prof1 = 0
        max_prof = 0

        for i in range(len(prices)):
            if (prices[i] <= min1):
                min1 = prices[i]
                marker = i
            if (prices[i] - min1 > prof1):
                prof1 = prices[i] - min1
                start = marker
                end = i
                prof2 = check(start, end)
                if (prof2 + prof1) > max_prof:
                    max_prof = prof1 + prof2

        return max_prof
__________________________________________________________________________________________________
sample 13868 kb submission
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit1 =0; profit2 =0
        buy1 = float("Inf"); buy2 = float("Inf")
        
        for price in prices:
            profit2 = max(profit2, price - buy2)
            buy2 = min(buy2, price - profit1)
            profit1 = max(profit1, price - buy1)
            buy1 = min(buy1, price)
        
        return profit2        
__________________________________________________________________________________________________
