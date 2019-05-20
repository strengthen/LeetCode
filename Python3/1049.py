__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        total = sum(stones)
        sums = {0}
        for s in stones:
            sums |= {s + i for i in sums}
        return min(2 * pos_sum - total if 2 * pos_sum - total >= 0 else sys.maxsize for pos_sum in sums)
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        memo = {0}
        for s in stones:
            memo |= {i+s for i in memo}
        
        sumA = sum(stones)
        return min(abs(sumA-2*i) for i in memo)
__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def lastStoneWeightII(self, A):
        dp = {0}
        sumA = sum(A)
        for a in A:
            dp |= {a + i for i in dp}
        return min(abs(sumA - i - i) for i in dp)