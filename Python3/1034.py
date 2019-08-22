__________________________________________________________________________________________________
sample 144 ms submission
class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        seen = set()
        if not grid or not grid[0]:
            return grid
        self.row, self.col = len(grid), len(grid[0])
        def dfs(x, y):
            if (x, y) in seen: return True
            if not (0 <= x < self.row and 0 <= y < self.col and grid[x][y] == grid[r0][c0]):
                return False
            seen.add((x,y))
            if dfs(x+1,y) + dfs(x-1,y) + dfs(x, y+1) + dfs(x, y-1) < 4:
                grid[x][y] = color
            return True
        dfs(r0, c0)
        return grid
__________________________________________________________________________________________________
sample 13076 kb submission
import copy
class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        _color = grid[r0][c0]
        updated = []
        def is_border(r, c):
            for i, j in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                r0 = r+i
                c0 = c+j
                if r0 < 0 or c0 < 0:
                    return True
                try:
                    _c = grid[r0][c0]
                except:
                    return True
                if _c != _color:
                    return True
            return False
        
        def get_neighbor(r, c):
            neighbors = []
            for i, j in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                r0 = r+i
                c0 = c+j
                if r0 < 0 or c0 < 0:
                    continue
                try:
                    _c = grid[r0][c0]
                except:
                    continue
                if (r0, c0) in updated:
                    continue
                if _c == _color:
                    neighbors.append((r0, c0))
            return neighbors
        queue = [(r0, c0)]
        new_grid = copy.deepcopy(grid)
        while queue:
            r, c = queue[0]
            updated.append((r,c))
            queue = queue[1:]
            if is_border(r, c):
                new_grid[r][c] = color
            new_list = get_neighbor(r,c)
            queue.extend(new_list)
        return new_grid
__________________________________________________________________________________________________
