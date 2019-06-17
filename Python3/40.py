__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        if not candidates:
            return []
        result = []
        candidates.sort()
        self.dfs(candidates,target,0,[],result)
        return result
    
    def dfs(self,candidates,target,index,path,result):
        if target == 0:
            result.append(path)
            return
        for i in range(index,len(candidates)):
            if target < candidates[i]:
                return
            if i > index and candidates[i-1] == candidates[i]:
                continue
            self.dfs(candidates,target-candidates[i],i+1,path+[candidates[i]],result)
__________________________________________________________________________________________________
sample 12740 kb submission
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        def visit(targetVal, temp, start):
            if targetVal<0:
                return 
            if targetVal == 0:
                res.append(tuple(sorted(temp)))
            for index in range(start, candidates.__len__()):
                val = candidates[index]
                if index>start and candidates[index] == candidates[index-1]:
                    continue
                visit(targetVal-val, temp+[val], index+1)
        visit(target, [], 0)
        return res
__________________________________________________________________________________________________
