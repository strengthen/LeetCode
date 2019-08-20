__________________________________________________________________________________________________
sample 1196 ms submission
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1: return 0
        left = 0
        total = 1
        res = 0
        for right in range(len(nums)):
            total *= nums[right]
            while total >= k:
                total //= nums[left]
                left += 1
            res += right - left + 1 #combination的变形
        return res
__________________________________________________________________________________________________
sample 15720 kb submission
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = 0
        p = 1
        j = 0
        for i in range(n):
            if nums[i] >= k:
                p = 1
                j = i + 1
            else:
                while j < n and p * nums[j] < k:
                    p = p * nums[j]
                    j = j + 1

                ans = ans + j - i
                p = p / nums[i]        
        
        return ans
__________________________________________________________________________________________________
