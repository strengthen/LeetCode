__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        ans = [0, 0]
        for c in chips:
            ans[c % 2] += 1
        return min(ans)
__________________________________________________________________________________________________
56ms
class Solution:
def minCostToMoveChips(self, chips: List[int]) -> int:
    return min(sum((c1 - c2) % 2 for c2 in chips) for c1 in chips)
__________________________________________________________________________________________________
