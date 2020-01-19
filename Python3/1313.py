__________________________________________________________________________________________________
sample 52 ms submission
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        out_lst = []
        for i in range(0,len(nums),2):
        #    val = nums[i + 1]
            out_lst += [nums[i+1]] * nums[i]
        return out_lst
__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        
        res = []
        for i in range(len(nums) // 2):
            a, b = nums[i * 2], nums[i * 2 + 1]
            res += [b] * a
        return res
__________________________________________________________________________________________________
