__________________________________________________________________________________________________
sample 24 ms submission
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []
        
    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.q.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns
        """
        f = self.q[0]
        del self.q[0]
        return f
        
    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.q[0]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.q) == 0
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
__________________________________________________________________________________________________
sample 12944 kb submission
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack=[]

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        return self.stack.pop(0)

    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.stack[0]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if not self.stack:
            return True
        return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
__________________________________________________________________________________________________
