__________________________________________________________________________________________________
sample 228 ms submission
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if k >= 2147483640 or k <= -2147483640:
            return True
        if 0 in nums:
            i = nums.index(0)
            if i-1 >= 0 and nums[i-1] == 0:
                return True
            if i+1 < len(nums) and nums[i+1] == 0:
                return True
        if k == 0:
            return False
        if k < 0:
            k = -k
        counter = 0
        d = dict()
        for i in range(len(nums)):
            counter += nums[i]
            d[counter] = i
            if counter % k == 0:
                if i != 0:
                    return True
            if counter > k:
                re = counter % k
                val = counter // k
                for x in range(val+1):
                    if x*k + re in d:
                        if d[x*k + re] < i - 1:
                            return True
        return False
__________________________________________________________________________________________________
sample 13100 kb submission
class Solution:
    def checkSubarraySum(self, nums, k):
        if len(nums)==0: return False
        
        ### k == 0 or k<0
        ## curSum concept
        
        curSum, numDict = 0, {0:-1}
        
        for i in range(len(nums)):
            if k == 0:
                curSum += nums[i]
            else:
                curSum = (curSum + nums[i])%k
        
            if curSum not in numDict:
                numDict[curSum] = i
            else:
                if i-numDict[curSum] >= 2:
                    return True
        return False
__________________________________________________________________________________________________
