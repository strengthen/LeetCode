__________________________________________________________________________________________________
sample 152 ms submission
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k == 0:
            return []
        if k == 1:
            return nums
        L = len(nums)
        res = [max(nums[:k])]
        for i in range(k, L):
            if nums[i] >= res[-1]:
                res.append(nums[i])
            else:
                if nums[i - k] < res[-1]:
                    res.append(res[-1])
                elif nums[i - k] == res[-1]:
                    res.append(max(nums[i-k+1:i+1]))
        return res
__________________________________________________________________________________________________
sample 19308 kb submission
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k == 0 or len(nums) == 0:
            return []
        if k == 1 :
            return nums
        n = len(nums)
        left = [float('-inf')] * n
        right = [float('-inf')] * n
        left[0], right[-1] = nums[0], nums[-1]
        for i in range(1, n):
            #from left to right
            if i % k == 0:
                left[i] = nums[i]
            else:
                left[i] = max(left[i - 1], nums[i])
            #form right to left
            j = n - 1 - i
            if (j + 1) % k == 0:
                right[j] = nums[j]
            else:
                right[j] = max(right[j + 1], nums[j])
        res = []
        for i in range(n - k + 1):
            res.append(max(right[i], left[i + k - 1]))
        return res
__________________________________________________________________________________________________
