__________________________________________________________________________________________________
sample 308 ms submission
class Solution:
    def __init__(self, nums):
        self._nums = nums
        self._size = len(nums)

    def pick(self, tgt, randint=random.randint):
        nums = self._nums
        i = j = nums.index(tgt)
        for k in range(i, self._size):
            if nums[k] != tgt:
                break
            j = k
        return randint(i, j)
__________________________________________________________________________________________________
sample 15408 kb submission
class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        result = None
        
        count = 0
        
        for i, n in enumerate(self.nums):
            if n == target:
                count += 1
                chance = random.randint(1, count)
                if chance == count:
                    result = i
                    
        return result


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
__________________________________________________________________________________________________
