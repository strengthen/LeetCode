__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        covered = 0
        ans = 0
        for num in nums:
            while num > covered + 1:
                ans += 1
                covered = 2 * covered + 1
                if covered >= n:
                    return ans
            covered += num
            if covered >= n:
                return ans
        while covered < n:
            ans += 1
            covered = 2 * covered + 1
        return ans        
__________________________________________________________________________________________________
sample 13200 kb submission
class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        # greedy: find the smallest number missing, and add it; then re-caculate
        patches, i = 0, 0
        miss = 1
        N = len(nums)
        
        while miss <= n:
            if i < N and nums[i] <= miss:
                miss += nums[i]
                i += 1
            else:
                miss *= 2
                patches += 1
        return patches
__________________________________________________________________________________________________
