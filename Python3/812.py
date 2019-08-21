__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        points = self.boundary(points)
        m = 0
        for p1,p2,p3 in itertools.permutations(points, 3):
            a = self.calc_area(p1,p2,p3)
            if a > m:
                m = a
        return m
    
    def boundary(self, points):
        points = sorted(points, key=lambda x: (x[0], x[1]))
        def cross(o,a,b): 
            return (o[0] - a[0]) * (o[1] - b[1]) - (o[1] - a[1]) * (o[0] - b[0])
        lower, upper = [],[]
        for p in points:
            while len(lower) >=2 and cross(lower[-2], lower[-1], p)<0: 
                lower.pop()
            lower.append(tuple(p))
            
        for p in reversed(points):
            while len(upper) >=2 and cross(upper[-2], upper[-1], p)<0: 
                upper.pop()
            upper.append(tuple(p))
        return list(set(lower+upper))
    
    def calc_area(self, a,b,c):
        return abs(a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1])) / 2
__________________________________________________________________________________________________
sample 13120 kb submission
class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        res = 0
        N = len(points)
        for i in range(N - 2):
            for j in range(i + 1, N - 1):
                for k in range(i + 2, N):
                    (x1, y1), (x2, y2), (x3, y3) = points[i], points[j], points[k]
                    res = max(res, 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)))
        return res
__________________________________________________________________________________________________
