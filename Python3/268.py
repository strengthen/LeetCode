__________________________________________________________________________________________________
sample 136 ms submission
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        
        s = sum(nums)
        
        n = len(nums)
        
        return n*(n+1)//2 - s
__________________________________________________________________________________________________
sample 13876 kb submission
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        return int(n*(n+1)/2 - sum(nums))
__________________________________________________________________________________________________
