__________________________________________________________________________________________________
sample 232 ms submission
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        cur, ans = -0xFFFFFFF, 0
        for x, y in sorted(pairs, key = operator.itemgetter(1)):
            if cur < x:
                cur = y
                ans += 1
        return ans
__________________________________________________________________________________________________
sample 13220 kb submission
class Solution(object):
    def findLongestChain(self, pairs):
        cur, ans = float('-inf'), 0
        for x, y in sorted(pairs, key = operator.itemgetter(1)):
            if cur < x:
                cur = y
                ans += 1
        return ans
__________________________________________________________________________________________________
