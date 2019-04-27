__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        while (true) {
            vector<pair<int, int>> del;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == 0) continue;
                    int x0 = i, x1 = i, y0 = j, y1 = j;
                    while (x0 >= 0 && x0 > i - 3 && board[x0][j] == board[i][j]) --x0;
                    while (x1 < m && x1 < i + 3 && board[x1][j] == board[i][j]) ++x1;
                    while (y0 >= 0 && y0 > j - 3 && board[i][y0] == board[i][j]) --y0;
                    while (y1 < n && y1 < j + 3 && board[i][y1] == board[i][j]) ++y1;
                    if (x1 - x0 > 3 || y1 - y0 > 3) del.push_back({i, j});
                }
            }
            if (del.empty()) break;
            for (auto a : del) board[a.first][a.second] = 0;
            for (int j = 0; j < n; ++j) {
                int t = m - 1;
                for (int i = m - 1; i >= 0; --i) {
                    if (board[i][j]) swap(board[t--][j], board[i][j]);   
                }
            }
        }
        return board;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
