__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    // use second bit to store new information
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live_n = 0;
                for (int k = i-1; k <= i+1; k++) {
                    for (int l = j-1; l <= j+1; l++) {
                        if (k < m && k >= 0 &&
                            l < n && l >= 0 && 
                            !(k == i && l == j)) {
                            live_n += (1 & board[k][l]);
                        }
                    }
                }
                int new_state = board[i][j];
                if (board[i][j] == 1) {
                    if (live_n < 2) {
                        new_state = 0;
                    } else if (live_n <= 3) {
                        new_state = 1;
                    } else if (live_n > 3) {
                        new_state = 0;
                    }
                } else if (live_n == 3) {
                    new_state = 1;
                }
                board[i][j] += (new_state << 1);
            }
        }
        
        // right shift 1 bit to get new state
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
__________________________________________________________________________________________________
sample 8616 kb submission
class Solution
{
public:
    int CountNeighborLives(vector<vector<int>>& board, int row, int col)
    {
        int count = 0;
        int last_row = board.size() - 1;
        int last_col = board[0].size() - 1;

        for(int i = max(row - 1, 0); i <= min(row + 1, last_row); i++)
        {
            for(int j = max(col - 1, 0); j <= min(col + 1, last_col); j++)
            {
                if(i == row && j == col)
                    continue;
                
                count += board[i][j] & 1;
            }
        }
        
        return count;
    }
    
    void gameOfLife(vector<vector<int>>& board)
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                int neighbor_lives = CountNeighborLives(board, i, j);
                
                board[i][j] = ((board[i][j] == 0 && neighbor_lives == 3) ||
                               (board[i][j] == 1 && (neighbor_lives == 2 || neighbor_lives == 3))) ?
                    (board[i][j] | 2) : board[i][j];
            }
        }
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                board[i][j] = board[i][j] >> 1;
            }
        }                
    }
};
__________________________________________________________________________________________________
