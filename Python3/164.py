__________________________________________________________________________________________________
sample 52 ms submission
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        sorted_nums = sorted(nums)
        res = 0
        for i in range(len(sorted_nums) - 1):
            res = max(res, sorted_nums[i+1] - sorted_nums[i])
        return res
__________________________________________________________________________________________________
sample 13620 kb submission
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0
        else:
            nums.sort()
            max_interval = 0
            for i in range(1, n):
                if nums[i] - nums[i-1] >= max_interval:
                    max_interval = nums[i] - nums[i-1]
                    
            return max_interval
__________________________________________________________________________________________________
