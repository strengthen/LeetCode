__________________________________________________________________________________________________
sample 112 ms submission
class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        p = 1
        n = len(nums)
        output = []
        for i in range(0,n):
            output.append(p)
            p = p * nums[i]
        p = 1
        for i in range(n-1,-1,-1):
            output[i] = output[i] * p
            p = p * nums[i]
        return output
__________________________________________________________________________________________________
sample 18672 kb submission
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output = []
        removed = {}
        
        for i in range(len(nums)):
            temp = nums[i]
            if temp not in removed:
                nums.pop(i)
                product = self.product(nums)
                output.append(product)
                nums.insert(i, temp)
                removed[temp] = product
            else:
                output.append(removed[temp])
        
        return output
    
    def product(self, array):
        result = 1
        for n in array:
            result *= n
        return result    

    # what if we add that element and sum it
__________________________________________________________________________________________________
