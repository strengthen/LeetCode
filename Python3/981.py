__________________________________________________________________________________________________
sample 668 ms submission
class TimeMap:
    def __init__(self):
        self._times = collections.defaultdict(list)
        self._values = collections.defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self._times[key].append(timestamp)
        self._values[key].append(value)

    def get(self, key: str, timestamp: int) -> str:
        if key in self._times:
            times = self._times[key]
            l, r = 0, len(times)-1
            if times[l] <= timestamp:
                if times[r] > timestamp:
                    while l <= r:
                        mid = (l + r) // 2
                        if times[mid] == timestamp: l = r = mid
                        if times[mid] <= timestamp: l = mid + 1
                        else: r = mid - 1
                return self._values[key][r]
        return ""
__________________________________________________________________________________________________
sample 56800 kb submission
class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.ts = collections.defaultdict(list)
        self.val = collections.defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.ts[key].append(timestamp)
        self.val[key].append(value)
        
    def get(self, key: str, timestamp: int) -> str:
        if not self.ts[key]: return ""
        idx = bisect.bisect_right(self.ts[key], timestamp)
        if idx == 0: return ""
        return self.val[key][idx-1]
        
# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
__________________________________________________________________________________________________
