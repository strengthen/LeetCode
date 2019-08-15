__________________________________________________________________________________________________
sample 112 ms submission
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        
        if matrix == [[]] or matrix == []:
            self.matrix_sum = [[0]]
            return
        
        a, b = len(matrix), len(matrix[0])
        self.matrix_sum = [[0 for i in range(b+1)] for j in range(a+1)]
        self.matrix_sum[0][0] = matrix[0][0]
        for i in range(a):
            for j in range(b):
                self.matrix_sum[i][j] = matrix[i][j] + self.matrix_sum[i-1][j] + self.matrix_sum[i][j-1] - self.matrix_sum[i-1][j-1]   
        #print(self.matrix_sum)

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.matrix_sum[row2][col2] - self.matrix_sum[row1-1][col2] - self.matrix_sum[row2][col1-1] + self.matrix_sum[row1-1][col1-1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
__________________________________________________________________________________________________
sample 14864 kb submission
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
    
        self.matrix = matrix
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        
        return sum([sum(self.matrix[row][col1: col2 + 1]) for row in range(row1, row2 + 1)])
__________________________________________________________________________________________________
