__________________________________________________________________________________________________
sample 80 ms submission
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        lis=[]
        for i in range(1,n+1):
            lis.append(i)
        from itertools import combinations
        l=list(combinations(lis,k))
        return l        
__________________________________________________________________________________________________
sample 14876 kb submission
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
         
        res = []
        self.dfs(range(1,n+1), k, [], res)
        return res
        
    def dfs(self, nums, k, path, res):
        if k == 0:
            res.append(path)
            return
        
        for i in range(len(nums)):
            self.dfs(nums[i+1:], k-1, path+[nums[i]], res)
        return
__________________________________________________________________________________________________
