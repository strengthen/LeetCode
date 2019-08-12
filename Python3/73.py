__________________________________________________________________________________________________
sample 136 ms submission
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row, col = set(), set()
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    row.add(i)
                    col.add(j)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i in row:
                    matrix[i][j] = 0
                if j in col:
                    matrix[i][j] = 0 
__________________________________________________________________________________________________
sample 13228 kb submission
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        if m == 0:
            return
        n = len(matrix[0])
        
        col_zero = False
        
        for i in range(m):
            if matrix[i][0] == 0:
                col_zero = True
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
                    
                    
                    
        for i in range(1,m):
            for j in range(1,n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
            
        if matrix[0][0] == 0:
            matrix[0] = [0] * n
                
        if col_zero:
            for k in range(m):
                matrix[k][0] = 0
__________________________________________________________________________________________________
