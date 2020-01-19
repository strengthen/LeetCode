__________________________________________________________________________________________________
sample 112 ms submission
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        res=0
        if len(grid)==0:
            return res
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j]==0:
                    if self.traverse_grid(grid,i,j):
                        res+=1
                        
        return res
                        
    def traverse_grid(self,grid,i,j):
        if i<1 or i>=len(grid)-1 or j<1 or j>=len(grid[i])-1:
            #Because any 0 at the boundary will be rejected outright as it cannot be enclosed
            #by a boundary of 1
            return False
        grid[i][j]=1
        top=True if grid[i-1][j] else self.traverse_grid(grid,i-1,j)
        bottom=True if grid[i+1][j] else self.traverse_grid(grid,i+1,j)
        right=True if grid[i][j+1] else self.traverse_grid(grid,i,j+1)
        left=True if grid[i][j-1] else self.traverse_grid(grid,i,j-1)
        
        return top and bottom and right and left
__________________________________________________________________________________________________
sample 116 ms submission
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        nr = len(grid)
        nc = len(grid[0])
        num = 0
        
        
        for r in range(nr):
            for c in range(nc):
                tem = 0
                if grid[r][c] == 0:
                    num = num + 1
                    grid[r][c] = 1
                    if r==0 or r == nr-1 or c == 0 or c == nc-1:
                        tem = 1
                    
                    queue = collections.deque([r*nc+c,])
                    
                    while queue:
                        node = queue.popleft()
                        row = node // nc
                        col = node % nc
                        
                        if row-1>=0 and grid[row-1][col] == 0:
                            queue.append((row-1)*nc + col)
                            grid[row-1][col] = 1
                            if row-1==0 or row-1==nr-1 or col == 0 or col == nc-1:
                                tem = 1
                               
                            
                        if row+1<nr and grid[row+1][col] == 0:
                            queue.append((row+1)*nc + col)
                            grid[row+1][col] = 1
                            if row+1==0 or row+1==nr-1 or col == 0 or col == nc-1:
                                tem = 1
                              
                            
                        if col-1>=0 and grid[row][col-1] == 0:
                            queue.append(row*nc + col-1)
                            grid[row][col-1] =1
                            if row==0 or row==nr-1 or col-1 == 0 or col-1 == nc-1:
                                tem = 1
                                
                            
                        if col+1<nc and grid[row][col+1] == 0:
                            queue.append(row*nc + col+1)
                            grid[row][col+1] = 1
                            if row==0 or row==nr-1 or col+1 == 0 or col+1 == nc-1:
                                tem = 1
                             
                    if tem == 1:
                        num = num- 1
                      
                        
        return num
__________________________________________________________________________________________________
sample 124 ms submission
class Solution:
    def closedIsland(self, grid):
        num = 0
        self.m = len(grid)
        if not self.m: return num
        self.n = len(grid[0])
        if not self.n: return num
        for i in range(self.m):
            for j in range(self.n):
                if grid[i][j] == 0:
                    num += self.update(grid,i,j)
        return num

    def update(self,grid,i,j):
        grid[i][j] = 1
        n = 1
        if i == 0 or i == self.m-1 or j == 0 or j == self.n-1:
            n = 0
        if i < self.m - 1 and grid[i+1][j] == 0:
            n = min(self.update(grid,i+1,j),n)
        if j < self.n - 1 and grid[i][j+1] == 0:
            n= min(self.update(grid,i,j+1),n)
        if i > 0 and grid[i-1][j] == 0:
            n = min(self.update(grid,i-1,j),n)
        if j > 0 and grid[i][j-1] == 0:
            n= min(self.update(grid,i,j-1),n)
        return n
