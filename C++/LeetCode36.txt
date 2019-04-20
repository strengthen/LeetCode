__________________________________________________________________________________________________
8ms
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        char cMap[9] = {0}, i, j, p, q, r;
        for (i = 0; i < 9; i++) {
            memset(cMap, 0, 9);
            for (j = 0; j < 9; j++) if (b[i][j] > 46) cMap[b[i][j] - 49]++;
            j = 0;
            while (j < 9 && cMap[j] <= 1) j++;
            if (j != 9) return false;
        }
        for (i = 0; i < 9; i++) {
            memset(cMap, 0, 9);
            for (j = 0; j < 9; j++) if (b[j][i] > 46) cMap[b[j][i] - 49]++;
            j = 0;
            while (j < 9 && cMap[j] <= 1) j++;
            if (j != 9) return false;
        }
        for (p = 3; p <= 9; p += 3) {
            for (q = 3; q <= 9; q += 3) {
                memset(cMap, 0, 9);
                for (i = p - 3; i < p; i++) {
                    for (j = q - 3; j < q; j++)  if (b[i][j] > 46) cMap[b[i][j] - 49]++;
                    j = 0;
                    while (j < 9 && cMap[j] <= 1) j++;
                    if (j != 9) return false;
                }
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int hor[9][9] = {0}, ver[9][9] = {0}, sqr[9][9] = {0};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[i][j];
                if(c != '.') {
                    if(hor[i][c % 9]++) return false;
                    if(ver[j][c % 9]++) return false;
                    if(sqr[(i / 3) * 3 + j / 3][c % 9]++) return false;
                }
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
16ms
static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int* row[9];
        int* col[9];
        int* box[9];
        for(int i = 0; i < 9; i++){
            row[i] = new int[9]{0};
            col[i] = new int[9]{0};
            box[i] = new int[9]{0};
        }
        int bn = 0;
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                int rl = i+3;
                int cl = j+3;
                for(int m = i; m < rl; m++){
                    for(int n = j; n < cl; n++){
                        if(board[m][n] != '.'){
                            int val = board[m][n] - '0' - 1;
                            if(row[m][val] == 1)return false;
                            row[m][val] = 1;
                            if(col[n][val] == 1)return false;
                            col[n][val] = 1;
                            if(box[bn][val] == 1)return false;
                            box[bn][val] = 1;
                        }
                    }
                }
                bn++;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
9352 kb
auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][9] = {0}, col[9][9] = {0}, squ[9][9] = {0};
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i /3* 3 + j / 3;
                    if (row[i][num] || col[j][num] || squ[k][num]) return false;
                    row[i][num] = col[j][num] = squ[k][num] = 1;
                }
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
9376 kb 
auto fast_io =[](){std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = board.size();
        
        std::array<bool, 10> lineSeen { false };
        std::array<bool, 10> colSeen { false };
        std::array<bool, 10> blockSeen { false };
        
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                const int lineBlock = j / 3 + 3 * (i/3);
                const int colBlock =  j % 3 + 3 * (i%3);
                
                const int digitLine = board[i][j] - '0';
                const int digitCol = board[j][i] - '0';
                const int digitBlock = board[lineBlock][colBlock] - '0';
            
                if (digitLine > 0)
                {
                    if (lineSeen[digitLine]) return false;
                    lineSeen[digitLine] = true;
                }
                
                if (digitCol > 0)
                {
                    if (colSeen[digitCol]) return false;
                    colSeen[digitCol] = true;
                }
                
                // block number i, case number j
                if (digitBlock > 0)
                {
                    if (blockSeen[digitBlock]) return false;
                    blockSeen[digitBlock] = true;
                }
            }
            std::fill_n(lineSeen.begin(), 10, false);
            std::fill_n(colSeen.begin(), 10, false);
            std::fill_n(blockSeen.begin(), 10, false);
        }
        
        return true;
    }
};
__________________________________________________________________________________________________