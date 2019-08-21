__________________________________________________________________________________________________
sample 480 ms submission
class StockSpanner:

    def __init__(self):
        self.stack = []

    def next(self, price: int) -> int:
        weight = 1
        while self.stack and self.stack[-1][0] <= price:
            weight += self.stack.pop()[1]
        self.stack.append((price, weight))
        return weight


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
__________________________________________________________________________________________________
sample 488 ms submission
class StockSpanner:

    def __init__(self):
        self.stk = []
    
    def next(self, price: int) -> int:
        cnt = 1
        while self.stk and self.stk[-1][0] <= price:
            cnt += self.stk.pop()[1]
        self.stk.append((price, cnt))
        return cnt
###100 80 60 70 60 75 85
###(100,1)(85, 6)
 

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
__________________________________________________________________________________________________
