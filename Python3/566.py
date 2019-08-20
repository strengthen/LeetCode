__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        if r * c != len(nums) * len(nums[0]):
            return nums
        newMatrix = [[0 for _ in range(c)] for _ in range(r)]
        matrix = []
        for each in nums:
            matrix += each
        start = 0
        end = c
        for index in range(r):
            newMatrix[index] = matrix[start : end]
            start += c
            end += c
        return newMatrix
__________________________________________________________________________________________________
sample 13948 kb submission
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        rslt=[]
        oldr=len(nums)
        oldc=len(nums[0])
        oldrtc=oldr*oldc
        newrtc=r*c
        if oldrtc<newrtc:
            return nums
        tphld=[]
        done=False
        for i in range(oldr):
            for j in range(oldc):
                cpi=i*oldc+j
                tphld.append(nums[i][j])
                if (cpi+1)%c==0:
                    rslt.append(tphld.copy())
                    tphld=[]
                if cpi==newrtc-1:
                    done=True
                    break
            if done:
                break
        return rslt
__________________________________________________________________________________________________
