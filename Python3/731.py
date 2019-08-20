__________________________________________________________________________________________________
sample 208 ms submission
import bisect

class MyCalendarTwo:

    def __init__(self):
        self.one = []
        self.two = []

    def is_valid(self, start, end):
        if end <= start:
            return -1

        i = bisect.bisect_right(self.two, start)
        if i % 2:
            return -1

        j = bisect.bisect_left(self.two, end)
        if i != j:
            return -1

        return i
        

    def book(self, start: int, end: int) -> bool:

        t = self.is_valid(start, end)
        if t == -1:
            return False

        i = bisect.bisect_right(self.one, start)
        j = bisect.bisect_left(self.one, end)

        if i % 2:
            if j % 2:
                self.two[t:t] = [start] + self.one[i:j] + [end]
                self.one[i:j] = []
            else:
                self.two[t:t] = [start] + self.one[i:j]
                self.one[i:j] = [end]
        else:
            if j % 2:
                self.two[t:t] = self.one[i:j] + [end]
                self.one[i:j] = [start]
            else:
                self.two[t:t] = self.one[i:j]
                self.one[i:j] = [start, end]

        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
__________________________________________________________________________________________________
sample 13336 kb submission
class MyCalendarTwo:
    class Node:
        def __init__(self, start, end):
            self.start = start
            self.end = end
            self.left = self.right = None
        
        def contains(self, node):
            if node.start >= self.end:
                if self.right is None:
                    return False
                return self.right.contains(node)
            elif node.end <= self.start:
                if self.left is None:
                    return False
                return self.left.contains(node)
            return True
        
        def insert(self, node):
            if node.start >= self.end:
                if self.right is None:
                    self.right = node
                    return True
                return self.right.insert(node)
            elif node.end <= self.start:
                if self.left is None:
                    self.left = node
                    return True
                return self.left.insert(node)
            return False
        
    def __init__(self):
        self.bookings = []
        self.double_bookings = None

    def book(self, start: int, end: int) -> bool:
        curr = (start, end)
        def overlap(b1, b2):
            if b1[1] <= b2[0] or b2[1] <= b1[0]:
                return False
            return True
        if self.double_bookings is not None:
            if self.double_bookings.contains(self.Node(start, end)):
                return False
        for b in self.bookings:
            if overlap(b, curr):
                overlap_start = max(curr[0], b[0])
                overlap_end = min(curr[1], b[1])
                node = self.Node(overlap_start, overlap_end)
                if self.double_bookings is None:
                    self.double_bookings = node
                else:
                    if not self.double_bookings.insert(node):
                        return False
        self.bookings.append(curr)
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
__________________________________________________________________________________________________
