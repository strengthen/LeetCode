__________________________________________________________________________________________________
sample 536 ms submission
class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        
        def goDeep(row, col):
            if A[row][col]:
                A[row][col] = 0
                if row + 1 < len(A):
                    if A[row+1][col]:
                        goDeep(row+1, col)
                if row > 0:
                    if A[row-1][col]:
                        goDeep(row-1, col)
                if col + 1 < len(A[0]):
                    if A[row][col+1]:
                        goDeep(row, col+1)
                if col > 0:
                    if A[row][col-1]:
                        goDeep(row, col-1)
        
        for i in range(len(A)):
            goDeep(i, 0)
            goDeep(i, len(A[0])-1)
        for i in range(len(A[0])):
            goDeep(0, i)
            goDeep(len(A)-1, i)
            
        return sum([sum(i) for i in A])
__________________________________________________________________________________________________
sample 14112 kb submission
class Solution:
    def numEnclaves(self, A: List[List[int]]) -> int:
        if len(A) == 0 or len(A[0]) == 0:
            return 0
        
        m, n = len(A), len(A[0])
        
        directions = [(-1, 0), (0, 1), (1,0), (0,-1)]
        
        def dfs(i, j, A, m, n):
            if i < 0 or i >= m or j < 0 or j >= n or A[i][j] != 1:
                return
            A[i][j] = -1
            for dx, dy in directions:
                dfs(i + dx, j + dy, A, m, n)
                
        for i in range(m):
            dfs(i, 0, A, m, n)
            dfs(i, n-1, A, m, n)
            
        for j in range(1, n - 1):
            dfs(0, j, A, m, n)
            dfs(m-1, j, A, m, n)
            
        count = 0
        for i in range(m):
            for j in range(n):
                count += A[i][j] == 1
                    
        return count
__________________________________________________________________________________________________
