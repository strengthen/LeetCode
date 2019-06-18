__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l = len(matrix)
        for i in range(l // 2):
            for j in range(l // 2 + l % 2):
                self.rotate_mat(matrix, i, j)
        
    def rotate_mat(self, matrix, x, y):
        locs = [(x, y)]
        for i in range(3):
            x, y = self.find_next_location(x, y, len(matrix))
            locs.append((x, y))
        self._rotate_element(matrix, locs)
    
    @staticmethod
    def _rotate_element(matrix, locs):
        temp = matrix[locs[3][0]][locs[3][1]]
        for i in range(4):
            matrix[locs[i][0]][locs[i][1]], temp = temp, matrix[locs[i][0]][locs[i][1]]
        
        
    @staticmethod
    def find_next_location(x, y, length):
        l = (length - 1) / 2
        x -= l
        y -= l
        x, y = y, -x
        x += l
        y += l
        return int(x), int(y)        
__________________________________________________________________________________________________
sample 12744 kb submission
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(len(matrix)):
            for j in range(i,len(matrix[0])):
                matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
                
        for i in matrix:
            i.reverse()
__________________________________________________________________________________________________
