__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        res = 0
        for x in nums:
            res ^= x
            
        return res
__________________________________________________________________________________________________
sample 13804 kb submission
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
            previous = nums[0]
            cnt = 0
            for i in range(1, len(nums)):
                if nums[i] == previous:
                    cnt += 1
                else:

                    if cnt == 0:
                        return nums[i - 1]
                    else:
                        cnt = 0
                        previous = nums[i]

            return nums[-1]
__________________________________________________________________________________________________
