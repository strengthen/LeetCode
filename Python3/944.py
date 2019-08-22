__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        return sum(list(ls) != sorted(ls) for ls in zip(*A))
__________________________________________________________________________________________________
sample 13364 kb submission
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        return sum(1 for col in zip(*A) if not all(col[i] <= col[i+1] for i in range(len(col) - 1)))
__________________________________________________________________________________________________
