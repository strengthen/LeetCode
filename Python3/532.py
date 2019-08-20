__________________________________________________________________________________________________
sample 124 ms submission
from collections import Counter

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        """
        Loop through nums and check if num + k or num - k is in num ~ O(N)
        """
        if k < 0: return 0
        if k == 0: return sum([val > 1 for val in Counter(nums).values()])
        
        pairs = set()
        count = 0
        for num in nums:
            if num in pairs: continue
            if num + k in pairs: count += 1
            if num - k in pairs: count += 1
            pairs.add(num)
        
        return count
__________________________________________________________________________________________________
sample 13884 kb submission
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        count=0
        nums=sorted(nums)
        for i in range (len(nums)):
            if i>0 and nums[i]==nums[i-1]:
                continue
            if i<len(nums)-1:
                j=i+1
                while j < len(nums)-1 and nums[j]-nums[i]<k:
                    j+=1
                if nums[j]-nums[i] == k:
                    count+=1
        return count
__________________________________________________________________________________________________
