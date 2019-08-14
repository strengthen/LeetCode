__________________________________________________________________________________________________
sample 48 ms submission
import heapq as hq
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if n == 0 or k == 0:
            return 0
        
        if k > n // 2:
            # Equivalent to as many as transactions you want
            maxp = 0
            for i in range(1, n):
                if prices[i] > prices[i - 1]:
                    maxp += prices[i] - prices[i - 1]
            
            return maxp
        else:
            # dp = [[0] * n for _ in range(k)]
            # for kk in range(k):
            #     prevMin = prices[0] # initially 
            #     for i in range(1, n):
            #         dp[kk][i] = max(dp[kk][i - 1], prices[i] - prevMin)
            #         if kk > 0:
            #             # prices[i] - prices[j] + dp[kk - 1][j - 1] for j in range(i - 1)
            #             # --> prices[i] - (prices[j] - dp[kk - 1][j - 1])
            #             # keep updating the later term, so it remains minimum
            #             prevMin = min(prevMin, prices[i] - dp[kk - 1][i - 1])
            #         else:
            #             prevMin = min(prevMin, prices[i])
            # 
            # return dp[-1][-1]
            
            lo, hi = 0, 0
            profits, trans = [], []
            while True:
                # Find segments with positive slope --> transaction making profits
                # Be aware of horizontal line
                lo = hi
                while lo < n - 1 and prices[lo + 1] <= prices[lo]:
                    lo += 1
                hi = lo
                while hi < n - 1 and prices[hi + 1] >= prices[hi]:
                    hi += 1
                
                if lo == hi:
                    break
                
                while trans:
                    if prices[lo] < prices[trans[-1][0]]:
                        x, y = trans.pop()
                        profits.append(prices[x] - prices[y]) # Push negative value so minHeap -> maxHeap
                    elif prices[hi] > prices[trans[-1][1]]:
                        x, y = trans.pop()
                        profits.append(prices[lo] - prices[y])
                        lo = x
                    else:
                        break
                
                trans.append((lo, hi))
            
            while trans:
                x, y = trans.pop()
                profits.append(prices[x] - prices[y])
            
            hq.heapify(profits)
            maxp = 0
            while profits and k > 0:
                maxp += hq.heappop(profits)
                k -= 1
            
            return -maxp    
__________________________________________________________________________________________________
sample 13556 kb submission
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if k >= n // 2:
            return sum(x - y for x, y in zip(prices[1:], prices[:-1]) if x > y)
        
        profits = [0]*n
        for _ in range(k):
            preprofit = 0
            for i in range(1,n):
                p = prices[i] - prices[i-1]
                curprofit = max(preprofit + p, profits[i])
                profits[i] = max(curprofit, profits[i-1])
                preprofit = curprofit   # not profits[i]
        
        return profits[-1]
    
    def maxProfit(self, k, prices):
        n = len(prices)
        if k >= n//2:
            return sum(x-y for x,y in zip(prices[1:], prices[:-1]) if x > y)
        
        #global_max = [[0]*n for _ in range(k+1)]
        local_max = [0]*n
        for i in range(1, k+1):
            #local_max = [0]*n
            preprofit = 0
            for j in range(1, n):
                profit = prices[j] - prices[j-1]
                curr_profit = max(local_max[j], preprofit + profit)
                local_max[j] = max(local_max[j-1], curr_profit)
                preprofit = curr_profit
        
        return local_max[-1]
__________________________________________________________________________________________________
