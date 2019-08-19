__________________________________________________________________________________________________
sample 360 ms submission
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res = list(range(1, len(nums)+1))
        
        for i in nums:
            res[i-1] = 0
        
        return [i for i in res if i]
__________________________________________________________________________________________________
sample 18472 kb submission
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        if len(nums) == 0: return []
        slotted = [None] * len(nums)
        for num in nums:
            slotted[num - 1] = num
        return [idx + 1 for idx,num in enumerate(slotted) if num == None]
__________________________________________________________________________________________________
