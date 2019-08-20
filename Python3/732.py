__________________________________________________________________________________________________
sample 180 ms submission
class MyCalendarThree:

    def __init__(self):
        self.X = [-1, int(1e9)]
        self.track = [0, 0]
        self.K = 0

    def book(self, start: int, end: int) -> int:
        def index(t):
            i = bisect.bisect_left(self.X, t)
            if self.X[i] != t:
                self.X.insert(i, t)
                self.track.insert(i, self.track[i - 1])
            return i
        i, j = index(start), index(end)
        self.track[i:j] = [k + 1 for k in self.track[i:j]]
        self.K = max(self.K, max(self.track[i:j]))
        return self.K
__________________________________________________________________________________________________
sample 188 ms submission
class MyCalendarThree:

    def __init__(self):
        self.events = []
        self.times = collections.defaultdict(int)
        self.max_time = 0
        

    def book(self, start: int, end: int) -> int:
        i = bisect.bisect_left(self.events, start)
        if(start not in self.times):
            self.times[start] = self.times[self.events[i-1]] if(i) else 0
            self.events[i:i] = [start]
        
        j = bisect.bisect_left(self.events, end)
        if(end not in self.times):
            self.times[end] = self.times[self.events[j-1]]
            self.events[j:j] = [end]
        
        for point in self.events[i:j]:
            self.times[point] += 1
            self.max_time = max(self.max_time, self.times[point])
        return self.max_time
__________________________________________________________________________________________________
