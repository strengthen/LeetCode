__________________________________________________________________________________________________
sample 468 ms submission
import math
class Solution:
    def imageSmoother(self, M):
        if not M:
            return
        row = len(M)
        col = 0
        if M[0]:
            col = len(M[0])

        copy = [[0]*col for i in range(row)]

        for i in range(1, row-1):
            for j in range(1, col-1):
                copy[i][j] = math.floor((M[i-1][j-1]+M[i-1][j]+M[i-1][j+1]+M[i][j-1]+M[i][j]+M[i][j+1]+M[i+1][j-1]+M[i+1][j]+M[i+1][j+1]) / 9)
        
        if row > 1:
            #first row
            for j in range(1, col-1):
                copy[0][j] =  math.floor((M[0][j-1]+M[0][j]+M[0][j+1]+M[1][j-1]+M[1][j]+M[1][j+1]) / 6)

            #last row
            for j in range(1, col-1):
                copy[row-1][j] =  math.floor((M[row-1][j-1]+M[row-1][j]+M[row-1][j+1]+M[row-2][j-1]+M[row-2][j]+M[row-2][j+1]) / 6)

            if col > 1:
                #first col
                for i in range(1, row-1):
                    copy[i][0] = math.floor((M[i-1][0]+M[i-1][1]+M[i][0]+M[i][1]+M[i+1][0]+M[i+1][1]) / 6)
                #last col
                for i in range(1, row-1):
                    copy[i][col-1] = math.floor((M[i-1][col-2]+M[i-1][col-1]+M[i][col-2]+M[i][col-1]+M[i+1][col-2]+M[i+1][col-1]) / 6)
            else:
                for i in range(1, row-1):
                    copy[i][0] =  math.floor((M[i-1][0]+M[i][0]+M[i+1][0]) / 3)
        else:
            #one row
            for j in range(1, col-1):
                copy[0][j] =  math.floor((M[0][j-1]+M[0][j]+M[0][j+1]) / 3)

        #4 corners
        if row > 1:
            if col > 1:
                copy[0][0] = math.floor((M[0][0]+M[0][1]+M[1][0]+M[1][1]) / 4)
                copy[0][col-1] = math.floor((M[0][col-2]+M[0][col-1]+M[1][col-2]+M[1][col-1]) / 4)
                copy[row-1][0] = math.floor((M[row-2][0]+M[row-2][1]+M[row-1][0]+M[row-1][1]) / 4)
                copy[row-1][col-1] = math.floor((M[row-2][col-2]+M[row-2][col-1]+M[row-1][col-2]+M[row-1][col-1]) / 4)
            else:
                copy[0][0] = math.floor((M[0][0]+M[1][0]) / 2)
                copy[row-1][0] = math.floor((M[row-2][0]+M[row-1][0]) / 2)
        else:
            if col > 1:
                copy[0][0] = math.floor((M[0][0]+M[0][1]) / 2)
                copy[0][col-1] = math.floor((M[0][col-2]+M[0][col-1]) / 2)
            else:
                copy[0][0] = M[0][0]

        return copy
__________________________________________________________________________________________________
sample 13504 kb submission
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        R, C = len(M), len(M[0])
        ans = [[0] * C for _ in M]
        for r in range(R):
            for c in range(C):
                count = 0
                for nr in (r-1, r, r+1):
                    for nc in (c-1, c, c+1):
                        if 0 <= nr < R and 0 <= nc < C:
                            ans[r][c] += M[nr][nc]
                            count += 1
                ans[r][c] //= count
        return ans        
__________________________________________________________________________________________________
