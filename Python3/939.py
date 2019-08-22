__________________________________________________________________________________________________
sample 208 ms submission
class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        n = len(points)
        nx = len(set(x for x, y in points))
        ny = len(set(y for x, y in points))
        if nx == n or ny == n:
            return 0

        p = collections.defaultdict(list)
        if nx > ny:
            for x, y in points:
                p[x].append(y)
        else:
            for x, y in points:
                p[y].append(x)

        lastx = {}
        res = float('inf')
        for x in sorted(p):
            p[x].sort()
            for i in range(len(p[x])):
                for j in range(i):
                    y1, y2 = p[x][j], p[x][i]
                    if (y1, y2) in lastx:
                        res = min(res, (x - lastx[y1, y2]) * (y2 - y1))
                    lastx[y1, y2] = x
        return res if res < float('inf') else 0
__________________________________________________________________________________________________
sample 13352 kb submission
from collections import defaultdict
class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        pool = defaultdict(set)
        for point in points:
            pool[point[0]].add(point[1])
        print(pool)
        minimum = float('inf')
        for x1 in pool:
            for x2 in pool:
                if x1 == x2: continue
                intersection = pool[x1] & pool[x2]
                if len(intersection) >= 2:
                    for y1 in intersection:
                        for y2 in intersection:
                            if y1 == y2: continue
                            minimum = min(minimum, abs(x1 - x2) * abs(y1 - y2))
        return minimum if minimum != float('inf') else 0
__________________________________________________________________________________________________
