__________________________________________________________________________________________________
sample 408 ms submission
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnts = collections.Counter(tasks)
        max_cnts = max(cnts.values())
        max_n = len([task for task in cnts if cnts[task]==max_cnts])
        return max(len(tasks), (max_cnts - 1)*(n+1) + max_n)
__________________________________________________________________________________________________
sample 13132 kb submission
from collections import Counter 
import heapq 

class Solution:
    def leastInterval(self, tasks, n):
        curr_time = 0
        h = []
        
        for k,v in Counter(tasks).items():
            heapq.heappush(h, (-1*v, k))
            
        while h:
            i = 0
            temp = [] 
            while i <= n:
                curr_time += 1
                if h:
                    x,y = heapq.heappop(h)
                    if x != -1: # not the last one
                        temp.append((x+1,y)) # +1, means count - 1 
                 
                # no values 
                if not h and not temp:
                    break
                    
                else:
                    i += 1
            for item in temp:
                heapq.heappush(h, item)
                
        return curr_time
__________________________________________________________________________________________________
