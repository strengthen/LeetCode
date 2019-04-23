__________________________________________________________________________________________________
36ms
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while val in nums:
            nums.remove(val)
        return len(nums)        
__________________________________________________________________________________________________
40ms
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = j = 0
        while i < len(nums):
            if nums[i] != val:
                nums[j] = nums[i]
                j += 1
            i += 1
        return j        
__________________________________________________________________________________________________
44ms
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while(val in set(nums)):
            nums.remove(val)
        return len(nums)
__________________________________________________________________________________________________
12136 kb
class Solution:
    def removeElement(self, nums: 'List[int]', val: 'int') -> 'int':
        
        if not nums:
            return 0
        
        newtail = 0
        for i in range(0, len(nums)):
            if nums[i] != val:
                nums[newtail] = nums[i]
                newtail += 1
        
        return newtail
__________________________________________________________________________________________________
12196 kb
class Solution:
    def removeElement(self, nums: 'List[int]', val: 'int') -> 'int':
        i,last=0,len(nums)-1
        while i<=last:
            if nums[i] ==val:
                nums[i],nums[last] = nums[last],nums[i]
                last -=1
            else:
                i +=1
        return last+1
__________________________________________________________________________________________________
