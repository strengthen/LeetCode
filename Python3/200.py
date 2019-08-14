__________________________________________________________________________________________________
sample 120 ms submission
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        if(len(grid)) == 0:
            return 0
        else:
            if(len(grid[0])== 0):
                return 0

        grid_dict = {}
        row_idx = 0
        cur_row_gp_num = 0
        for row in grid:
            row_gp_list = []
            grid_dict[row_idx%2] = []

            cur_gp = set()
            for i in range(len(row)):
                if(row[i] == '1'):
                    cur_gp.add(i)
                else:
                    if(cur_gp):
                        grid_dict[row_idx%2].append(cur_gp)

                        cur_gp = set()
                    else:
                        pass

            if (cur_gp):
                grid_dict[row_idx%2].append(cur_gp)


            cur_row_gp_num += len(grid_dict[row_idx%2])
        
            if(row_idx > 0):
                for pre_gp in grid_dict[(row_idx-1)%2]:
                    merge_gp = set()
                    rm_gp_list = []
                    for cur_gp in grid_dict[row_idx%2]:

                        if pre_gp & cur_gp:
                            merge_gp = merge_gp | cur_gp

                            rm_gp_list.append(cur_gp)
                            cur_row_gp_num -= 1

                        else:
                            pass
                    for rm_gp in rm_gp_list:
                        grid_dict[row_idx%2].remove(rm_gp)

                    if(merge_gp): 
                        grid_dict[row_idx%2].append(merge_gp)

            row_idx += 1

        return cur_row_gp_num
__________________________________________________________________________________________________
sample 13480 kb submission
from collections import deque
class Solution:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """
    def numIslands(self, grid):
        if not grid:
            return 0
        if not grid[0]:
            return 0
        
        m=len(grid)
        n=len(grid[0])
        islands=0
        for i in range(m):
            for j in range(n):
                if grid[i][j]=="1"  :
                    islands+=1
                    self.bfs(grid, i,j)
        return islands
    
    def bfs(self, grid, i ,j):
        q = deque([(i,j)])
        grid[i][j]=False
        while q:
            x, y = q.popleft()     
            for dx, dy in [(0,1),(1,0),(-1,0),(0,-1)]:
                x_=x+dx
                y_=y+dy
                if self.is_valid(grid, x_, y_):
                    q.append((x_,y_))
                    grid[x_][y_]="0"
                
                    
                    
    def is_valid(self,grid, i, j):
        return 0<=i<len(grid) and 0<=j<len(grid[0]) and grid[i][j]=="1"    
__________________________________________________________________________________________________
