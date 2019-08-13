__________________________________________________________________________________________________
sample 140 ms submission
from collections import deque
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # DFS
        if not board:
            return 
        m, n = len(board), len(board[0])
        # save the boarder index with nested for loops
        save = [ij for k in range(max(m, n)) for ij in ((0, k), (k, 0),(m-1, k),(k, n-1))]
        while save:
            i, j = save.pop()
            if 0 <= i < m and 0 <= j < n and board[i][j] == "O":
                # set the position to "S"
                board[i][j] = "S"
                # save its neighboring positions for further check
                save += [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]
                
        board[:] = [["XO"[item == "S"] for item in row] for row in board]
__________________________________________________________________________________________________
sample 14120 kb submission
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        m=len(board)
        n=len(board[0])
        if m<=2 or n<=2:
            return 
        check=[]
        openspace=[]
        for row in [0,m-1]:
            for col in range(n):
                if board[row][col]=='O':
                    check.append((row,col))
                    openspace.append((row,col))
        for col in [0, n-1]:
            for row in range(1,m-1):
                if board[row][col]=='O':
                    check.append((row,col))
                    openspace.append((row,col))
        while check:  #save all "O"positions that connected to boarder 'O' to openspace
            currow,curcol=check.pop(0)
            rowchange=[1,-1,0,0]
            colchange=[0,0,1,-1]
            for x,y in zip(rowchange,colchange):
                if currow+x>0 and currow+x<m-1 and curcol+y>0 and curcol+y<n-1 and board[currow+x][curcol+y]=='O' and (currow+x,curcol+y) not in openspace:
                    check.append((currow+x,curcol+y))
                    openspace.append((currow+x,curcol+y))
        for i in range(1,m-1):
            for j in range(1,n-1):
                if (i,j) not in openspace and board[i][j]=='O':
                    board[i][j]='X'
        return     
__________________________________________________________________________________________________
