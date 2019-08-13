__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def longestConsecutive(self, nums: 'List[int]') -> 'int':
        #把数组改为set，提供O(1)复杂度的快速查找
        res = 0
        
        nums = set(nums)
        
        for n in nums:
            if n - 1 not in nums:
                val, length = n + 1, 1
                
                while val in nums:
                    val += 1
                    length += 1
                
                res = max(res, length)
        return res    
__________________________________________________________________________________________________
sample 13800 kb submission
class Solution:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hp={x: False for x in nums}
        result=0
        for i in range(len(nums)):
            if nums[i] not in hp: continue
            if not hp[nums[i]]:
                hp[nums[i]]=True
                left, right=nums[i]-1, nums[i]+1
                count=1
                while left in hp: 
                    count+=1
                    hp[left]=True
                    left-=1
                
                while right in hp:
                    count+=1
                    hp[right]=True
                    right+=1
                    
                result=max(result, count)
        return result
__________________________________________________________________________________________________
