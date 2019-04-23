__________________________________________________________________________________________________
4ms
class Solution {
    private:
    bool isSafe(vector<int>& board, int row, int column){
        for(int nc = 0; nc < column; nc++){
            if(board[nc] == row || (board[nc]-row == nc-column) || (board[nc]-row == column-nc)) return false;
        }
        return true;
    }
    void helper(vector<int>& board, int column, int& num_sol){
        if(column == board.size()){num_sol++; return;}
        for(int row = 0; row < board.size(); row++){
            if(isSafe(board, row, column)){
                board[column] = row;
                helper(board, column+1, num_sol);
            }
        }
    }
public:
    int totalNQueens(int n) {
        if(n < 2) return n;
        int num_sol = 0;
        vector<int> board(n, 0);
        helper(board, 0, num_sol);
        return num_sol;
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        totalNQueensDFS(pos, 0, res);
        return res;
    }
    void totalNQueensDFS(vector<int> &pos, int row, int &res) {
        int n = pos.size();
        if (row == n) ++res;
        else {
            for (int col = 0; col < n; ++col) {
                if (isValid(pos, row, col)) {
                    pos[row] = col;
                    totalNQueensDFS(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    bool isSafe(int x1, int y1, int x2, int y2) {
        if(abs(x1-x2)==abs(y1-y2)) return false;
        if((x1 == x2) ||(y1==y2)) return false;
        else return true;
    }
    int totalNQueens(int n, int d, vector< pair<int, int> >& vec) {
        if(d == n){ cout<<"hi"; return 1;
        }
        int sum = 0,temp;
        for(int i=0;i<n;i++) {
         
            vector<pair<int, int>> :: iterator it = vec.begin();
            for(; it !=vec.end(); it++) {
                if(!isSafe(d,i,(*it).first, (*it).second)) {
                    
                    break;
                }    
            }   
         if(it ==vec.end()) {
             vec.push_back(make_pair(d,i));
             temp = totalNQueens(n, d+1, vec);
             if(temp!= -1) sum = sum+ temp;
             vec.pop_back();
         }     
        }
        
        return sum;
    }
        
    int totalNQueens(int n) {
        vector< pair<int, int> > vec;
        int d = 0,temp;
        int sum = 0;
        for(int i=0;i<n;i++) {
           vec.push_back(make_pair(0,i));  
           temp = totalNQueens(n ,d+1, vec);
           if(temp!=-1) sum += temp; 
           vec.pop_back();
        
        }  
        
        return sum;
     }
};
__________________________________________________________________________________________________
8020 kb
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0, shu = 0, pie = 0, na = 0;
        nQueens(count,shu,pie,na,0,n);
        return count;
    }
    
private:
    void nQueens(int &count, int &shu, int &pie, int &na, int row, int n) {
        for (int col = 0; col < n; ++col) {
            int j = row + col, k = n - 1 + col - row;
            if (((shu >> col) | (pie >> j) | (na >> k)) & 1) {
                continue;
            } 
            if (row == n - 1) {
                count += 1;
            } else {
                shu ^= (1 << col); pie ^= (1 << j); na ^= (1 << k);
                nQueens(count,shu,pie,na,row+1,n);
                shu ^= (1 << col); pie ^= (1 << j); na ^= (1 << k);
            }
        }
    }
};
__________________________________________________________________________________________________
8052 kb
class Solution {
    unsigned int mask;
    int res;
    int n;
public:
    int totalNQueens(int n) {
        this->n = n;
        res = 0;
        mask = (1u << n) - 1;
        helper(0, 0, 0, 0); //1 taken, 0 free
        return res;
    }
    
    void helper(int i, unsigned int v, unsigned int l, unsigned int r) {
        if (i >= n) {
            ++res;
            return;
        }
        unsigned int free_cols = mask & ~(l | r | v); //1 free, 0 taken
        while (free_cols) {
            unsigned int cur_taken_col = -free_cols & free_cols; // cur_taken_col = first free bit to 1, others 0       
            helper(i + 1, v | cur_taken_col, (l | cur_taken_col) << 1, (r | cur_taken_col) >> 1);
            free_cols ^= cur_taken_col;
        }        
    }
};
__________________________________________________________________________________________________