__________________________________________________________________________________________________
sample 184 ms submission
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        t = 0
        res = 0
        hm = {}
        for i in range(len(position)):
            hm[position[i]] = speed[i]
        position.sort()
        for i in range(len(position)-1, -1, -1):
            if t == 0:
                t = (target - position[i] ) / hm[position[i]]
                res = 1
                continue
            tt = (target - position[i] ) / hm[position[i]]
            if tt > t:
                t = tt
                res += 1
        return res
__________________________________________________________________________________________________
sample 188 ms submission
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = sorted(zip(position, speed), key=lambda x:-x[0])
        ans, slowest = 0, -1
        for p, s in cars:
            t = (target - p) / s
            if t > slowest:
                slowest = t
                ans += 1
        return ans
__________________________________________________________________________________________________
