__________________________________________________________________________________________________
sample 124 ms submission
class Solution:
     def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        row_n = len(grid)
        col_n = len(grid[0])
        res = 0
        for i in range(row_n):
            for j in range(col_n):
                if grid[i][j]:
                    area = 0
                    stack = [(i, j)]
                    grid[i][j] = 0
                    while stack:
                        cur_i, cur_j = stack.pop()
                        area += 1
                        if cur_i - 1 >= 0 and grid[cur_i - 1][cur_j]:
                            stack.append((cur_i - 1, cur_j))
                            grid[cur_i - 1][cur_j] = 0
                        if cur_i + 1 < row_n and grid[cur_i + 1][cur_j]:
                            stack.append((cur_i + 1, cur_j))
                            grid[cur_i + 1][cur_j] = 0
                        if cur_j - 1 >= 0 and grid[cur_i][cur_j - 1]:
                            stack.append((cur_i, cur_j - 1))
                            grid[cur_i][cur_j - 1] = 0
                        if cur_j + 1 < col_n and grid[cur_i][cur_j + 1]:
                            stack.append((cur_i, cur_j + 1))
                            grid[cur_i][cur_j + 1] = 0
                    res = max(res, area)
        return res        
__________________________________________________________________________________________________
sample 14840 kb submission
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_size = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    size = self.explore_island(grid, i, j, size=1)
                    if size > max_size:
                        max_size = size
        return max_size
                    
    
    def explore_island(self, grid, i, j, size):
        neighbours = []
        #print("In cell {}, {}, size is {}".format(str(i), str(j), str(size)))
        #search up
        if i>0:
            if grid[i-1][j] == 1:
                neighbours.append((i-1, j))
                grid[i-1][j] = 0
                size += 1
        #search right
        if j<len(grid[0])-1:
            if grid[i][j+1] == 1:
                neighbours.append((i, j+1))
                grid[i][j+1] = 0
                size += 1
        #search down
        if i<len(grid)-1:
            if grid[i+1][j] == 1:
                neighbours.append((i+1, j))
                grid[i+1][j] = 0
                size += 1
        #search left
        if j>0:
            if grid[i][j-1] == 1:
                neighbours.append((i, j-1))
                grid[i][j-1] = 0
                size += 1
        #print("After neighbour search size {}".format(str(size)))
        for n in neighbours:
            size = self.explore_island(grid, n[0], n[1], size)
        return size
__________________________________________________________________________________________________
