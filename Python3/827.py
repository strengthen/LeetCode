__________________________________________________________________________________________________
sample 120 ms submission
class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = n and len(grid[0])
        if not m or not n:
            return 0
        dic = collections.Counter()
        
        def dfs(i,j):
            for I, J in [(i+1,j),(i-1,j),(i,j-1),(i,j+1)]:
                if I>=0 and J >=0 and I< n and J<n:
                    if grid[I][J] == 1:
                        grid[I][J] = -1
                        self.count += 1
                        dfs(I,J)
                    if grid[I][J] == 0:
                        self.seen.add((I,J))
                        
        
        self.count = 1
        for i in range(n):
            for j in range (m):    
                if grid[i][j] == 1:
                    self.count = 1
                    self.seen = set()
                    grid[i][j] = -1
                    dfs(i,j)
                    for s in self.seen:
                        dic[s] += self.count
        # if not anythin in dic, then 1 is the mose 
    
        if not dic: return self.count
        return max(dic.values()) + 1
__________________________________________________________________________________________________
sample 124 ms submission
class Solution:
    def largestIsland(self, grid: list) -> int:
        if not grid: return 0
        id = 2
        area = {0: 0}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 1: continue
                area[id] = self.visit(grid, i, j, id)
                id += 1
        max_area = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 0: continue
                tmp = set()
                if i > 0: tmp.add(grid[i - 1][j])
                if j > 0: tmp.add(grid[i][j - 1])
                if i + 1 < len(grid): tmp.add(grid[i + 1][j])
                if j + 1 < len(grid[0]): tmp.add(grid[i][j + 1])
                max_area = max(max_area, 1 + sum([area[x] for x in tmp]))
        return max_area if max_area else len(grid) * len(grid[0])

    def visit(self, grid, i, j, id) -> int:
        ret, grid[i][j] = 1, id
        if i > 0 and grid[i - 1][j] == 1: ret += self.visit(grid, i - 1, j, id)
        if j > 0 and grid[i][j - 1] == 1: ret += self.visit(grid, i, j - 1, id)
        if i + 1 < len(grid) and grid[i + 1][j] == 1: ret += self.visit(grid, i + 1, j, id)
        if j + 1 < len(grid[0]) and grid[i][j + 1] == 1: ret += self.visit(grid, i, j + 1, id)
        return ret        
__________________________________________________________________________________________________
