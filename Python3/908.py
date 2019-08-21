__________________________________________________________________________________________________
sample 120 ms submission
class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        return max(0, max(A) - min(A) - 2 * K)
__________________________________________________________________________________________________
sample 13904 kb submission
class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        if len(A) < 2:
            return 0
        minimum = min(A)
        maximum = max(A)
        
        return max(maximum - minimum - 2*K, 0)
__________________________________________________________________________________________________
