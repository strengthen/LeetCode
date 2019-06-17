__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        start,end=0,len(nums)-1
        while start<=end:
            if nums[start]>0:
                start=start+1
            elif nums[end]<=0:
                end=end-1
            else:
                nums[start],nums[end]=nums[end],nums[start]
                start=start+1
                end=end-1
        if start<len(nums) and nums[start]>0:
            par=start
        else:
            par=start-1
        for i in range(par+1):
            if nums[i]<=0:
                ind=-nums[i]
            else:
                ind=nums[i]
            if ind<=par+1 and nums[ind-1]>0:
                nums[ind-1]=-nums[ind-1]
        print(nums)
        for i in range(par+1):
            if nums[i]>0:
                return i+1
        return par+2
__________________________________________________________________________________________________
sample 12776 kb submission
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 1
        
        for i in range(len(nums)):
            p = i
            # switch
            while nums[p] > 0 and nums[p] <= len(nums) and nums[p] != p+1:
                t = nums[p]
                nums[p],nums[t-1] = nums[t-1],nums[p]
                if nums[p] == t:
                    break
        for i in range(len(nums)):
            if nums[i] != i+1:
                return i+1
        return len(nums)+1                
__________________________________________________________________________________________________
