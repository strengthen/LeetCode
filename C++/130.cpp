__________________________________________________________________________________________________
24ms
static int desyncio = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();

class Solution {
    void setAlive(vector<vector<char>>& board, int x, int y){
        if (!board[x][y]) return;
        
        board[x][y] = 0;
        if (x > 0 && board[x - 1][y] == 'O') setAlive(board, x - 1, y);
        if (y > 0 && board[x][y - 1] == 'O') setAlive(board, x, y - 1);
        if (x + 1 < board.size() && board[x + 1][y] == 'O') setAlive(board, x + 1, y);
        if (y + 1 < board[0].size()  && board[x][y + 1] == 'O') setAlive(board, x, y + 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int height = board.size();
        int width = board[0].size();
        
        if (height == 1 || width == 1) return;
        for(int i = 0; i < width; ++i){
            if (board[0][i] == 'O') setAlive(board, 0, i);
            if (board[height - 1][i] == 'O') setAlive(board, height - 1, i);
        }   
        for(int i = 1; i < height - 1; ++i){
            if (board[i][0] == 'O') setAlive(board, i, 0);
            if (board[i][width - 1] == 'O') setAlive(board, i, width - 1);
        }   
            
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if (!board[i][j]){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
__________________________________________________________________________________________________
13884 kb
auto gucciGang = []() {std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
private:
	void solve(vector<vector<char>>& board, int i, int j) {
		if (i >= 0 && i < (int)board.size() && j >= 0 && j < (int)board[i].size() && board[i][j] == 'O') {
			board[i][j] = '!';
			solve(board, i, j - 1);
			solve(board, i, j + 1);
			solve(board, i - 1, j);
			solve(board, i + 1, j);
		}
	}
public:
	void solve(vector<vector<char>>& board) {
		int m, n;
		if ((m = board.size() - 1) >= 0 && (n = board[0].size() - 1) >= 0) {
			for (int i = 0; i <= m; ++i) {
				solve(board, i, 0);
				solve(board, i, n);
			}
			for (int i = 0; i <= n; ++i) {
				solve(board, 0, i);
				solve(board, m, i);
			}
			for (int i = 0; i <= m; ++i) {
				for (int j = 0; j <= n; ++j) {
					if (board[i][j] == 'O') {
						board[i][j] = 'X';
					}
					else if (board[i][j] == '!') {
						board[i][j] = 'O';
					}
				}
			}
		}
	}
};
__________________________________________________________________________________________________
