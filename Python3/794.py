__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def validTicTacToe(self, b: List[str]) -> bool:
    	T, w = {'XXX':0, 'OOO':0}, "".join(b).count('X') - "".join(b).count('O')
    	for i in range(3): T[b[0][i]+b[1][i]+b[2][i]], T[b[i][0]+b[i][1]+b[i][2]] = 1, 1
    	for i in range(2): T[b[0][2*i]+b[1][1]+b[2][2*(1-i)]] = 1
    	return False if (w not in [0,1]) or (T['XXX'] == 1 and w != 1) or (T['OOO'] == 1 and w != 0) else True
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def validTicTacToe(self, b: List[str]) -> bool:
    	T, w, [x,y,z] = {'XXX':0, 'OOO':0}, "".join(b).count('X') - "".join(b).count('O'), b
    	for i in [0,1,2]: T[x[i]+y[i]+z[i]], T[b[i][0]+b[i][1]+b[i][2]], T[x[2*i//2]+y[1]+z[2*(1-i//2)]] = 1, 1, 1
    	return False if (w not in [0,1]) or (T['XXX'] == 1 and w != 1) or (T['OOO'] == 1 and w != 0) else True
__________________________________________________________________________________________________
