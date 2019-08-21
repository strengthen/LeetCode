__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        def getSum(intervals):
            '''
            intervals are sorted by start, may have overlaps, find the sum of total covered area
            [[1, 3],[2, 3]] = 3
            '''
            tot = 0
            end = -math.inf
            for a, b in intervals:
                if b<=end:
                    continue
                
                tot += b- max(end, a)
                end = b
            return tot
            
        ENTER = 0
        EXIT = 1
        
        lines = []
        for x1, y1, x2, y2 in rectangles:
            lines.append((x1, y1, y2, ENTER))
            lines.append((x2, y1, y2, EXIT))
        
        lines.sort(key=lambda x: (x[0], -x[3]))
        
        tot = 0 
        prevx = 0
        activeLines = []
        for line in lines:
            ysum = getSum(activeLines)
            tot += (line[0] - prevx) * ysum
            
            prevx = line[0]
            
            if line[3]==ENTER:
                activeLines.append([line[1], line[2]])
                activeLines.sort()
            
            else:
                activeLines.remove([line[1], line[2]])
                
        return tot%(10**9 + 7)
__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        ans = 0
        
        if not rectangles:
            return ans
        
        MOD = int(1e9 + 7)
        lines = sorted(x for x1, y1, x2, y2 in rectangles for x in [[x1, y1, y2, True], [x2, y1, y2, False]])
        segs = [(float('inf'),) * 2]
        x1 = lines[0][0]
        
        for x2, y1, y2, is_start in lines:
            h = lo = hi = 0
            
            for h1, h2 in segs:
                if h1 > hi:
                    h += hi - lo
                    lo, hi = h1, h2
                else:
                    hi = max(hi, h2)
            
            ans = (ans + (x2 - x1) * h) % MOD
            
            if is_start:
                bisect.insort(segs, (y1, y2))
            else:
                segs.remove((y1, y2))
            
            x1 = x2
        
        return ans
__________________________________________________________________________________________________
