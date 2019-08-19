__________________________________________________________________________________________________
sample 316 ms submission
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        xmap = map("{:032b}".format, nums)
        total, N = 0, len(nums)
        for i in zip(*xmap):
            ones = i.count('1')
            total += ones * (N - ones)
        return total        
__________________________________________________________________________________________________
sample 14108 kb submission
import heapq
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        if len(nums)<=1: return 0
        max_val=max(nums)
        index=curr=1
        while curr<=max_val:
            curr=2**index
            index+=1
        index-=2
        heapq.heapify(nums)
        ans=0
        #print(index)
        for i in range(index,-1,-1):
            left=[]
            while nums and nums[0]<2**i:
                left.append(heapq.heappop(nums))
            #print(left,nums)
            ans+=len(left)*len(nums)
            nums=[a-2**i for a in nums]+left
            heapq.heapify(nums)
        return ans
__________________________________________________________________________________________________
