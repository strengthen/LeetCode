__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]: return -1
        m, n = len(grid), len(grid[0])
        #queue = [(i, j) for i in range(m) for j in range(n) if grid[i][j] == 2]
        queue, to_rot = [], 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    to_rot += 1
                elif grid[i][j] == 2:
                    queue.append((i,j))
                    
        time = 0
        while queue:
            for _ in range(len(queue)):
                x, y = queue.pop(0)
                for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                    new_x, new_y = x+dx, y+dy
                    if 0 <= new_x < m and 0 <= new_y < n and grid[new_x][new_y] == 1:
                        grid[new_x][new_y] = 2
                        queue.append((new_x, new_y))
                        to_rot -= 1
            time += 1
        return max(0, time-1) if to_rot == 0 else -1
__________________________________________________________________________________________________
sample 12972 kb submission
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        def neighbor(elem, num_rows, num_cols):
            n_list = []
            r, c = elem
            for i, j in [(r+1, c), (r-1, c), (r, c+1), (r, c-1)]:
                if 0 <= i < num_rows and 0 <= j < num_cols:
                    n_list.append([i, j])
            return n_list


        # grid = [[2, 1, 1], [0, 0, 1], [1, 1, 1]]
        # grid = [[0, 2, 1, 1], [1, 1, 1, 0], [1, 0, 1, 1]]
        num_rows = len(grid)
        num_cols = len(grid[0])
        curr_rotten = []

        # create initial rotten list
        num_fresh = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 2:
                    curr_rotten.append([i, j])
                elif grid[i][j] == 1:
                    num_fresh += 1

        t = 0
        while len(curr_rotten) != 0:
            new_rotten = []
            for elem in curr_rotten:
                for i, j in neighbor(elem, num_rows, num_cols):
                    if grid[i][j] == 1:
                        new_rotten.append([i, j])
                        grid[i][j] = 2
                        num_fresh -= 1
            if len(new_rotten) > 0:
                t += 1
            curr_rotten = new_rotten
        if num_fresh == 0:
            return t
        else:
            return -1
__________________________________________________________________________________________________
