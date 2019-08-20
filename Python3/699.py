__________________________________________________________________________________________________
sample 96 ms submission
from bisect import bisect_left as bl, bisect_right as br
class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        ans, xs, hs = [], [0], [0]
        for (x, h) in positions:
            i, j = br(xs, x), bl(xs, x+h)
            H = max(hs[max(i-1, 0):j], default = 0) + h
            xs[i:j] = [x, x + h]
            hs[i:j] = [H, hs[j - 1]]
            ans.append(H)
            if len(ans) > 1:
                ans[-1] = max(ans[-1], ans[-2])
        return ans
__________________________________________________________________________________________________
sample 100 ms submission
class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        pos,hs=[0],[0]
        maxh=0
        res=[]
        for left,side in positions:
            i=bisect.bisect_right(pos,left)
            j=bisect.bisect_left(pos,left+side)
            height=max(hs[i-1:j] or [0]) + side
            pos[i:j]=[left,left+side]
            hs[i:j]=[height,hs[j-1]]
            maxh=max(height,maxh)
            res.append(maxh)
        return res
__________________________________________________________________________________________________
