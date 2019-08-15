__________________________________________________________________________________________________
sample 120 ms submission
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        ctr = collections.Counter(nums)
        return [ k for k in ctr if ctr[k] > len(nums)//3 ]
__________________________________________________________________________________________________
sample 13716 kb submission
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return []
        ans = []
        thrd = len(nums) // 3
        for i in range(12):
            if len(ans) == 2:
                return ans
            candidate = nums[random.randint(0, len(nums)-1)]
            if candidate in ans:
                continue
            counter = 0
            for num in nums:
                if num == candidate:
                    counter += 1
                    if counter > thrd:
                        ans.append(candidate)
                        break
        return ans
__________________________________________________________________________________________________
