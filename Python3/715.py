__________________________________________________________________________________________________
sample 432 ms submission
import bisect
class RangeModule:

    def __init__(self):
        self.track = []

    def addRange(self, left, right):
        start = bisect.bisect_left(self.track, left)
        end = bisect.bisect_right(self.track, right)
        
        subtrack = []
        if start % 2 == 0:
            subtrack.append(left)
        if end % 2 == 0:
            subtrack.append(right)
            
        self.track[start:end] = subtrack

    def removeRange(self, left, right):
        start = bisect.bisect_left(self.track, left)
        end = bisect.bisect_right(self.track, right)
        
        subtrack = []
        if start % 2 == 1:
            subtrack.append(left)
        if end % 2 == 1:
            subtrack.append(right)
			
        self.track[start:end] = subtrack
		
    def queryRange(self, left, right):
        start = bisect.bisect_right(self.track, left)
        end = bisect.bisect_left(self.track, right)
		
        return start == end and start % 2 == 1

# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)
__________________________________________________________________________________________________
sample 436 ms submission
import bisect

# https://leetcode.com/problems/range-module/discuss/244194/Python-solution-using-bisect_left-bisect_right-with-explanation

class RangeModule: 

    def __init__(self):
        self.track = list()        
        
        
    def addRange(self, left: int, right: int) -> None:
        start = bisect.bisect_left(self.track, left)
        end = bisect.bisect_right(self.track, right)
        
        # print("track", self.track)
        
        subtrack = []
        if start % 2 == 0:
            subtrack.append(left)
        if end % 2 == 0:
            subtrack.append(right)
			
        self.track[start:end] = subtrack
        
        # print("Addrange")
        # print("start, end, subratck, track")
        # print(start, end, subtrack, self.track)
        

    def queryRange(self, left: int, right: int) -> bool:
        start = bisect.bisect_right(self.track, left)
        end = bisect.bisect_left(self.track, right)
		
        # print("queryRange")
        # print("left, right", left, right)
        # print("track", self.track)
        # print("startidx, endidx", start, end)
        return start == end and start % 2 == 1

    def removeRange(self, left: int, right: int) -> None:
        start = bisect.bisect_left(self.track, left)
        end = bisect.bisect_right(self.track, right)
        
        # print("track", self.track)
        
        subtrack = []
        if start % 2 == 1:
            subtrack.append(left)
        if end % 2 == 1:
            subtrack.append(right)
			
        self.track[start:end] = subtrack
        
        # print("removeRange")
        # print("start, end, subratck, track")
        # print(start, end, subtrack, self.track)
        

# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)
__________________________________________________________________________________________________
