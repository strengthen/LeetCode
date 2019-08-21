__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        
        for i in range(len(matrix)-1):
            if (matrix[i][0:len(matrix[0])-1] != 
                matrix[i+1][1:len(matrix[0])]):
                return False
        
        return True
__________________________________________________________________________________________________
sample 13028 kb submission
import sys

class Solution:
    def isToeplitzMatrix(self, A: List[List[int]]) -> bool:
        m, n = len(A), len(A[0])
        for i in range(m):
            for j in range(n):
                if A[i][j] == -sys.maxsize:
                    continue
                k, l = i+1, j+1
                while k < m and l < n:
                    if A[k-1][l-1] == A[k][l]:
                        A[k-1][l-1] = -sys.maxsize
                        k, l = k+1, l+1                        
                    else:
                        return False
        return True
__________________________________________________________________________________________________
