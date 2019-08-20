__________________________________________________________________________________________________
sample 912 ms submission
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        
        # Approach from forum
        M = d = 0
        for i in range(len(nums)-k):
            d += nums[i+k] - nums[i]
            if d > M: 
                M = d
        return (sum(nums[:k])+M)/k
__________________________________________________________________________________________________
sample 15336 kb submission
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        s = sum(nums[:k])
        maxs = s
        for idx in range(k, len(nums)):
            s += nums[idx]-nums[idx-k]
            maxs = max(maxs, s)
        return maxs/k
__________________________________________________________________________________________________
