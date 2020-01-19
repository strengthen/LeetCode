__________________________________________________________________________________________________
sample 28 ms submission
from collections import OrderedDict

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        q = OrderedDict({(0, 0): [0, 0]})
        qo = {(0, 0):[0, 0]}
        while(q):
            #print(q)
            kt, vt = q.popitem(last = False)
            #qo[kt] = vt
            ri, ci = kt
            di, ki = vt
            
            if(m + n - 2 - ri - ci <= k - ki):
                return di + m + n - 2 -ri - ci
            
            if(ri - 1 >= 0):
                dpi, kpi = qo.get((ri-1, ci), (50, 50))
                if(grid[ri - 1][ci] == 0):
                    if(dpi > di + 1 or kpi > ki):
                        q[(ri - 1, ci)] = [di + 1, ki]
                        qo[(ri - 1, ci)] = [di + 1, ki]
                elif(k > ki and (dpi > di + 1 or kpi > ki + 1)):
                    q[(ri-1, ci)] = [di + 1, ki + 1]
                    qo[(ri-1, ci)] = [di + 1, ki + 1]
            
            if(ri + 1 < m):
                dpi, kpi = qo.get((ri+1, ci), (50, 50))
                if(grid[ri + 1][ci] == 0):
                    if(dpi > di + 1 or kpi > ki):
                        #print(dpi, kpi, di, ki, ri+1, ci)
                        q[(ri + 1, ci)] = [di + 1, ki]
                        qo[(ri + 1, ci)] = [di + 1, ki]
                elif(k > ki and (dpi > di + 1 or kpi > ki + 1)):
                    q[(ri+1, ci)] = [di + 1, ki + 1]
                    qo[(ri+1, ci)] = [di + 1, ki + 1]
            
            if(ci - 1 >= 0):
                dpi, kpi = qo.get((ri, ci - 1), (50, 50))
                if(grid[ri][ci - 1] == 0):
                    if(dpi > di + 1 or kpi > ki):
                        q[(ri, ci - 1)] = [di + 1, ki]
                        qo[(ri, ci - 1)] = [di + 1, ki]
                elif(k > ki and (dpi > di + 1 or kpi > ki + 1)):
                    q[(ri, ci - 1)] = [di + 1, ki + 1]
                    qo[(ri, ci - 1)] = [di + 1, ki + 1]
            
            if(ci + 1 < n):
                dpi, kpi = q.get((ri, ci + 1), (50, 50))
                if(grid[ri][ci + 1] == 0):
                    if(dpi > di + 1 or kpi > ki):
                        q[(ri, ci + 1)] = [di + 1, ki]
                        qo[(ri, ci + 1)] = [di + 1, ki]
                elif(k > ki and (dpi > di + 1 or kpi > ki + 1)):
                    q[(ri, ci + 1)] = [di + 1, ki + 1]
                    qo[(ri, ci + 1)] = [di + 1, ki + 1]
        return -1
__________________________________________________________________________________________________
sample 32 ms submission
from collections import deque
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        if len(grid) == 1 and len(grid[0]) == 1:
            return 0
        queue = deque([(0,0,k,0)])
        visited = set([(0,0,k)])
        Rows,Cols = len(grid),len(grid[0])
        if k > Rows-1 + Cols-1:
            return Rows-1 + Cols-1
        while queue:
            row, col, eliminate, steps = queue.popleft()
            for new_row, new_col in [(row-1,col), (row,col+1), (row+1, col), (row, col-1)]:
                if new_row >= 0 and new_row < Rows and new_col >= 0 and new_col < Cols:
                    if k>=Rows+Cols-new_row-new_col-1:
                        return steps+Rows-new_row+Cols-new_col-1
                    cv= grid[new_row][new_col]
                    if ((not cv) or (cv and eliminate > 0)) and (new_row,new_col,eliminate-cv) not in visited:
                        visited.add((new_row, new_col, eliminate-cv))
                        queue.append((new_row, new_col, eliminate-cv, steps+1))                        
                        if new_row == Rows-1 and new_col == Cols-1: 
                            return steps+1    
        return -1
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        if k >= m + n - 3:
            return m + n - 2
        queue, steps =  [(0,0,0)], 0, 
        obstacles = [[float('inf')]*n for _ in range(m)]
        obstacles[0][0] = 0
        moves = [[1,0],[0,1],[-1,0],[0,-1]]
        while len(queue) != 0:
            for _ in range(len(queue)):
                x,y,seen = queue.pop(0)
                if x == m - 1 and y == n - 1 : return steps
                for dx,dy in moves:
                    row, col = x + dx, y + dy
                    if 0 <= row < m and 0 <= col < n:
                        o = seen + grid[row][col]
                        if o >= obstacles[row][col] or o > k: continue
                        obstacles[row][col] = o
                        queue.append((row,col,o))
            steps += 1
        return -1