__________________________________________________________________________________________________
sample 96 ms submission
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        ans = []

        if not nums:
            return ans

        rank = []

        for num in nums[::-1]:
            i = bisect.bisect_left(rank, num)
            ans += i,
            rank[i:i] = num,

        return ans[::-1]
__________________________________________________________________________________________________
sample 16300 kb submission
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        output = [0] * len(nums)
        nums_sorted = sorted(nums)
        for i in range(len(nums)):
            output[i] = nums_sorted.index(nums[i])
            nums_sorted.remove(nums[i])
        return output
__________________________________________________________________________________________________
