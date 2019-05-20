__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        import bisect
        
        stones = sorted(stones)
        
        while len(stones) >=2:
            y = stones.pop()
            x = stones.pop()
            
            if x == y:
                continue
            elif x!= y:
                tmp = y-x
                bisect.insort(stones,tmp)
                
        return stones.pop() if len(stones) == 1 else 0 
__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()
        while len(stones)>1:
            t1 = stones.pop()
            t2 = stones.pop()
            if t1-t2:
                bisect.insort_left(stones, t1-t2)
        return stones[0] if stones else 0
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap = []
        for stone in stones:
            heapq.heappush(heap, -stone)
        while len(heap) >= 2:
            a = -heapq.heappop(heap)
            b = -heapq.heappop(heap)
            heapq.heappush(heap, b-a)
        return -heap[0]
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        while len(stones) != 1:
            stones = sorted(stones)
            r = stones.pop()-stones.pop()
            stones.append(r)
        return stones.pop()