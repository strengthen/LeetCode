__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def reverse_nums(self, i, j, nums):
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return
        right = len(nums) - 1
        for i in range(len(nums) - 1, 0, -1):
            if nums[i - 1] < nums[i]:
                right = i
                break
            if i - 1 == 0:
                return self.reverse_nums(i - 1, len(nums) -1, nums)
        pivot = right - 1
        succesor = 0 
        for i in range(len(nums) -1, pivot, -1):
            if nums[i] > nums[pivot]:
                succesor = i 
                break
        nums[pivot], nums[succesor] = nums[succesor], nums[pivot]
        self.reverse_nums(right, len(nums) - 1, nums)
__________________________________________________________________________________________________
sample 12764 kb submission
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 1:return
        def f(start):
            cout = 1
            for i in range(start, int((len(nums)+start-1)/2)+1):
                nums[i], nums[len(nums)-cout] = nums[len(nums)-cout], nums[i]
                cout+=1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] > nums[i+1]: continue
            else:
                k = len(nums)-1
                while k>=i+1:
                    if nums[k] > nums[i]:
                        nums[k], nums[i] = nums[i], nums[k]
                        f(i+1)
                        return
                    k -= 1
        f(0)
__________________________________________________________________________________________________
