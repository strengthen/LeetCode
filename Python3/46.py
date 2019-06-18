__________________________________________________________________________________________________
sample 40 ms submission
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        visited = set([])

        def dfs(nums, path, res, visited):
            if len(path) == len(nums):
                res.append(path + [])
                return

            for i in range(0, len(nums)):
                if i not in visited:
                    visited.add(i)
                    dfs(nums, path+[nums[i]], res, visited)
                    visited.discard(i)

        dfs(nums, [], res, visited)
        
        return res   
__________________________________________________________________________________________________
sample 12664 kb submission
class Solution:
    def permute(self, nums):
        ans = []
        
        def dfs(index):
            if index == len(nums):
                ans.append(nums[:])
                return
            
            for i in range(index, len(nums)):
                nums[i], nums[index] = nums[index], nums[i]
                dfs(index + 1)
                nums[i], nums[index] = nums[index], nums[i]
        
        dfs(0)
        return ans

        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
__________________________________________________________________________________________________
