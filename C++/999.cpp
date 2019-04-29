__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
    int i, j, rooki, rookj, flag = 0, ct = 0;
	for(i = 0; i < 8; ++i){
		for(j = 0; j < 8; ++j){
			if(board[i][j] == 'R'){
				rooki = i, rookj = j;
				flag = 1;
				break;
			}
		}
		if(flag) break;
	}
	for(i = rooki + 1, j = rookj; i < 8; ++i){
		if(board[i][j] == 'B') break;
		else if(board[i][j] == 'p'){
			ct++;
			break;
		}
	}
	for(i = rooki - 1, j = rookj; i >= 0; --i){
		if(board[i][j] == 'B') break;
		else if(board[i][j] == 'p'){
			ct++;
			break;
		}
	}
	for(i = rooki, j = rookj + 1; j < 8; ++j){
		if(board[i][j] == 'B') break;
		else if(board[i][j] == 'p'){
			ct++;
			break;
		}
	}
	for(i = rooki, j = rookj - 1; j >= 0; --j){
		if(board[i][j] == 'B') break;
		else if(board[i][j] == 'p'){
			ct++;
			break;
		}
	}
	return ct;    
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int cap(vector<vector<char>>& b, int x, int y, int dx, int dy) {
  while (x >= 0 && x < b.size() && y >= 0 && y < b[x].size() && b[x][y] != 'B') {
    if (b[x][y] == 'p') return 1;
    x += dx, y += dy;
  }
  return 0;
}
int numRookCaptures(vector<vector<char>>& b) {
  for (auto i = 0; i < b.size(); ++i)
    for (auto j = 0; j < b[i].size(); ++j)
      if (b[i][j] == 'R') return cap(b,i,j,0,1)+cap(b,i,j,0,-1)+cap(b,i,j,1,0)+cap(b,i,j,-1,0);
  return 0;
}
};
__________________________________________________________________________________________________
