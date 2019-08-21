__________________________________________________________________________________________________
sample 124 ms submission
import heapq
class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        cnt = prevdis = 0
        heap = []
        stations.append((target, 0))
        for (dis, fuel) in stations:
            startFuel = startFuel - dis + prevdis
            prevdis = dis
            while startFuel < 0: 
                if len(heap) == 0 : return -1
                cnt += 1
                startFuel -= heapq.heappop(heap)
            heapq.heappush(heap, -fuel)
        return cnt
__________________________________________________________________________________________________
sample 128 ms submission
class Solution:
    def minRefuelStops(self, target, startFuel, stations):
        stations.append([target, float('inf')])
        max_hp = []
        tank = startFuel  # tank is left gas for car
        prev = 0
        ans = 0
        for s in stations:
            tank -= s[0] - prev  # cosume  (s[0]-prev) L gas
            while tank < 0 and max_hp:
                tank += -heapq.heappop(max_hp)
                ans += 1
            if tank < 0: return -1
            heapq.heappush(max_hp, -s[1])
            prev = s[0]
        return ans                
__________________________________________________________________________________________________
