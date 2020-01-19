__________________________________________________________________________________________________
sample 16 ms submission
class Solution(object):
    def tictactoe(self, moves):
        finalArray = [['1','2','3'],
                      ['4','5','6'],
                      ['7','8','9']]
        
		#map input to array
        count = 1
        for coordinates in moves:
            x = coordinates[0]
            y = coordinates[1]
            if count%2 != 0:
                finalArray[x][y] = 'X'
            else:
                finalArray[x][y] = '0'
            count+=1
		
		#check if there is any winning combination
        count = 0
        for num in range(0,3):
            if finalArray[0][num] == finalArray[1][num] == finalArray[2][num]:
                return checkWinner(finalArray[1][num])
            if finalArray[num][0] == finalArray[num][1] == finalArray[num][2]:
                return checkWinner(finalArray[num][0])
        if (finalArray[0][0] == finalArray[1][1] == finalArray[2][2]) or (finalArray[2][0] == finalArray[1][1] == finalArray[0][2]):
            return checkWinner(finalArray[1][1])
			
		#if no winning combination, check if still pending or draw
        # list1 = ['1','2','3','4','5','6','7','8','9']
        # flat_list = [item for sublist in finalArray for item in sublist]
        # if any(elem in flat_list for elem in list1):
        if len(moves)<9:
            return 'Pending'
        return 'Draw'

def checkWinner (char):
    if char == 'X':
        return 'A'
    else:
        return 'B'
__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        a_plays = []
        b_plays = []

        for i in range(len(moves)):
            if i % 2:
                b_plays.append(moves[i])
            else:
                a_plays.append(moves[i])

        a_win = self.judge_is_win(a_plays)
        b_win = self.judge_is_win(b_plays)

        if a_win:
            return 'A'
        if b_win:
            return 'B'
        if not a_win and not b_win:
            if len(moves) == 9:
                return 'Draw'
            else:
                return 'Pending'


    def judge_is_win(self, moves):
        if len(moves) < 3:
            return False

        v_dict = {}
        h_dict = {}

        for move in moves:
            if v_dict.get(move[0]) is None:
                v_dict[move[0]] = 1
            else:
                v_dict[move[0]] += 1

            if h_dict.get(move[1]) is None:
                h_dict[move[1]] = 1
            else:
                h_dict[move[1]] += 1

        for _, v in v_dict.items():
            if v == 3:
                return True

        for _, v in h_dict.items():
            if v == 3:
                return True

        diagonal1 = diagonal2 = 0

        diagonal_points1 = [[0, 0], [2, 2]]
        diagonal_points2 = [[0, 2], [2, 0]]

        has_center = False

        for move in moves:
            if move in diagonal_points1:
                diagonal1 += 1

            if move in diagonal_points2:
                diagonal2 += 1

            if move[0] == 1 and move[1] == 1:
                has_center = True

        if (diagonal1 == 2 or diagonal2 == 2) and has_center:
            return True

        return False
__________________________________________________________________________________________________
