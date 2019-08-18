__________________________________________________________________________________________________
sample 288 ms submission
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if matrix==None or len(matrix)==0:
            return[]
        
        m = len(matrix)
        n = len(matrix[0])
        flowRight = []
        for i in range(m):
            flowRight.append([False]*n)
                        
        def checkRight(row, col):
            flowRight[row][col] = True
            if row-1>=0 and flowRight[row-1][col]==False and matrix[row-1][col]>=matrix[row][col]:
                checkRight(row-1, col)
            if col-1>=0 and flowRight[row][col-1]==False and matrix[row][col-1]>=matrix[row][col]:
                checkRight(row, col-1)
            if col+1<n and flowRight[row][col+1]==False and matrix[row][col+1]>=matrix[row][col]:
                checkRight(row, col+1)
            if row+1<m and flowRight[row+1][col]==False and matrix[row+1][col]>=matrix[row][col]:
                checkRight(row+1, col)
        
        for i in range(m):
            checkRight(i, n-1)
        for i in range(n):
            checkRight(m-1, i)
            
        
        flowLeft = []
        for i in range(m):
            flowLeft.append([False]*n)
        def checkLeft(row, col):
            flowLeft[row][col] = True
            if row-1>=0 and flowLeft[row-1][col]==False and matrix[row-1][col]>=matrix[row][col]:
                checkLeft(row-1, col)
            if col-1>=0 and flowLeft[row][col-1]==False and matrix[row][col-1]>=matrix[row][col]:
                checkLeft(row, col-1)
            if col+1<n and flowLeft[row][col+1]==False and matrix[row][col+1]>=matrix[row][col]:
                checkLeft(row, col+1)
            if row+1<m and flowLeft[row+1][col]==False and matrix[row+1][col]>=matrix[row][col]:
                checkLeft(row+1, col)
                
        for i in range(m):
            checkLeft(i, 0)
        for i in range(n):
            checkLeft(0, i)
          
        res = []
        for row in range(m):
            for col in range(n):
                if flowRight[row][col] and flowLeft[row][col]:
                    res.append([row,col])
        return res          
__________________________________________________________________________________________________
sample 13820 kb submission
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix: return []
        directions = {(0,1), (0,-1), (1,0), (-1,0)}
        m, n = len(matrix), len(matrix[0])        
        def dfs(stk):
            ocean = set(stk)
            while stk:
                cur = stk.pop()
                for d in directions:
                    i, j = cur[0] + d[0], cur[1] + d[1]
                    if 0 <= i < m and 0 <= j < n and (i, j) not in ocean:
                        if matrix[i][j] >= matrix[cur[0]][cur[1]]:
                            stk.append((i, j))
                            ocean.add((i, j))
            return ocean
        stk1 = [(0, i) for i in range(n)] + [(i, 0) for i in range(1,m)]
        stk2 = [(m-1, i) for i in range(n)] + [(i, n-1) for i in range(m-1)]
        return list(i for i in dfs(stk1) & dfs(stk2))
__________________________________________________________________________________________________
