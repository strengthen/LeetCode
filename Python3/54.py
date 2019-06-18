__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if matrix==[] or matrix[0]==[]:
            return []
        else:
            row = len(matrix)-1
            col = len(matrix[0])-1
            def nextInd(i,j,row,col):
                if i<=row/2 and i-j<=1 and i+j<col:
                    #go right
                    return i,j+1
                elif j>=col/2 and i+j>=col and i-j<row-col:
                    #go down
                    return i+1,j
                elif i>row/2 and i-j>=row-col and i+j>row:
                    #go left
                    return i,j-1
                elif j<col/2 and i+j<=row and i-j>1 :
                    #go up
                    return i-1,j
            opt=[]
            i = 0
            j = 0
            for k in range((row+1)*(col+1)):
                print(i,j)
                opt.append(matrix[i][j])
                if k < (row+1)*(col+1)-1:
                    i,j = nextInd(i,j,row,col)
            return opt
__________________________________________________________________________________________________
sample 12616 kb submission
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)  
        if n == 0:
            return []
        m = len(matrix[0])
        if m == 0:
            return[]
        result = []
        i,j = 0,0
        start_i,start_j = 0,0
        end_i,end_j = n-1,m-1
        while True:
            #right
            if start_j <= end_j:
                result+=([matrix[i][x] for x in range(start_j,end_j+1)])
                start_i+=1
                j = end_j
            else:
                break
            #down
            if start_i <= end_i:
                result+=[matrix[x][j] for x in range(start_i,end_i+1)]
                end_j -= 1
                i = end_i
            else:
                break
            # left
            if start_j <= end_j:
                result += [matrix[i][x] for x in reversed(range(start_j, end_j + 1))]
                end_i -= 1
                j = start_j
            else:
                break
            # up
            if start_i <= end_i:
                result += [matrix[x][j] for x in reversed(range(start_i, end_i + 1))]
                start_j += 1
                i = start_i
            else:
                break
        return result
__________________________________________________________________________________________________
