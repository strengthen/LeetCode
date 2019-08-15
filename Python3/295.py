__________________________________________________________________________________________________
sample 196 ms submission
import heapq

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        import heapq
        self.maxh = [] # maxheap
        self.minh = [] # minheap  leave large number
        
    def addNum(self, num: int) -> None:
        if len(self.maxh) == len(self.minh):
            tmp = heapq.heappushpop(self.maxh,-num)  #  1 2 3
            heapq.heappush(self.minh,-tmp)           # 4 ,5 6  10   (mnum =10)
        else:
            tmp = heapq.heappushpop(self.minh,num)     #     6 7  10     num = 7
            heapq.heappush(self.maxh,-tmp)           #    1 2 3 4 
                
                
    def findMedian(self) -> float:
        if len(self.maxh) == len(self.minh):
            return (-self.maxh[0] + self.minh[0])/2
        else:
            return self.minh[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
__________________________________________________________________________________________________
sample 23208 kb submission
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.left_heap = []  # max heap - minheap with -val, lower half
        self.right_heap = []  # min heap - upper half
        

    def addNum(self, num: int) -> None:
        # add to heap based on value
        # make sure heap sizes meet constraint: size(left heap) = size(right heap) (- 1)
        if len(self.right_heap) == 0 or num > self.right_heap[0]:
            heapq.heappush(self.right_heap, num)
            while len(self.left_heap) + 1 < len(self.right_heap):
                val = heapq.heappop(self.right_heap)
                heapq.heappush(self.left_heap, -val)
        else:
            heapq.heappush(self.left_heap, -num)
            while len(self.left_heap) > len(self.right_heap):
                val = heapq.heappop(self.left_heap)
                heapq.heappush(self.right_heap, -val)
        return

    def findMedian(self) -> float:
        if len(self.left_heap) == len(self.right_heap):
            return (-self.left_heap[0] + self.right_heap[0]) / 2
        return self.right_heap[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
__________________________________________________________________________________________________
