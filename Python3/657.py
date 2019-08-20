__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        return (moves.count("U") == moves.count("D")) and (moves.count("L") == moves.count("R"))

__________________________________________________________________________________________________
sample 13044 kb submission
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        yaxis = 0
        xaxis = 0
        for move in moves:
            if move == 'U':
                yaxis += 1
            elif move == 'D':
                yaxis -= 1
            elif move == 'R':
                xaxis += 1
            elif move == 'L':
                xaxis -= 1
        return True if xaxis == 0 and yaxis == 0 else False
__________________________________________________________________________________________________
