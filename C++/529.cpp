__________________________________________________________________________________________________
sample 36 ms submission
class Solution {
public:
    const vector<pair<int, int>> move_directions = {
        {-1, 0},
        {-1, -1},
        {0, -1},
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {1, -1}
    };
    
    int minesCount(vector<vector<char>>& board, int i, int j, const int& rows, const int& cols) {
        
        int count = 0;
        for(int istart = max(i - 1, 0); istart < min(i + 2, rows); ++istart) {
            for(int jstart = max(j - 1, 0); jstart < min(j + 2, cols); ++jstart) {
                
                if(board[istart][jstart] == 'M')
                    ++count;
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, const int& rows, const int& cols) {
        if(  i < 0 || i >= rows
          || j < 0 || j >= cols)
            return;
        
        if(board[i][j] != 'E')
            return;
        
        int mines = minesCount(board, i, j, rows, cols);
        
        if(mines > 0) {
            board[i][j] = char('0' + mines);
        }
        else {
            for(auto& direction : move_directions) {
                board[i][j] = 'B';
                dfs(board, i + direction.first, j + direction.second, rows, cols);
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(click.size() < 2)
            return {};
        
        int i = click[0];
		int j = click[1];
	
		int rows = board.size();
		int cols = board[0].size();

		if (board[i][j] == 'M') board[i][j] = 'X';
		else dfs(board, i, j, rows, cols);

		return board;
    }
};

static auto s = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;   
}();
__________________________________________________________________________________________________
sample 15148 kb submission
class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> result = board;
        if(board.empty()) return result;
        std::queue<pair<int, int>> qu;
        int row = click[0];
        int col = click[1];
        if(board[row][col] == 'M'){
            result[row][col] = 'X';
            return result;
        }
        
        qu.emplace(row, col);
        result[row][col] = 'B';
        
        while(!qu.empty()) {
            auto cell = qu.front();
            qu.pop();
            int numMines = 0;
            for(auto d = 0; d < 8; ++d) {
                int row = cell.first + dir[d][0];
                int col = cell.second + dir[d][1];
                if(!isValid(board, row, col)) continue;
                if(result[row][col] == 'M')
                    ++numMines;
            }
            if(numMines > 0) {
                result[cell.first][cell.second] = '0' + numMines;
                continue;
            }
            for(auto d = 0; d < 8; ++d) {
                int row = cell.first + dir[d][0];
                int col = cell.second + dir[d][1];
                if(!isValid(board, row, col)) continue;
                if(result[row][col] == 'E') {
                    result[row][col] = 'B';
                    qu.emplace(row, col);
                }
            }
        }
        return result;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col) {
        return (row >= 0 && row < board.size() && col >=0 && col < board[0].size());
    }
};
__________________________________________________________________________________________________
