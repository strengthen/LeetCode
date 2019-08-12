__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
                
        def triangulate(triangle: List[List[int]], numRows: int) -> List[List[int]]:
            rowSize = len(triangle)
            if rowSize == numRows + 1:
                return triangle[-1]
            nextRow = [1]        
            for i in range(1, rowSize):
                nextRow.append(triangle[-1][i - 1] + triangle[-1][i])        
            nextRow.append(1)                
            triangle.append(nextRow)
            return triangulate(triangle, numRows)

        return triangulate([[1]], rowIndex)        
__________________________________________________________________________________________________
sample 12816 kb submission
class Solution:
    def getRow(self, rowIndex: int):
        def pasc(cur: int, rowIndex: int, row: List[int]):
            if cur > rowIndex + 1:
                return row
            for i in reversed(range(cur)):
                if i == 0 or i == cur-1:
                    row[i] = 1
                else:
                    row[i] = row[i] + row[i-1]

            pasc(cur+1, rowIndex, row)

        row = [0]*(rowIndex+1)
        pasc(0, rowIndex, row)
        return row
__________________________________________________________________________________________________
