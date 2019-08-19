__________________________________________________________________________________________________
sample 148 ms submission
#单调站经典题目
class Solution:
    def find132pattern1(self, nums: List[int]) -> bool:
        
        n = len(nums)
        mn = float('inf')
        for i in range(n):
            mn = min(nums[i], mn)
            if mn == nums[i]: continue
            for j in range(n-1, i,-1):
                if nums[i]>nums[j] and nums[j]>mn: 
                    return True
        return False
    def find132pattern(self, nums: List[int]) -> bool:
        if nums == None or len(nums) < 3: return False
        n = len(nums)
        stack = []
        third = float('-inf')
        for i in nums[::-1]:
            if i < third: return True
            while stack and i > stack[-1]:
                third = stack.pop()
            stack.append(i)
        return False
__________________________________________________________________________________________________
sample 14200 kb submission
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        import sys
        stack = []
        s3 = -sys.maxsize
        for n in nums[::-1]:
            if n < s3:
                return True
            while stack and stack[-1] < n:
                s3 = stack.pop()
            stack.append(n)
        return False
__________________________________________________________________________________________________
