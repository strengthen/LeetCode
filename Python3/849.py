__________________________________________________________________________________________________
sample 128 ms submission
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        right, left = 0, 0
        while seats[left]==0:
            left+=1
        idx = len(seats)-1
        while seats[idx]==0:
            idx -= 1
            right +=1
        
        max_, zero = 0, 0
        
        for i in seats:
            if i == 0:
                zero += 1
                if zero > max_:
                    max_ = zero
            else:
                zero = 0
        return max([left, right, int(max_/2+0.5)])
__________________________________________________________________________________________________
sample 13144 kb submission
class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        first, last, prev = -1, -1, -1
        ans = 0
        for i in range(len(seats)):
            if seats[i] != 1:
                continue
                
            if prev != -1:
                ans = max(ans, (i - prev) // 2)
            elif first == -1:
                first = i
            if last < i:
                last = i
                
            prev = i
                
        return max(ans, max(first, len(seats) - 1 - last))
__________________________________________________________________________________________________
