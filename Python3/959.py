__________________________________________________________________________________________________
sample 52 ms submission
# solution 1
class UnionFindSet(object):
    def __init__(self):
        self.pars = dict()
        self.size = dict()
        
    def add(self, r, c, i):
        self.pars[(r, c, i)] = (r, c, i)
        self.size[(r, c, i)] = 1
        
    def union(self, r1, c1, i1, r2, c2, i2):
        p1, p2 = self.find(r1, c1, i1), self.find(r2, c2, i2)
        if p1 == p2:
            return
        
        if self.size[p1] > self.size[p2]:
            p1, p2 = p2, p1
        self.pars[p1] = p2
        self.size[p2] += self.size[p1]
        
    def find(self, r, c, i):
        key = (r, c, i)
        if self.pars[key] != key:
            pr, pc, pi = self.pars[key]
            self.pars[key] = self.find(pr, pc, pi)
        return self.pars[key]


class Solution:
    
    def regionsBySlashes(self, grid: List[str]) -> int:
        
        
        # solution 2:
        # runtime: 68ms, >96.80%
        def find(s):
            sets.setdefault(s,s)
            while sets[s] != s: s = sets[s]
            return s
        def join_sets(s1, s2):
            leader_s1, leader_s2 = find(s1), find(s2)
            sets[leader_s2] = leader_s1
            
        new_row, next_val = [], len(grid)
        sets = {i:i for i in range(len(grid))}
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                top = last_row[j][0] if i else sets[j]
                if grid[i][j] == ' ' or grid[i][j] == '/':
                    if j: join_sets(top,new_row[j-1][1])
                    if grid[i][j] == ' ': new_cell = [top, top]
                    else: next_val, new_cell = next_val + 1, [next_val, next_val]
                elif j: new_cell = [new_row[j-1][1], top]
                else: next_val, new_cell = next_val + 1, [next_val, top]
                new_row.append(new_cell)
            last_row, new_row = new_row, []

        return next_val - sum(sets[s] != s for s in sets)
__________________________________________________________________________________________________
sample 15496 kb submission
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        def dfs(arr, i, j):
            if i >= 0 and j >= 0 and i < len(arr) and j < len(arr[0])and arr[i][j] == 0:
                arr[i][j] = 1
                dfs(arr, i - 1, j)
                dfs(arr, i + 1, j)
                dfs(arr, i, j - 1)
                dfs(arr, i, j + 1)

        n = len(grid)
        m = len(grid[0])
        arr = [[0] * m * 3 for _ in range(n * 3)]
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '/':
                    arr[i * 3][j * 3 + 2] = 1
                    arr[i * 3 + 1][j * 3 + 1] = 1
                    arr[i * 3 + 2][j * 3] = 1
                elif grid[i][j] == '\\':
                    arr[i * 3][j * 3] = 1
                    arr[i * 3 + 1][j * 3 + 1] = 1
                    arr[i * 3 + 2][j * 3 + 2] = 1
        res = 0
        for i in range(len(arr)):
            for j in range(len(arr[0])):
                if arr[i][j] == 0:
                    dfs(arr, i, j)
                    res += 1
        return res
__________________________________________________________________________________________________
