__________________________________________________________________________________________________
sample 156 ms submission
import collections

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not word:
            return False

        bcnts = collections.Counter(c for x in board for c in x)
        
        for c, cnt in collections.Counter(word).items():
            if c not in bcnts or cnt > bcnts[c]:
                return False
            
        width = len(board[0])
        height = len(board)

        def dfs(row, col, word):
            visited[(row,col)] = 1
            if not word:
                return True
            temp = board[row][col]
            board[row][col] = ''
            if (row > 0 and board[row - 1][col] == word[0] and dfs(row - 1, col, word[1:])) \
            or (row < height-1 and board[row + 1][col] == word[0] and dfs(row + 1, col, word[1:])) \
            or (col > 0 and board[row][col-1] == word[0] and dfs(row, col-1, word[1:])) \
            or (col < width-1 and board[row][col+1] == word[0] and dfs(row, col+1, word[1:])):
                return True
            board[row][col] = temp
            
        for row in range(height):
            for col in range(width):
                visited = {}
                if board[row][col] == word[0]:
                    ret = dfs(row,col,word[1:])
                    if ret:
                        return True
        return False
__________________________________________________________________________________________________
sample 13896 kb submission
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
    
        rows = len(board)
        if rows == 0:
          return False

        cols = len(board[0])
        if cols == 0:
          return False

        for i in range(rows):
          for j in range(cols):
            result = self.searchWord(board, rows, cols, word, 0, i, j)
            if result:
              return True
        return False

    def searchWord(self, board: List[List[str]], rows: int, cols: int, word: str, letter:int, row: int, col: int) -> bool:

        if col < 0 or col >= cols or row < 0 or row >= rows:
          return False

        boardLetter = board[row][col]
        if word[letter] == boardLetter:

          if letter == len(word) - 1:
            return True

          board[row][col] = '#'

          result = \
            self.searchWord(board, rows, cols, word, letter + 1, row + 1, col) or \
              self.searchWord(board, rows, cols, word, letter + 1, row - 1, col) or \
                self.searchWord(board, rows, cols, word, letter + 1, row, col + 1) or \
                  self.searchWord(board, rows, cols, word, letter + 1, row, col - 1)

          board[row][col] = boardLetter
          if result:
            return True

        return False        
__________________________________________________________________________________________________
