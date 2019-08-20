__________________________________________________________________________________________________
sample 192 ms submission
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                if i != 0 and (nums[i] == nums[i - 1] or nums[i + 1] < nums[i - 1]):
                    nums[i + 1] = nums[i]
                else:
                    nums[i] = nums[i + 1]
                break
        for j in range(len(nums) - 1):
            if nums[j] > nums[j + 1]:
                return False
        return True
__________________________________________________________________________________________________
sample 14036 kb submission
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        left = 0
        right = len(nums)-1
        
        while left < right and nums[left] <= nums[left+1]:
            left += 1
            
        while left < right and nums[right] >= nums[right-1]:
            right -= 1
            
        head = -float('inf') if left == 0 else nums[left-1]
        tail = float('inf') if right == len(nums)-1 else nums[right+1]   
        
        if right - left <= 1 and (head <= nums[right] or nums[left] <= tail):
            return True;
        else:
            return False;
__________________________________________________________________________________________________
