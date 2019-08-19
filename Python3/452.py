__________________________________________________________________________________________________
sample 452 ms submission
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if len(points)<1:
            return 0
        points.sort(key=lambda x:x[1])
        count=1
        last=points[0][1]
        for i in range(1,len(points),1):
            if points[i][0]>last:
                count+=1
                last=points[i][1]
        return count
__________________________________________________________________________________________________
sample 16628 kb submission
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        if not points or not points[0]:
            return 0
        points = [(x1, x2) for x1, x2 in points]
        heapq.heapify(points)
        count = 0
        while points:
            _, minEnd = heapq.heappop(points)
            while points and points[0][0] <= minEnd:
                _, end = heapq.heappop(points)
                minEnd = min(end, minEnd)
            count += 1
        return count

    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key=lambda x: x[1])
        result, end = 0, -float('inf')
        for interval in points:
            if interval[0] > end:
                result += 1
                end = interval[1]
        return result
    
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key=lambda x: x[0])
        result, end = 0, -float('inf')
        for interval in points:
            if interval[0] > end:
                result += 1
                end = interval[1]
            else:
                end = min(end, interval[1])
        return result
__________________________________________________________________________________________________
