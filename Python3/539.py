__________________________________________________________________________________________________
sample 64 ms submission
from itertools import cycle


class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        if len(timePoints) >= 1440:
            return 0
        
        s = set()
        for time in timePoints:
            if time in s:
                return 0
            s.add(time)
        timePoints = sorted(s)

        def time_diff(a, b):
            h1, m1 = a.split(':')
            h2, m2 = b.split(':')
            secs = abs(60 * (int(h1) - int(h2)) + int(m1) - int(m2))
            return min(secs, 1440 - secs)

        next_iter = cycle(timePoints)
        next(next_iter)
        return min(
            time_diff(nxt, prev)
            for prev, nxt in zip(timePoints, next_iter)
        )
__________________________________________________________________________________________________
sample 68 ms submission
from typing import List


class Solution:

    MINS_IN_HOUR = 60
    HOURS_IN_DAY = 24
    MINS_IN_DAY = HOURS_IN_DAY * MINS_IN_HOUR

    def findMinDifference(self, times: List[str]) -> int:
        all_mins = set()
        for time in times:
            mins = self.get_mins(time)
            if mins in all_mins:
                return 0
            all_mins.add(mins)
        result = self.MINS_IN_DAY
        prev, first = -1, -1
        for t in range(self.MINS_IN_DAY):
            if t not in all_mins:
                continue
            if prev == -1:
                prev = first = t 
            else:
                result = min(result, t-prev)
                prev = t
        over_midnight = self.MINS_IN_DAY - prev + first
        result = min(result, over_midnight)
        return result

    def get_mins(self, time: str) -> int:
        hours, mins = time.split(":")
        return int(hours) * self.MINS_IN_HOUR + int(mins)
__________________________________________________________________________________________________
