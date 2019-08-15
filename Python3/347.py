__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        ans= collections.Counter(nums).most_common(k)
        return [a[0] for a in ans]
__________________________________________________________________________________________________
sample 15640 kb submission
from collections import Counter
import heapq


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        heap = []
        for num, count in counter.items():
            if len(heap) == k:
                heapq.heappushpop(heap, (count, num))
            else:
                heapq.heappush(heap, (count, num))
        return [num for _, num in heap]
__________________________________________________________________________________________________
