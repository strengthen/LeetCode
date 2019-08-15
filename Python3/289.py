__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        check = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
        def determine(i, j, board):
            live_count = 0
            for xx, yy in check:
                if 0 <= xx + i < len(board) and 0 <= yy + j < len(board[0]):
                    live_count += board[xx+i][yy+j]
            if live_count < 2:
                return 0
            if board[i][j] and (live_count == 2 or live_count == 3):
                return 1
            if board[i][j] and live_count > 3:
                return 0
            if not board[i][j] and live_count == 3:
                return 1
            return 0
        flip_list = []
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] != determine(i, j, board):
                    flip_list.append((i, j))
        for i, j in flip_list:
            board[i][j] = int(not board[i][j])
__________________________________________________________________________________________________
sample 13096 kb submission
class Solution:
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def rules(x,y,board):
            flip=board[x][y]
            live,dead=0,0
            neighbors=[[-1,-1],[0,-1],[1,-1],[-1,0],[1,0],[-1,1],[0,1],[1,1]]
            for p in neighbors:
                p1,p2=(x+p[0],y+p[-1])
                if 0<=p1<len(board) and 0<=p2<len(board[0]):
                    if board[p1][p2]==1 or board[p1][p2]=='@':
                        live+=1
                    else:
                        dead+=1
            if flip==1:
                if live<2 or live>3:
                    flip='@'
            else:
                if live==3:
                    flip='#'
            return flip
        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j]=rules(i,j,board)
        print(board)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]=='@':
                    board[i][j]=0
                elif board[i][j]=='#':
                    board[i][j]=1
__________________________________________________________________________________________________
