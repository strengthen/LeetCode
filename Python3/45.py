__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def jump(self, nums: List[int]) -> int:
        step = 0
        curr = 0
        next = 0
        n = len(nums)
        for i in range(0,n):
            if curr<i:
                curr = next
                step += 1
            next = max(next, nums[i]+i)
        return step
__________________________________________________________________________________________________
sample 14096 kb submission
class Solution:
    def jump(self, nums: List[int]) -> int:
        start, end, step = 0, 0, 0
        while end < len(nums)-1:
            step += 1
            maxend = end
            for i in range(start, end+1):
                tmp = i + nums[i]
                if tmp > maxend:
                    maxend = tmp
            start, end = end+1, max(maxend,end)
            print(start,end)
        return step
__________________________________________________________________________________________________
