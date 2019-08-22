__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    x0, y0 = i, j
        res = 0
        for i, j in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
            x, y = x0+i, y0+j
            while 0 <= x <8 and 0<= y <8:
                if board[x][y] == 'p': res +=1
                if board[x][y] != '.': break
                x, y = x+i, y+j
        return res
__________________________________________________________________________________________________
sample 13052 kb submission
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        
        result = 0
        pos = 0
        for r in range(8):
            if "R" in board[r]:
                q = board[r].index("R")
            else:
                continue
                
            if q >= 0:
                for i in range(q+1,8):
                    if (board[r][i] != "p" and board[r][i] != "."):
                        break
                    
                    if board[r][i] == "p":
                        result += 1
                        break
                
                for i in range(q-1, -1, -1):
                    if (board[r][i] != "p" and board[r][i] != "."):
                        break
                        
                    if board[r][i] == "p":
                        result += 1
                        break
                    
                break
                
        for i in range(r+1,8):
            if (board[i][q] != "p" and board[i][q] != "."):
                break

            if board[i][q] == "p":
                result += 1
                break

        for i in range(r-1, -1, -1):
            if (board[i][q] != "p" and board[i][q] != "."):
                break

            if board[i][q] == "p":
                result += 1
                break

        return result
__________________________________________________________________________________________________
