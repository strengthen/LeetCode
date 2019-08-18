__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if len(nums) == 1: return False
        s = sum(nums)
        if s % 2 == 1: return False
        t = s//2
        
        for n in nums:
            if n > t: return False
            
        nums.sort(reverse=True)
        
        def search(curr_sum, nums):
            if curr_sum > t: return False
            elif curr_sum == t: return True
            
            for i, n in enumerate(nums):
                new_nums = nums[:i] + nums[i+1:]
                return search(curr_sum + n, new_nums) or search(curr_sum, new_nums)
        
        return search(0, nums)
__________________________________________________________________________________________________
sample 13168 kb submission
class Solution:
    def canFindSum(self, nums, target, ind, n, d):
        if target in d:
            return d[target] 
        if target == 0:
            d[target] = True
        else:
            d[target] = False
            if target > 0:
                for i in range(ind, n):
                    if self.canFindSum(nums, target - nums[i], i+1, n, d):
                        d[target] = True
                        break
        return d[target]
    
    def canPartition(self, nums):
        s = sum(nums)
        if s % 2 != 0: return False
        return self.canFindSum(nums, s/2, 0, len(nums), {})
__________________________________________________________________________________________________
