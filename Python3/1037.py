__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def isBoomerang(self, p: List[List[int]]) -> bool:
        return (p[0][0] - p[1][0]) * (p[0][1] - p[2][1]) != (p[0][0] - p[2][0]) * (p[0][1] - p[1][1])
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        if not points or len(points) < 3:
            return False
        
        a, b, c = points
        AB = (b[0] - a[0], b[1] - a[1])
        AC = (c[0] - a[0], c[1] - a[1])
        return AB[0] * AC[1] - AC[0] * AB[1]
__________________________________________________________________________________________________
