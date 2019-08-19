__________________________________________________________________________________________________
sample 380 ms submission
class Solution:
    def findMaxConsecutiveOnes(self, nums):
        return max(len(list(g)) if k == 1 else 0 for k, g in itertools.groupby(nums))
__________________________________________________________________________________________________
sample 13116 kb submission
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans = 0
        temp = 0
        for i in nums:
            if(i == 1):
                temp += 1
            else:
                if(temp > ans):
                    ans = temp
                temp = 0
        if(temp > ans):
            ans = temp
        
        return ans
__________________________________________________________________________________________________
