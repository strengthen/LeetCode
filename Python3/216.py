__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def combinationSum3(self, k: int, n: int, d:int = 9) -> List[List[int]]:
        if k * (2 * d - k + 1) <= 2 * n:
            return [list(range(d - k + 1, d + 1))] if k * (2 * d - k + 1) == 2 * n else []
        if k * (k + 1) >= 2 * n:
            return [list(range(1, k + 1))] if k * (k + 1) == 2 * n else []
        return [l + [d] for l in self.combinationSum3(k - 1, n - d, d - 1)] + self.combinationSum3(k, n, d - 1);
__________________________________________________________________________________________________
sample 13000 kb submission
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        nums = list(range(1, 10))
        res = []
        
        def dfs(nums, path, k, target, res):
            
            if k < 0 or sum(path) > target:
                return
            
            if k == 0 and sum(path) == target:
                res.append(path)
                return
            
            for i in range(len(nums)):
                
                dfs(nums[i+1:], path + [nums[i]], k-1, target, res)
                
        dfs(nums, [], k, n, res)
    
        return res
__________________________________________________________________________________________________
