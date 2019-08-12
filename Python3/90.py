__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        combinations = []
        self.dfs(nums, 0, [], combinations)
        return combinations
        
    def dfs(self, nums, index, combination, combinations):
        combinations.append(list(combination))
        
        for i in range(index, len(nums)):
            if i != index and nums[i] ==nums[i-1]:
                continue
            combination.append(nums[i])
            self.dfs(nums, i + 1, combination, combinations)
            combination.pop()        
__________________________________________________________________________________________________
sample 13100 kb submission
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.res = []
        self.helper([], 0, nums)
        return self.res
        
    def helper(self, path, depth, nums):
        if depth >= len(nums):
            if path not in self.res:
                self.res.append(path)
            return
        self.helper(path, depth+1, nums)
        self.helper(path+[nums[depth]], depth+1, nums)
__________________________________________________________________________________________________
