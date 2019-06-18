__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        def permute(nums, i):
            if i == 0:
                return [[nums[i]]]
            
            solutions = []
            
            for permut in permute(nums, i - 1):
                for pos in range(len(permut) + 1):
                    solutions.append(
                        permut[:pos] + [nums[i]] + permut[pos:]
                    )
                    if pos < len(permut) and permut[pos] == nums[i]:
                        break
                    
            return solutions
        
        return permute(nums, len(nums) - 1)        
__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = [[]]
        for i, n in enumerate(nums):
            n_ans = []
            for a in ans:
                for j in range(len(a) + 1):
                    n_ans.append(a[:j] + [n] + a[j:])
                    if j < len(a) and a[j] == n: break
            ans = n_ans
        return ans
__________________________________________________________________________________________________
