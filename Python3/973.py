__________________________________________________________________________________________________
sample 676 ms submission
# from heapq import *
# class Solution:
#     def kClosest(self, points: 'List[List[int]]', K: 'int') -> 'List[List[int]]':
#         h = []
        
#         for i in points:
#             dis = i[0]**2 + i[1]**2
#             heappush(h,(dis,i))
#         res = []
#         for i in range(K):
#             res.append(heappop(h)[1])
#         return res

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        # pointsList = collections.Counter(points)
        
        return sorted(points,key = lambda x:x[0]*x[0]+x[1]*x[1])[:K]
__________________________________________________________________________________________________
sample 16772 kb submission
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        return sorted(points, key=lambda e: e[0]**2+e[1]**2)[0:K]
__________________________________________________________________________________________________
