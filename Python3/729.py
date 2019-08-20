__________________________________________________________________________________________________
sample 220 ms submission
from bisect import bisect_right
class MyCalendar:    

    def __init__(self):
        self.intervals = [[-2, -1], [10 ** 9 + 1, 10 ** 9 + 2]]        

    def book(self, start: int, end: int) -> bool:
        curr = [start, 10 ** 9 + 1]
        index = bisect_right(self.intervals, curr)
        if(self.intervals[index - 1][1] > start or 
           self.intervals[index][0] < end):
            return False
        self.intervals.insert(index, [start, end])
        return True

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
__________________________________________________________________________________________________
sample 13400 kb submission
class MyCalendar:

    def __init__(self):
        self.intervals = []

    def book(self, start: int, end: int) -> bool:
        if not self.intervals or end <= self.intervals[0][0]:
            self.intervals = [[start, end]] + self.intervals
            return True
        
        if self.intervals[-1][1] <= start:
            self.intervals.append([start, end])
            return True
            
        for ind in range(1, len(self.intervals)):
            i = self.intervals[ind]
            prev = self.intervals[ind - 1]
            if start >= prev[1] and end <= i[0]:
                self.intervals.insert(ind, [start, end])
                return True
            
        return False


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
__________________________________________________________________________________________________
