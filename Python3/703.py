__________________________________________________________________________________________________
sample 96 ms submission
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.pool = nums
        self.size = len(self.pool)
        heapq.heapify(self.pool)
        while self.size > self.k:
            heapq.heappop(self.pool)
            self.size -= 1

    def add(self, val: int) -> int:
        if self.size < self.k:#You may assume that nums' length ≥ k-1
            heapq.heappush(self.pool, val)#所以self.size 有可能 = k-1
            self.size += 1
        elif val > self.pool[0]:
            heapq.heapreplace(self.pool, val)            
        return self.pool[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
__________________________________________________________________________________________________
sample 16484 kb submission
# source for LeetCode 703. Kth Largest Element in a Stream

import heapq
class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.queue = nums[:k]
        self.size = k
        heapq.heapify(self.queue)
        for i in nums[k:]: self.add(i)

    def add(self, val: int) -> int:
        if(len(self.queue) < self.size):
            heapq.heappush(self.queue, val)
        else:
            heapq.heappushpop(self.queue, val)
        return self.queue[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
__________________________________________________________________________________________________
