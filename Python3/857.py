__________________________________________________________________________________________________
sample 208 ms submission
from heapq import heapify, heappushpop

class Solution:
  def mincostToHireWorkers(
    self, 
    quality: List[int], 
    wage: List[int], 
    K: int
  ) -> float:
    workers = sorted(zip(quality, wage), key=lambda x: x[1]/x[0])
    quality_heap = [-w[0] for w in workers[:K]]
    heapify(quality_heap)
    
    quality_sum = -sum(quality_heap)
    cost = quality_sum / workers[K-1][0] * workers[K-1][1]
    min_cost = cost
    
    for k in range(K, len(quality)):
      if workers[k][0] + quality_heap[0] < 0:
        quality_sum += heappushpop(quality_heap, -workers[k][0]) + workers[k][0]
        cost = quality_sum / workers[k][0] * workers[k][1]
        min_cost = min(cost, min_cost)
    return min_cost
__________________________________________________________________________________________________
sample 15140 kb submission
import heapq

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        n = len(quality)
        rate = []
        for q, w in zip(quality, wage):
            rate.append(w/q)
        
        rateindex = sorted(range(n), key = lambda i: rate[i])
        
        # use max heap to store the min K quality person
        pq = minKQuality = []
        for i in range(K):
            pq.append( -quality[rateindex[i]] ) # use - to change min heap to max heap
        heapq.heapify(pq)
        
        minQuality =  sum(pq) * (-1)
        minWage = rate[rateindex[K-1]] * minQuality
        for i in range(K, n):
            index = rateindex[i]
            currate = rate[index]
            outquality = - heapq.heappushpop(pq, -quality[index])
            minQuality += (quality[index] - outquality)
            minWage = min(minWage, minQuality * currate )
            
        return minWage
__________________________________________________________________________________________________
