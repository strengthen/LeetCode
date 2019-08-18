__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        if len(board[0]) == 0:
            return 0
        board = ["".join(x).replace(".X", ".S") for x in board]
        board.append("." * len(board[0]))
        board = list(zip(*board))
        return sum(["".join(x).count('S.') for x in board])\
            + "".join(board[0]).count(".X") \
            + (board[0][0] == 'X')                
__________________________________________________________________________________________________
sample 13104 kb submission
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        ans = 0
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == 'X':
                    if i == 0 or board[i-1][j] != 'X':
                        if j == 0 or board[i][j-1] != 'X': 
                            ans += 1
        return ans
__________________________________________________________________________________________________
