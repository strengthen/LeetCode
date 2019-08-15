__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        pos = 0
        for i in range(len(nums)):
            if nums[i]:
                nums[pos] = nums[i]
                pos +=1
        for j in range(pos,len(nums)):
            nums[j] = 0
__________________________________________________________________________________________________
sample 14192 kb submission
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        

    
        last_zero_i = None

        for i, v in enumerate(nums):
            if v == 0:
                if last_zero_i is None:
                    last_zero_i = i         
            elif (last_zero_i is not None):
                nums[last_zero_i] = v
                nums[i] = 0

                if nums[last_zero_i+1] == 0:
                    last_zero_i += 1
                else:
                    last_zero_i = None
__________________________________________________________________________________________________
