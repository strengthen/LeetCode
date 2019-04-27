__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int num_t1=1, num_t2=0;
        for (int row=1; row<board.size(); row++) {
            bool inverted=board[0][0]!=board[row][0];
            for (int col=1; col<board[0].size(); col++) {
                bool identical=board[0][col]==board[row][col];
                if (identical==inverted) return -1;
            }
            inverted ? num_t2++ : num_t1++;
        }
        bool even = board.size()%2==0;
        if ((even && num_t1!=num_t2) || (!even && abs(num_t1-num_t2)>1)) return -1;
        int row_swaps=0;
        bool swap_first=num_t1<=num_t2;
        for (int row=0; row<board.size(); row+=2)
            if ((board[row][0]==board[0][0])==swap_first) row_swaps++;
        if (even) row_swaps = min(row_swaps, (int)(board.size()+1)/2 - row_swaps);
        int col_swaps=0;
        num_t1=1; num_t2=0;
        for (int col=1; col<board[0].size(); col++)
            board[0][col]==board[0][0] ? num_t1++ : num_t2++;
        if ((even && num_t1!=num_t2) || (!even && abs(num_t1-num_t2)>1)) return -1;
        swap_first = num_t1<=num_t2;
        for (int col=0; col<board[0].size(); col+=2)
            if ((board[0][col]==board[0][0])==swap_first) col_swaps++;
        if (even) col_swaps = min(col_swaps, (int)(board[0].size()+1)/2 - col_swaps);
        return row_swaps+col_swaps;
    }
};
__________________________________________________________________________________________________
sample 9968 kb submission

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& b) {
        int N = b.size(), rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (b[0][0]^b[i][0]^b[0][j]^b[i][j]) return -1;
            }
        }
        for (int i = 0; i < N; ++i) {
            rowSum += b[0][i];
            colSum += b[i][0];
            rowSwap += b[i][0] == i % 2;
            colSwap += b[0][i] == i % 2;
        }
        if (N / 2 > rowSum || rowSum > (N + 1) / 2) return -1;
        if (N / 2 > colSum || colSum > (N + 1) / 2) return -1;
        // Example [[1,1,0],[0,0,1],[0,0,1]]
        // rowSwap = 2, colSwap = 1, take even swaps always, because for each swap two things change places
        if (N % 2) {
            if (colSwap % 2) colSwap = N - colSwap;
            if (rowSwap % 2) rowSwap = N - rowSwap;
        }
        else {
            // For N = 6, first column is
            // 1, 1, 1, 0, 0, 0 -> rowSwap = 4. but it's actually 2
            colSwap = min(N - colSwap, colSwap);
            rowSwap = min(N - rowSwap, rowSwap);
        }
        return (colSwap + rowSwap) / 2;
    }
};
__________________________________________________________________________________________________
