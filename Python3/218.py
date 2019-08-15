__________________________________________________________________________________________________
sample 112 ms submission
import heapq
class Solution:
    def getSkyline(self, buildings):
        if not buildings:
            return []
        last = heapq.heappop(buildings)
        skyline = []
        S, E, H = 0, 1, 2
        while buildings:
            building = heapq.heappop(buildings)
            
            if building[S] >= last[E]: # no overlap
                if last[H] == building[H]:
                    last[E] = building[E]
                else:
                    skyline.append([last[S], last[H]])
                    if building[S] > last[E]:
                        skyline.append([last[E], 0])
                    last = building
                
            elif building[H] == last[H]: # same height
                last[E] = max(last[E], building[E])
                
            elif building[H] > last[H]:
                if building[E] < last[E]:         
                    heapq.heappush(buildings, [building[E], last[E], last[H]])
                if building[S] > last[S]:
                    skyline.append([last[S], last[H]])
                    last = building
                else:
                    last[E], last[H] = building[E], building[H]
                    
            elif building[E] > last[E]: # less than ->  partition only when building is stretched further out
                building[S] = last[E]
                heapq.heappush(buildings, building)
        
        return skyline + [[last[S], last[H]], [last[E], 0]]
__________________________________________________________________________________________________
sample 16844 kb submission
# The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

# For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

# The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

# For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
class Solution:
    def arrangeSkyline(self, skyline):
        ans = [None] * len(skyline)
        ans[0] = skyline[0]
        i, j = 1, 1
        while i < len(skyline):
            if skyline[i][0] == ans[j-1][0]:
                j -= 1
                ans[j] = (ans[j][0], max(skyline[i][1], ans[j][1]))
            elif skyline[i][1] == ans[j-1][1]:
                j -= 1
            else:
                ans[j] = skyline[i]
            i, j = i+1, j+1
        return ans[:j]
                
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        heap = []
        for i, (left, right, height) in enumerate(buildings):
            heapq.heappush(heap, (-height, i))
            
        ans = []
        while len(heap):
            _, i = heapq.heappop(heap)
            left, right, height = buildings[i]
            
            if ans == []:
                ans = [(-1, 0), (left, height), (right, 0), (0x7FFFFFFF, 0)]
                continue
                
            left_i = None
            right_i = None
            for i, (x, y) in list(enumerate(ans))[1:]:
                if x >= left and ans[i-1][0] < left and ans[i-1][1] == 0:
                    left_i = i
                if x >= right and ans[i-1][0] < right and ans[i-1][1] == 0:
                    right_i = i
                if x > right:
                    break

            if right_i == left_i and right_i is not None:
                ans = ans[:right_i] + [(left, height), (right, 0)] + ans[right_i:]
                continue
                
            if right_i is not None:
                ans[right_i-1] = (ans[right_i-1][0], height)
                ans = ans[:right_i] + [(right, 0)] + ans[right_i:]
                
            if left_i is not None:
                ans = ans[:left_i] + [(left, height)] + ans[left_i:]
                
            for i, (x, y) in list(enumerate(ans))[1:]:
                if left <= x and x < right and y == 0:
                    ans[i] = (x, height)
                
            ans = self.arrangeSkyline(ans) + [ans[-1]]
            
        return self.arrangeSkyline(ans)[1:] if ans != [] else []
__________________________________________________________________________________________________
