__________________________________________________________________________________________________
sample 192 ms submission
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        edges = dict()
        for arr in wall:
            index = 0
            for brick in arr:
                index += brick
                if index in edges:
                    edges[index] += 1
                else:
                    edges[index] = 1
                    
        del edges[max(edges.keys())]
        if len(edges) == 0:
            return len(wall)
        max_key = -1
        for key in edges:
            if max_key == -1 or edges[key] > edges[max_key]:
                max_key = key
        return len(wall) - edges[max_key]
__________________________________________________________________________________________________
sample 16552 kb submission
from collections import defaultdict
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        mydict = defaultdict(int)
        max_freq = 0
        for bricks in wall:
            sums = 0
            for brick in bricks[:-1]:
                sums += brick
                mydict[sums] += 1
                max_freq = max(max_freq, mydict[sums])
        return len(wall) - max_freq                    
__________________________________________________________________________________________________
