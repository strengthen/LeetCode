__________________________________________________________________________________________________
sample 916 ms submission
class Solution:
    def gridIllumination(self, N: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        s = set()
        lx = {}
        ly = {}
        lp = {}
        lq = {}
        for lamp in lamps:
            x = lamp[0]
            y = lamp[1]
            s.add((x,y))
            if x in lx:
                lx[x]+=1
            else:
                lx[x]=1
            if y in ly:
                ly[y]+=1
            else:
                ly[y]=1
            if x+y in lp:
                lp[x+y]+=1
            else:
                lp[x+y]=1
            if x-y in lq:
                lq[x-y]+=1
            else:
                lq[x-y]=1
        ans = []
        for query in queries:
            x = query[0]
            y = query[1]
            if x in lx or y in ly or x + y in lp or x - y in lq:
                ans.append(1)
                for tx in range(x-1,x+2):
                    for ty in range(y-1, y+2):
                        if tx<0 or tx>=N or ty<0 or ty>=N:
                            continue
                        if (tx,ty) in s:
                            s.remove((tx,ty))
                            lx[tx]-=1
                            if lx[tx] == 0:
                                lx.pop(tx)
                            ly[ty]-=1
                            if ly[ty] == 0:
                                ly.pop(ty)
                            lp[tx+ty]-=1
                            if lp[tx+ty] ==0:
                                lp.pop(tx+ty)
                            lq[tx-ty]-=1
                            if lq[tx-ty] == 0:
                                lq.pop(tx-ty)
            else:
                ans.append(0)
        return ans
__________________________________________________________________________________________________
sample 27208 kb submission
from collections import defaultdict


class Solution:
    @staticmethod
    def get_neighbors(x: int,y: int, N: int):
        res = [(x, y)]
        if x-1 >= 0:
            res.append((x-1, y))
        if y-1 >= 0:
            res.append((x, y-1))
        if x+1 < N:
            res.append((x+1, y))
        if y+1 < N:
            res.append((x, y+1))
        if x-1 >= 0 and y-1 >= 0:
            res.append((x-1, y-1))
        if x-1 >= 0 and y+1 < N:
            res.append((x-1, y+1))
        if x+1 < N and y-1 >= 0:
            res.append((x+1, y-1))
        if x+1 < N and y+1 < N:
            res.append((x+1, y+1))
        return res
    
    def gridIllumination(self, N: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        row, col = defaultdict(int), defaultdict(int)
        diag1, diag2 = defaultdict(int), defaultdict(int)
        lamp_cell = set()
        for lamp in lamps:
            x, y = lamp
            row[x] += 1
            col[y] += 1
            diag1[x + y] += 1
            diag2[x - y] += 1
            lamp_cell.add((x, y))
        res = []
        for q in queries:
            x, y = q
            if (x in row and row[x] > 0) or (y in col and col[y] > 0) or (x+y in diag1 and diag1[x+y] > 0) or (x-y in diag2 and diag2[x-y] > 0):
                res.append(1)
            else:
                res.append(0)
            cells = self.get_neighbors(x, y, N)
            for cell in cells:
                if cell in lamp_cell:
                    lamp_cell.remove(cell)
                    row[cell[0]] -= 1
                    col[cell[1]] -= 1
                    diag1[cell[0] + cell[1]] -= 1
                    diag2[cell[0] - cell[1]] -= 1
        return res        
__________________________________________________________________________________________________
