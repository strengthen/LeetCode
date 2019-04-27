__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool check(vector<string>& board) {
        int Xnum = 0;
        int Onum = 0;
        for(int i=0; i<board.size(); ++i) {
            for(int j=0; j<board.size(); ++j) {
                if(board[i][j] == 'X') {
                    Xnum += 1;
                } else if(board[i][j] == 'O') {
                    Onum += 1;
                }
            }
        }
        if(Xnum - Onum != 0 && Xnum - Onum != 1) return false;
        bool Xwin = false;
        bool Owin = false;
        for(int i=0; i<board.size(); ++i) {
            if(board[i][1] == board[i][0] && board[i][2] == board[i][0]) {
                if(board[i][0] == 'X') Xwin = true;
                if(board[i][0] == 'O') Owin = true;
            }
            if(board[1][i] == board[0][i] && board[2][i] == board[0][i]) {
                if(board[0][i] == 'X') Xwin = true;
                if(board[0][i] == 'O') Owin = true;
            }
        }
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            if(board[0][0] == 'X') Xwin = true;
            if(board[0][0] == 'O') Owin = true;
        }
        if(board[0][2] == board[1][1] && board[2][0] == board[1][1]) {
            if(board[1][1] == 'X') Xwin = true;
            if(board[1][1] == 'O') Owin = true;
        }
        if(Xwin && Owin) return false;
        if(Xwin && Xnum == Onum) return false;
        if(Owin && Xnum != Onum) return false;
        return true;
    }
    bool validTicTacToe(vector<string>& board) {
        return check(board);
    }
};
__________________________________________________________________________________________________
sample 8612 kb submission
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        bool xwin = false, owin = false;
        vector<int> row(3), col(3);
        int diag = 0, antidiag = 0, turns = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X'){
                    ++row[i]; ++col[j]; ++turns;
                    if(i == j)
                        ++diag;
                    if(i + j == 2)
                        ++antidiag;
                }else if(board[i][j] == 'O'){
                    --row[i]; --col[j]; --turns;
                    if(i == j)
                        --diag;
                    if(i + j == 2)
                        --antidiag;
                }
            }
        }
        xwin = row[0] == 3 || row[1] == 3 || row[2] == 3 ||
               col[0] == 3 || col[1] == 3 || col[2] == 3 ||
               diag == 3 || antidiag == 3;
        owin = row[0] == -3 || row[1] == -3 || row[2] == -3 ||
               col[0] == -3 || col[1] == -3 || col[2] == -3 ||
               diag == -3 || antidiag == -3;
        if((xwin && turns == 0) || (owin && turns == 1))
            return false;
        return (turns == 0 || turns == 1) && (!xwin || !owin);
    }
};
__________________________________________________________________________________________________
