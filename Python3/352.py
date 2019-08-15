__________________________________________________________________________________________________
sample 176 ms submission
class SummaryRanges:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lists = []

    def addNum(self, val: int) -> None:
        index = self.binarySearch(val)
        if index == None: return
        # insert the interval
        pos = index
        self.lists.insert(pos, [val, val])
        
        # merge with next interval
        if pos + 1 < len(self.lists) and val == self.lists[pos + 1][0] - 1:
            self.lists[pos][1] = self.lists[pos + 1][1]
            self.lists[pos + 1:pos + 2] = []
            
        # merge with previous interval
        if pos - 1 >= 0 and val == self.lists[pos - 1][1] + 1:
            self.lists[pos - 1][1] = self.lists[pos][1]
            self.lists[pos:pos + 1] = []

    def getIntervals(self) -> List[List[int]]:
        return self.lists
    
    def binarySearch(self, target):
        lo, hi = 0, len(self.lists) - 1
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            elem = self.lists[mid]
            if elem[0] <= target <= elem[1]:
                return
            elif elem[0] > target:
                hi = mid - 1
            else:
                lo = mid + 1
        return min(lo, hi) + 1

# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
__________________________________________________________________________________________________
sample 17684 kb submission
class SummaryRanges:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.intervals = []

    def addNum(self, val: int) -> None:
        if not self.intervals:
            self.intervals.append([val, val])
        else:
            pos = 0
            for s, e in self.intervals:
                if val > e + 1:
                    pos += 1
                    continue
                elif val < s - 1:
                    self.intervals = self.intervals[:pos] + [[val, val]] + self.intervals[pos:]
                elif val == s - 1:
                    self.intervals[pos][0] = val
                elif val == e + 1:
                    self.intervals[pos][1] = val
                    if pos+1<len(self.intervals) and (val == self.intervals[pos + 1][0] or val + 1 == self.intervals[pos + 1][0]):
                        tmp = self.intervals[pos][0]
                        self.intervals = self.intervals[:pos] + self.intervals[pos + 1:]
                        self.intervals[pos][0] = tmp
                return
            self.intervals += [[val, val]]

    def getIntervals(self) -> list:
        return self.intervals



# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(val)
# param_2 = obj.getIntervals()
__________________________________________________________________________________________________
