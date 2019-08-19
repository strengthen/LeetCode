__________________________________________________________________________________________________
sample 196 ms submission
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        
        
        if len(matrix) == 0:
            return []
        
        if len(matrix) == 1:
            return matrix[0]
        
        diagOrder = [0] * (len(matrix)*len(matrix[0]))
        
        r1 = 0
        r2 = len(matrix) -1
        index = 0
        col1 = 0
        col2 = len(matrix[0])-1
        
        while(r1 <=r2 and col1 <= col2):
            while(r1>=0 and col1 <= col2):
                diagOrder[index] = matrix[r1][col1]
                r1 -= 1
                index += 1
                col1 += 1
            r1 += 1
            if(col1 > col2):
                col1 -= 1
                r1 += 1
            
            while(r1<=r2 and col1>=0):
                diagOrder[index] = matrix[r1][col1]
                r1 += 1
                index += 1
                col1 -= 1
            col1 += 1
            
            if(r1 > r2):
                r1 -= 1
                col1 += 1
        
        return diagOrder        
__________________________________________________________________________________________________
sample 15188 kb submission
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0 or len(matrix[0])==0:
            return []
        m,n = len(matrix), len(matrix[0])
        rst = []
        for total in range(0, m+n):
            if total%2==1:
                for i in range(max(0,total-n+1),min(total+1,m)):
                    rst.append(matrix[i][total-i])
            else:
                for i in range(min(total,m-1),max(-1,total-n),-1):
                    rst.append(matrix[i][total-i])
        return rst
__________________________________________________________________________________________________
