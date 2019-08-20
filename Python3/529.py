__________________________________________________________________________________________________
sample 196 ms submission
class Solution:
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        if not board:
            return []

        m, n = len(board), len(board[0])
        i, j = click[0], click[1]

        # If a mine ('M') is revealed, then the game is over - change it to 'X'.
        if board[i][j] == 'M':
            board[i][j] = 'X'
            return board

        # run dfs to reveal the board
        self.dfs(board, i, j)
        return board

    def dfs(self, board, i, j):
        if board[i][j] != 'E':
            return

        m, n = len(board), len(board[0])       
        directions = [(-1,-1), (0,-1), (1,-1), (1,0), (1,1), (0,1), (-1,1), (-1,0)]

        mine_count = 0

        for d in directions:
            ni, nj = i + d[0], j + d[1]
            if 0 <= ni < m and 0 <= nj < n and board[ni][nj] == 'M':        
                mine_count += 1

        if mine_count == 0:
            board[i][j] = 'B'
        else:
            board[i][j] = str(mine_count)
            return

        for d in directions:
            ni, nj = i + d[0], j + d[1]
            if 0 <= ni < m and 0 <= nj < n:
                self.dfs(board, ni, nj)
__________________________________________________________________________________________________
sample 13520 kb submission
from collections import deque
class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        nrow = len(board)
        if nrow == 0:
            return board
        ncol = len(board[0])
        if ncol == 0:
            return board
        
        [r, c] = click
        if board[r][c] == 'M':
            board[r][c] = 'X'
            return board
        
        q = deque([(r, c)])
        visited = set()
        visited.add((r, c))
        while len(q) > 0:
            (r, c) = q.popleft()
            if board[r][c] == 'E':
                cnt = [0]
                pos = []                
                self.count(board, nrow, ncol, r, c, cnt, pos)
                #print(cnt)
                #print(pos)
                if 0 < cnt[0] <=8:
                    board[r][c] = str(cnt[0])
                else:
                    board[r][c] = 'B'
                    for (x, y) in pos:
                        if (x, y) not in visited:
                            q.append((x, y))
                            visited.add((x, y))
        return board

                

    def count(self, board, nrow, ncol, r, c, cnt, pos):
        neighbors = [(r-1,c-1), (r-1,c), (r-1,c+1), (r,c-1), (r,c+1), (r+1,c-1), (r+1,c), (r+1,c+1)]
        for (x, y) in neighbors:
            if 0 <= x <nrow and 0 <= y <ncol:
                pos.append((x, y))
                if board[x][y] == 'M':
                    cnt[0] += 1
        return
__________________________________________________________________________________________________
