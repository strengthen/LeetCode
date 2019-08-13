__________________________________________________________________________________________________
sample 52 ms submission
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stackList= []
        self.stackMin = []
        

    def push(self, x: int) -> None:
        self.stackList.append(x)
        
        if len(self.stackMin) == 0:
            self.stackMin.append(x)
        elif x <= self.stackMin[-1]:
            self.stackMin.append(x)

    def pop(self) -> None:
        if self.stackList.pop() == self.stackMin[-1]: 
            self.stackMin.pop()
        

    def top(self) -> int:
        return self.stackList[-1]
        

    def getMin(self) -> int:
        return self.stackMin[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
__________________________________________________________________________________________________
sample 16384 kb submission
class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min = []

    def push(self, x: int) -> None:
        self.min.append(x if len(self.stack) == 0 else min(self.min[-1], x))
        self.stack.append(x)

    def pop(self) -> None:
        self.stack.pop()
        self.min.pop()

    def top(self) -> int:
        return self.stack[-1]
    
    def getMin(self) -> int:
        return self.min[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
__________________________________________________________________________________________________
