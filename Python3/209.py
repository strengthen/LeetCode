__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        res = float('inf')
        left = 0
        curr_s = 0
        for right in range(0,len(nums)):
            curr_s += nums[right]
            while curr_s >= s:
                res = min(res, right - left + 1)
                curr_s -= nums[left]
                left +=1
                
        return res if res != float('inf') else 0
__________________________________________________________________________________________________
sample 14552 kb submission
class Solution:
    def minSubArrayLen(self, s, nums):
        total = left = 0
        result = len(nums) + 1
        for right, n in enumerate(nums):
            total += n
            while total >= s:
                result = min(result, right - left + 1)
                total -= nums[left]
                left += 1
        return result if result <= len(nums) else 0
__________________________________________________________________________________________________
