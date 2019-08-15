__________________________________________________________________________________________________
sample 40 ms submission
import heapq
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        if not nums1 or not nums2:
            return []
        n,m=len(nums1),len(nums2)
        mappings=[0]*n
        que=[[nums1[i]+nums2[0], i] for i in range(n)]
        res=[]
        while len(res)<k and que:
            val,idx=heapq.heappop(que)
            res.append([nums1[idx],nums2[mappings[idx]]])
            mappings[idx]+=1
            if mappings[idx]<m:
                val2=nums1[idx]+nums2[mappings[idx]]
                heapq.heappush(que,[val2,idx])
        return res
__________________________________________________________________________________________________
sample 13304 kb submission
import heapq
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        if not nums1 or not nums2:
            return []
        
        def push(i, j):
            heapq.heappush(heap, (nums1[i] + nums2[j], i, j))
        
        def pop():
            _, i, j = heapq.heappop(heap)
            return i, j
        
        res = []
        heap = [(nums1[0] + nums2[0], 0, 0)]
        while heap and len(res) < k:
            i, j = pop()
            res.append((nums1[i], nums2[j]))
            if j == 0 and i + 1 < len(nums1):
                push(i + 1, j)
            if j + 1 < len(nums2):
                push(i, j + 1)
        
        return res
__________________________________________________________________________________________________
