__________________________________________________________________________________________________
sample 584 ms submission
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        i = 0
        p1 = 0
        p2 = 0
        p3 = 0
        prev = -2
        while i < len(nums):
            count = 1
            while i + 1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
                count += 1
            if nums[i] != prev + 1:
                if p1 > 0 or p2 > 0:
                    return False
                p1 = count
                p2 = 0
                p3 = 0
            else:
                if count < p1 + p2:
                    return False
                c1 = max(0, count - p1 - p2 - p3)
                c2 = p1
                c3 = p2 + min(p3, count - p2 - p1)
                p1 = c1 
                p2 = c2
                p3 = c3
            prev = nums[i]
            i += 1
        return True if p1 == 0 and p2 == 0 else False
__________________________________________________________________________________________________
sample 14012 kb submission
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        count = collections.Counter(nums)
        tails = collections.Counter()
        for x in nums:
            if count[x] == 0:
                continue
            elif tails[x] > 0:
                tails[x] -= 1
                tails[x+1] += 1
            elif count[x+1] > 0 and count[x+2] > 0:
                count[x+1] -= 1
                count[x+2] -= 1
                tails[x+3] += 1
            else:
                return False
            count[x] -= 1
        return True        
__________________________________________________________________________________________________
