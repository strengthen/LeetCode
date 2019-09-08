__________________________________________________________________________________________________
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        l1 = sum(distance[i] for i in range(start))
        l2 = sum(distance[i] for i in range(destination))
        tot = sum(distance)
        
        cn = max (l1, l2) - min (l1, l2)
        return min (cn, tot - cn)
__________________________________________________________________________________________________

__________________________________________________________________________________________________
