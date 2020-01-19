__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return len([1 for x in nums if len(str(x)) % 2 == 0])
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        e = 0
        for i in nums:
            new = len(str(i))
            if new % 2 == 0:
                e += 1
        return e
__________________________________________________________________________________________________
