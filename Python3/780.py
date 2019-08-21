__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        if tx > ty:
            sx, sy, tx, ty = sy, sx, ty, tx
            
        while sx < tx:
            sx, sy, tx, ty = sy, sx, (ty-tx) % tx, tx
        
        return sx == tx and ty >= sy and (ty-sy) % sx == 0
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while sx < tx and sy < ty:
            tx, ty = tx % ty, ty % tx
        return sx == tx and sy <= ty and (ty - sy) % sx == 0 or \
               sy == ty and sx <= tx and (tx - sx) % sy == 0
__________________________________________________________________________________________________
