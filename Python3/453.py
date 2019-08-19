__________________________________________________________________________________________________
sample 264 ms submission
# class Solution:
#     def minMoves(self, nums: List[int]) -> int:
        
#         nums = sorted(nums)
#         output = 0
#         target = nums[0]
        
#         for x in nums[1:]:
#             output += x - target
#         return output

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        
        target = min(nums)
        n = len(nums)
        
        return sum(nums) - target*n
__________________________________________________________________________________________________
sample 13976 kb submission
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(nums) - len(nums)*min(nums)

# n-1 elements plus 1 is equal to one element minus 1
# so it means every element decreases to the minimun of nums
__________________________________________________________________________________________________
