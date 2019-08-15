__________________________________________________________________________________________________
sample 376 ms submission
class Solution:
    def isRectangleCover(self, rectangles):
        corner=set()
        a,b,c,d,area=float('inf'),float('inf'),float('-inf'),float('-inf'),0
        for x1,y1,x2,y2 in rectangles:
            if x1<=a and y1<=b: a,b=x1,y1
            if x2>=c and y2>=d: c,d=x2,y2
            area+=(x2-x1)*(y2-y1)
            corner^={(x1,y1),(x2,y2),(x1,y2),(x2,y1)}
        return corner=={(a,b),(c,d),(a,d),(c,b)} and area==(c-a)*(d-b)
__________________________________________________________________________________________________
sample 17764 kb submission
class Solution:
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        x1 = sys.maxsize
        y1 = sys.maxsize
        x2 = -sys.maxsize
        y2 = -sys.maxsize
        _set = set()
        
        area = 0
        for rect in rectangles:
            x1 = min(x1, rect[0])
            y1 = min(y1, rect[1])
            x2 = max(x2, rect[2])
            y2 = max(y2, rect[3])
            
            area += (rect[2] - rect[0]) * (rect[3] - rect[1])
            
            for x, y in itertools.product([rect[0], rect[2]], [rect[1], rect[3]]):
                if (x, y) in _set:
                    _set.remove((x, y))
                else:
                    _set.add((x, y))
        return all((x, y) in _set for x, y in itertools.product([x1, x2], [y1, y2])) and len(_set) == 4 and area == (x2 - x1) * (y2 - y1)
__________________________________________________________________________________________________
