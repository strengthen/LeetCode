__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int sum = 0;
        int row = board.size();
        int col = board[0].size();
        
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                bool flag1 = true, flag2 = true;
                if(board[i][j] == 'X')
                {
                    if(i-1>=0 && board[i-1][j] == 'X') { flag1 = false; }
                    if(j-1>=0 && board[i][j-1] == 'X') { flag2 = false; }
                    if(flag1 && flag2) { ++sum; }
                }
            }
        }
        return sum;
    }
};
static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 9568 kb submission
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int nShips = 0;
        if(board.size() == 0)
            return nShips;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == 'X') {
                    if(i == 0 && j == 0)
                        nShips++;
                    else if(i == 0)
                        nShips+= board[i][j-1] == '.';
                    else if(j == 0)
                        nShips+= board[i-1][j] == '.';
                    else if(board[i-1][j] == '.' && board[i][j-1] == '.')
                        nShips++;
                }
            }
        }
        return nShips;
    }
};
__________________________________________________________________________________________________
