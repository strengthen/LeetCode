__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        res = [[]]
        
        
        def dfs(index, path):
            
            if index == len(nums):
                return
            
            currPath = path.copy() 
            currPath.append(nums[index])
            
            res.append( currPath )
            
            for i in range(index+1, len(nums)):
                dfs(i, currPath)
            
        for i in range(len(nums)):
            dfs(i, [])
        
        
        return res
__________________________________________________________________________________________________
sample 13012 kb submission
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = 2**len(nums)
        outputs = []
        
        for i in range(0,n):
            output = []
            number = i
            
            for j in range(0,len(nums)):
                condition = number % 2
                if condition: 
                    output.append(nums[j])
                    
                number = number >> 1
            outputs.append(output)
        
        return outputs        
__________________________________________________________________________________________________
