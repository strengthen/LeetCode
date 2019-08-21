__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1=rec1[0]
        x2=rec2[0]
        y1=rec1[-1]
        y2=rec2[-1]
        l1=rec1[-1]-rec1[1]
        l2=rec2[-1]-rec2[1]
        L1=rec1[2]-rec1[0]
        L2=rec2[2]-rec2[0]
        if (y2>=y1+l2) or (y1>=y2+l1):
            return False
        elif (x2>=x1+L1) or (x1>=x2+L2):
            return False
        else:
            return True 
__________________________________________________________________________________________________
sample 12884 kb submission
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1,y1,x2,y2 = 0,1,2,3
        return ( 
            rec1[x1] < rec2[x2] and # rec1 is to left of rec2
            rec1[y1] < rec2[y2] and # rec1 is above rec2
            rec2[x1] < rec1[x2] and # rec2 is to the left of rec1
            rec2[y1] < rec1[y2]     # rec2 is above rec1
        )
__________________________________________________________________________________________________
