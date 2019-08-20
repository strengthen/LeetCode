__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        #最大值，且其只有一个，检查其是否为所有其他值的两倍
        #O(n)问题
        #显然，获取max和逐一检查两倍关系是一种方式
        #一次遍历获得max,i和secondmax也是可以的。。。
                
        maxv=float("-inf")
        secondmax=float("-inf")
        index=0
        for i in range(len(nums)):
            if nums[i]>maxv:
                #这是新的最大值
                index=i
                maxv,secondmax=nums[i],maxv
            elif nums[i]>secondmax:
                #新的secondmax
                secondmax=nums[i]
                
        if maxv>=2*secondmax:
            return index
        else:
            return -1
__________________________________________________________________________________________________
sample 12940 kb submission
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        
        largestNum = max(nums)
        largestNumIndex = nums.index(largestNum)
         
        if all(largestNum >= 2*num for num in nums if num != largestNum):
            return largestNumIndex
        
        return -1 
__________________________________________________________________________________________________
