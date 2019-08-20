__________________________________________________________________________________________________
sample 204 ms submission
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        miss_num = int(n*(n+1)/2 - sum(set(nums)))
        extra_num = int(abs(n*(n+1)/2 - (sum(nums) + miss_num)))
        return [extra_num, miss_num]
__________________________________________________________________________________________________
sample 14032 kb submission
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        N = len(nums)
        array = [False]*N
        
        dulp = 0
        for i in range(N):
            if array[nums[i] - 1] == True:
                dulp = nums[i]
            array[nums[i] - 1] = True
        miss = 0
        for i in range(N):
            if array[i] == False:
                miss = i + 1
        return [dulp, miss]
__________________________________________________________________________________________________
