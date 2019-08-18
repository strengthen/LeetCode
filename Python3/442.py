__________________________________________________________________________________________________
sample 376 ms submission
class Solution:
    def findDuplicates(self, nums):
        ret = []
        seen = {*()}
        ret_append = ret.append
        seen_add = seen.add
        for num in nums:
            if num in seen:
                ret_append(num)
            else:
                seen_add(num)
        return ret
__________________________________________________________________________________________________
sample 17912 kb submission
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        
        for i in range(len(nums)):
            if nums[i] == -1:
                continue
            temp = nums[i]
            nums[i] = 0
            while nums[temp - 1] != 0 and nums[temp - 1] != -1:
                nums[temp - 1], temp = -1, nums[temp - 1]

            if nums[temp - 1] == 0:
                nums[temp - 1] = -1
            elif nums[temp - 1] == -1:
                res.append(temp)
                
        return res
__________________________________________________________________________________________________
