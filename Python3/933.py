__________________________________________________________________________________________________
sample 312 ms submission
class RecentCounter:

    def __init__(self):
        self.p = collections.deque()        

    def ping(self, t):
        self.p.append(t)
        while self.p[0] < t - 3000:
            self.p.popleft()
        return len(self.p)
__________________________________________________________________________________________________
sample 17708 kb submission
import bisect

class RecentCounter:

    def __init__(self):
        self.pings = []

    def ping(self, t: int) -> int:
        self.pings.append(t)
        self.pings = self.pings[bisect.bisect_left(self.pings, t-3000):]
        return len(self.pings)

# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
__________________________________________________________________________________________________
