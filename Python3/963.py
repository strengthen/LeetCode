__________________________________________________________________________________________________
sample 80 ms submission
import itertools
import math
class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        points = [complex(*z) for z in points]
        table = collections.defaultdict(list)
        for P, Q in itertools.combinations(points, 2):
            center = (P + Q) / 2
            radius = abs(center - P)
            table[center, radius].append(P)
        
        minArea = math.inf
        for (center, radius), candidates in table.items():
            for P, Q in itertools.combinations(candidates, 2):
                minArea = min(minArea, abs(P - Q) * abs(P - (center*2 - Q)))
        return minArea if minArea != math.inf else 0
__________________________________________________________________________________________________
sample 13620 kb submission
class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        d = collections.defaultdict(list)
        res = float("inf")
        for i in range(len(points)):
            for j in range(i + 1, len(points)):
                # print(points[i], points[j])
                key = ((points[i][0] + points[j][0]) / 2, (points[i][1] + points[j][1]) / 2, ((points[i][0] - points[j][0]) ** 2 + (points[i][1] - points[j][1]) ** 2) ** 0.5)
                if key in d:
                    for cur in d[key]:
                        res = min(res, ((points[i][0] - cur[0][0]) ** 2 + (points[i][1] - cur[0][1]) ** 2) ** 0.5 * ((points[i][0] - cur[1][0]) ** 2 + (points[i][1] - cur[1][1]) ** 2) ** 0.5)
                d[key].append((points[i], points[j]))
                # print(d)
        return res if res != float("inf") else 0.0
__________________________________________________________________________________________________
