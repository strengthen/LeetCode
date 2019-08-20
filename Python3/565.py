__________________________________________________________________________________________________
sample 116 ms submission
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums)):
            cnt = 0
            tmp = i
            while nums[tmp] != -1:
                nums[tmp], tmp = -1, nums[tmp]
                cnt += 1
            if cnt > ans:
                ans = cnt
        return ans
__________________________________________________________________________________________________
sample 14296 kb submission
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        res = 0
        for x in range(len(nums)):
            
            if(nums[x]!= sys.maxsize):
                start,count = nums[x],1
                nums[x] = sys.maxsize
                
                
                while(nums[start]!=sys.maxsize):
                    count+=1
                    temp = nums[start]
                    nums[start] = sys.maxsize
                    start = temp
                res = max(res,count)    
                    
        return res
__________________________________________________________________________________________________
