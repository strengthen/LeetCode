__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        time = 0
        x1, x2 = points[0]
        for i in range(1, len(points)):
            y1,y2 = points[i]
            time += max(abs(x1-y1), abs(x2-y2))
            x1,x2 = y1,y2
        return time
__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        curr = points[0]
        time = 0
        for point in points:
            time += max(abs(curr[0] - point[0]), abs(curr[1] - point[1]))
            curr = point
        return time
__________________________________________________________________________________________________
