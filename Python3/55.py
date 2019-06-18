__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxReach = 0
        for i in range(len(nums)):
            if (maxReach < i):
                return False
            maxReach = i+nums[i] if (i+nums[i] > maxReach) else maxReach
        return True
__________________________________________________________________________________________________
sample 14044 kb submission
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        last_good_po = len(nums)-1
        for i in range(len(nums)-2, -1, -1):
            if i + nums[i] >= last_good_po:
                last_good_po = i
        return last_good_po == 0
__________________________________________________________________________________________________
