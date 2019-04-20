__________________________________________________________________________________________________
52ms
class Solution:
    def removeDuplicates(self, nums: 'List[int]') -> 'int':
        if len(nums) == 0:
            return 0
        i = 0
        for j in range(1,len(nums)):
            if nums[j] != nums[i]:
                i+=1
                nums[i] = nums[j]
        return i+1
__________________________________________________________________________________________________
56ms
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums[:] = list(sorted(set(nums)))
        return len(nums)
__________________________________________________________________________________________________
60ms
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        lenght = 1
        i = 0
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:
                i += 1
                nums[j], nums[i] = nums[i], nums[j]
                lenght += 1
        return lenght
__________________________________________________________________________________________________
13620 kb 
class Solution:
    def removeDuplicates(self, nums: 'List[int]') -> 'int':
        if len(nums) == 0:
            return 0

        last = nums[-1]
        for i in reversed(range(len(nums[:-1]))):
            if nums[i] == last:
                nums.pop(i)
            else:
                last = nums[i]

        return len(nums)
__________________________________________________________________________________________________
13712 kb 
class Solution:
    def removeDuplicates(self, nums: 'List[int]') -> 'int':
        if len(nums)<2:
            return len(nums)
        k=nums[0]
        i=1
        while(True):
            if(i==len(nums)):
                break;
            if(k==nums[i]):
                nums.pop(i)
                i-=1
            else:
                k=nums[i]
            i+=1
        return len(nums)
__________________________________________________________________________________________________
