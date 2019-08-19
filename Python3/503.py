__________________________________________________________________________________________________
sample 220 ms submission
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        if not nums: return []
        max_num = max(nums)
        max_i = nums.index(max_num)
        
        res = [-1] * len(nums)
        stack = [max_num]
        
        for i in range(max_i-1, -1, -1):
            while stack[-1] <= nums[i]:
                stack.pop()
            res[i] = stack[-1]
            stack.append(nums[i])
            
        for i in range(len(nums)-1, max_i, -1):
            while stack and stack[-1] <= nums[i]:
                stack.pop()
            if stack: res[i] = stack[-1]
            stack.append(nums[i])
        
        return res
__________________________________________________________________________________________________
sample 14356 kb submission
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        q = []
        n = len(nums)
        out = [-1] * n
        j = 0
        for i in range(n):
            if nums[j] < nums[i]: j = i
            while q and nums[q[-1]] < nums[i]: out[q.pop()] = nums[i]
            q.append(i)
        for i in range(j+1):
            while q and nums[q[-1]] < nums[i]: out[q.pop()] = nums[i]
            q.append(i)
        return out
__________________________________________________________________________________________________
