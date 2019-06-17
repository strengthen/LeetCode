__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res=[]
        candidates.sort()
        self.DFS(candidates,target,0,[],res)
        return res
    def DFS(self,nums,target,index,path,res):
        #每次从上一个位置开始往后加入path
        for i in range(index,len(nums)):
        #res和path每次都要往下一层传，所以放在参数里
        #加上个判断省去深度遍历
            if nums[i] > target:
                break
            if nums[i] == target:
                res.append(path+[nums[i]])
                return
            self.DFS(nums,target-nums[i],i,path+[nums[i]],res)
__________________________________________________________________________________________________
sample 12716 kb submission
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def combsum(can,t):
            rt = []
            if min(can) > t:
                return rt

            for v in can:
                if v == t:
                    rt.append([v])
                res = combsum(can,t - v)
                if len(res) > 0:
                    for r in res:
                        r.append(v)
                        r.sort()
                        if r not in rt:
                            rt.append(r)
                else:
                    continue
            return rt        
        return combsum(candidates,target)
__________________________________________________________________________________________________
