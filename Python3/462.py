__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        mean = sorted(nums)[int(len(nums)/2)]
        return sum([abs(x-mean) for x in nums])
__________________________________________________________________________________________________
sample 14064 kb submission
class Solution:
    def minMoves2(self, A: List[int]) -> int:
        A = sorted(A)
        m = A[int(len(A) / 2)]
        return sum([abs(x-m) for x in A])
__________________________________________________________________________________________________
