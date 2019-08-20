__________________________________________________________________________________________________
sample 900 ms submission
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0

        mapping = {0: -1}
        result = 0

        curr = 0
        for i, num in enumerate(nums):
            curr += 1 if num else -1

            if curr in mapping:
                if i - mapping[curr] > result:
                    result = i - mapping[curr]
            else:
                mapping[curr] = i

        return result
__________________________________________________________________________________________________
sample 17452 kb submission
class Solution:
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d={1:-1}
        
        res=0
        cur=0
        
        for i in range(len(nums)):
            
            cur+=nums[i]
            
            if 2*cur-i in d:
                
                res=max(res,i-d[2*cur-i])
            
            d[2*cur-i]=min(d.get(2*cur-i,len(nums)),i)
        return res
__________________________________________________________________________________________________
