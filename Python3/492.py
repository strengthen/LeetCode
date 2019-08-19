__________________________________________________________________________________________________
sample 20 ms submission
class Solution(object):
    
    def constructRectangle(self, area):
        
        mid = int(math.sqrt(area))

        while area % mid != 0:
            mid -= 1
    
        return [int(area/mid),mid]
__________________________________________________________________________________________________
sample 12996 kb submission
#
# @lc app=leetcode id=492 lang=python3
#
# [492] Construct the Rectangle
#
import math
class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        mi = 9999999999999999
        ans = []
        L = 1
        while L <= math.sqrt(area):
            W, m = divmod(area, L)
            if m == 0:
                if abs(L-W) < mi:
                    mi = abs(L-W)
                    ans = [L, W]
            L += 1
        return [ans[1], ans[0]]
__________________________________________________________________________________________________
