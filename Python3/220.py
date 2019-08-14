__________________________________________________________________________________________________
sample 52 ms submission
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if len(nums) < 1 or t < 0 or k <= 0:
            return False
        if t == 0 and len(nums) == len(set(nums)):
            return False
        
        for i in range(len(nums)):
            jmax = min(len(nums), i+k+1)
            for j in range(i+1, jmax):
                val = nums[j]-nums[i]
                val = val if val>=0 else -val
                if val <= t:
                    return True
        return False
__________________________________________________________________________________________________
sample 13916 kb submission
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if (nums == None or len(nums) == 0 or k <= 0 or t < 0):
            return False

        p1=0
        p2=0
        while (p1 < (len(nums)-1)):
            tmp=nums[p1]-nums[p2]
            if (abs(tmp) <= t and p1!=p2):
                return True
            if (p2 - p1 < k and p2 < (len(nums)-1)):
                p2 += 1
            else:
                p1 += 1
                if(t!= 0):
                    p2= p1 + 1    
        return False
__________________________________________________________________________________________________
