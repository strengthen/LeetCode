__________________________________________________________________________________________________
sample 604 ms submission
class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        if not grid or not grid[0]:
            return []
        
        m, n = len(grid), len(grid[0])
        EMPTY = 0
        BRICK = 1
        DROP = 2
        WAIT = 3
        
        def count(x, y):
            cnt = 1
            grid[x][y] = DROP
            
            if x > 0 and grid[x - 1][y] == BRICK:
                cnt += count(x - 1, y)
            if y > 0 and grid[x][y - 1] == BRICK:
                cnt += count(x, y - 1)
            if x + 1 < m and grid[x + 1][y] == BRICK:
                cnt += count(x + 1, y)
            if y + 1 < n and grid[x][y + 1] == BRICK:
                cnt += count(x, y + 1)
            
            return cnt
        
        for x, y in hits:
            if grid[x][y] == BRICK:
                grid[x][y] = WAIT
        
        for y in range(n):
            if grid[0][y] == BRICK:
                count(0, y)
        
        ans = []
        
        for x, y in hits[::-1]:
            if grid[x][y] == WAIT:
                grid[x][y] = BRICK
                
                if (
                    x == 0 or
                    (x > 0 and grid[x - 1][y] == DROP) or 
                    (y > 0 and grid[x][y - 1] == DROP) or 
                    (x + 1 < m and grid[x + 1][y] == DROP) or 
                    (y + 1 < n and grid[x][y + 1] == DROP)
                ):
                    ans.append(count(x, y) - 1)
                else:
                    ans.append(0)
            else:
                ans.append(0)
        
        return ans[::-1]
__________________________________________________________________________________________________
sample 608 ms submission
class Solution:
    """
    T: O(m * n)
    S: O(m * n)
    """
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        if not grid or not grid[0] or not hits:
            return []
        
        m, n, k = len(grid), len(grid[0]), len(hits)
        EMPTY = 0
        BRICK = 1
        ERASURE = 2
        DROPED = 3
        
        def count(x, y):
            grid[x][y] = DROPED
            cnt = 1
            
            if x > 0 and grid[x - 1][y] == BRICK:
                cnt += count(x - 1, y)
            if y > 0 and grid[x][y - 1] == BRICK:
                cnt += count(x, y - 1)
            if x + 1 < m and grid[x + 1][y] == BRICK:
                cnt += count(x + 1, y)
            if y + 1 < n and grid[x][y + 1] == BRICK:
                cnt += count(x, y + 1)
            
            return cnt
        
        for x, y in hits:
            if grid[x][y] == BRICK:
                grid[x][y] = ERASURE
        
        for y in range(n):
            if grid[0][y] == BRICK:
                count(0, y)
        
        ans = [0] * k
        
        for i in range(k - 1, -1, -1):
            x, y = hits[i]
            
            if grid[x][y] == ERASURE:
                grid[x][y] = BRICK
                
                if (
                    (x == 0) or
                    (x > 0 and grid[x - 1][y] == DROPED) or 
                    (y > 0 and grid[x][y - 1] == DROPED) or
                    (x + 1 < m and grid[x + 1][y] == DROPED) or
                    (y + 1 < n and grid[x][y + 1] == DROPED)
                ):
                    ans[i] = count(x, y) - 1
        
        return ans
__________________________________________________________________________________________________
