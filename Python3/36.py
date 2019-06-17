__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        ds = {}
        for i in range(9):
            for j in range(9):
                cur = board[i][j]
                if cur != '.':
                    if cur in ds:
                        for x in ds[cur]:
                            if x[0] == i or x[1] ==j or (x[0]//3 == i//3 and x[1]//3 == j//3):
                                return False
                        ds[cur].append((i, j))
                    else:
                        ds[cur] = [(i, j)]
        return True
__________________________________________________________________________________________________
sample 12772 kb submission
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        
        
        boardT = list(zip(*board))

        sub_box = []
        for i in range(0, 9):
            for j in range(0, 9):

                if i%3==0 and j%3==0:
                    sub_box.append(board[i][j:j+3])
                    sub_box.append(board[i+1][j:j + 3])
                    sub_box.append(board[i+2][j:j + 3])

                    if not self.uniqueValues(sub_box):
                        return False
                    else:
                        sub_box = []
                
            if not self.uniqueValues([board[i]]) or not self.uniqueValues([boardT[i]]):
                return False
            
            
        return True
        
    def uniqueValues(self, nums):

        isBefore = set()
        for box in nums:
            for x in box:
                if x=='.':
                    continue
                if x in isBefore:
                    return False
                isBefore.add(x)

        return True
__________________________________________________________________________________________________
