__________________________________________________________________________________________________
class Solution:
    def canDivideIntoSubsequences(self, nums: List[int], K: int) -> bool:
        n=len(nums);tmp=1
        for i in range(1,n):
            if nums[i]!=nums[i-1]:
                if tmp*K>n:
                    return False
                tmp=1
            else:
                tmp+=1
        if tmp*K>n:
            return False
        return True
__________________________________________________________________________________________________

__________________________________________________________________________________________________
