__________________________________________________________________________________________________
sample 776 ms submission
class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        import heapq
        totalLen = 0
        heap = []
        for t, d in sorted(courses, key=lambda x: x[1]):
            if totalLen + t <= d:
                totalLen += t
                heapq.heappush(heap, -t)
            elif heap and t < -heap[0]:
                totalLen += t + heapq.heappop(heap)
                heapq.heappush(heap, -t)

        return len(heap)
__________________________________________________________________________________________________
sample 16624 kb submission
class Solution:
    def scheduleCourse(self, courses):
        courses.sort(key=lambda x:x[1])
        he,s=[],0
        heapq.heappush(he,0)
        for t,d in courses:
            if s+t>d:
                if t+he[0]<0:
                    s+=t+he[0]
                    heapq.heappushpop(he,-t)
            else:
                s+=t
                heapq.heappush(he,-t)
        return len(he)-1
__________________________________________________________________________________________________
