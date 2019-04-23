__________________________________________________________________________________________________
4ms
class Solution {
public:
    void dfs(int n, vector<vector<string>> &res, vector<string> &cur_rowstr, int row, int col, int pie, int na) {
        if(row >= n) {
            res.push_back(cur_rowstr);
            return;
        }
        
        int bits = (~ (col | pie | na)) & ((1<<n) - 1); // 获得可放置的空位
        
        while(bits) {
            int p = bits & -bits; // 获得最低位的可放置的空位
            int str_col = (int)log2((double)p);
            cur_rowstr[row][str_col] = 'Q'; // 处理cur_rowstr, 放入Queen
            
            dfs(n, res, cur_rowstr, row+1, col | p, (pie | p) << 1, (na | p) >> 1);  
            
            cur_rowstr[row][str_col] = '.'; // 恢复cur_rowstr
            bits &= (bits - 1);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        //if(n < 1)
            //return res;        
        vector<string> row_str(n, string(n, '.'));
        dfs(n, res, row_str, 0, 0, 0, 0);        
        return res;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        col = vector<bool>(n,false);
        dia1 = vector<bool>(2*n-1,false);
        dia2 = vector<bool>(2*n-1,false);
        
        vector<int> row;
        putQueen(n,0,row);
        
        
            return res;
    }
private:
    vector<vector<string>> res;
    vector<bool> col,dia1,dia2;
    
    
    //尝试在一个n皇后问题中 摆放第index行的皇后位置
    void putQueen(int n,int index,vector<int>& row)//( n queens,当前处理的行，row[行] = 列  每一行 皇后摆放在第几列)
    {
        if(index == n)
        {
            res.push_back(generateBoard(n,row));
            return;
        }
        
        for(int i= 0;i < n;++i)
            //尝试将第index行的皇后摆放在第i列
            if(!col[i] && !dia1[index + i] && !dia2[index-i+n-1])
            {
                row.push_back(i);
                col[i] = true;
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                putQueen(n,index + 1,row);
                
                col[i] = false;
                dia1[index+i] = false;
                dia2[index-i+n-1] = false;
                row.pop_back();
            }
        return;
    }
    vector<string> generateBoard(int n,vector<int>& row)
    {
        assert(row.size() == n);
        vector<string> board(n,string(n,'.'));
        for(int i = 0;i < n;++i)
            board[i][row[i]] = 'Q';
        return board;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		if (n == 0)return { {} };

		N = n;

		vector<vector<string>> ans;
		vector<int> col(n, 0);
		vector<int> diag1(2 * n - 1, 0);
		vector<int> diag2(2 * n - 1, 0);

		vector<string> temp(n, "");

		for (int i = 0; i < n; i++) {
			placeQueens(0, i, temp, ans, col, diag1, diag2);
		}

		return ans;
	}

private:
	int N;
	void placeQueens(int x, int y, vector<string>& temp, vector<vector<string>>& ans
		, vector<int>& col, vector<int>& diag1, vector<int>& diag2) {
		if (x == N - 1) {
			temp[x].insert(0, y, '.');
			temp[x] += "Q";
			temp[x].insert(y + 1, N - y - 1, '.');
			ans.push_back(temp);
			temp[x].clear();
			return;
		}


		col[y] = 1; diag1[x + y] = 1; diag2[x - y + N - 1] = 1;
		temp[x].insert(0, y, '.');
		temp[x] += "Q";
		temp[x].insert(y + 1, N - y - 1, '.');

		for (int i = 0; i < N; i++) {
			if (!col[i] && !diag1[x + 1 + i] && !diag2[x - i + N]) {
				placeQueens(x + 1, i, temp, ans, col, diag1, diag2);
			}
		}

		col[y] = 0; diag1[x + y] = 0; diag2[x - y + N - 1] = 0;
		temp[x].clear();
	}
};
__________________________________________________________________________________________________
9688 kb
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n,string(n,'.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string>> &res, vector<string> &nQueens, int row, int &n){
        if(row==n){
            res.push_back(nQueens);
            return;
        }
        for(int col=0; col<n; col++){
            if(isValid(nQueens, row, col, n)){
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row+1, n);
                nQueens[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string> &nQueens, int row, int col, int &n){
        //check if the colum had a queen before.
        for(int i=0;i<row;++i){//i++语句是需要一个临时变量取存储返回自增前的值，而++i不需要。两者结果相同。
            if(nQueens[i][col]=='Q')
                return false;
        }
        //check if the 45° diagonal had a queen before.
        for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j){
            if(nQueens[i][j] == 'Q')
                return false;
        }
        //check if the 135° diagonal had a queen before.
        for(int i=row-1,j=col+1;i>=0&&j<n; --i,++j){
            if(nQueens[i][j]=='Q')
                return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
9724 kb
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        y_bit = a_bit = b_bit = 0;
        for (int i = 0; i < n; i++) {
            place.push_back(string(n, '.'));
        }
        vector<vector<string>> res;
        DO(n, 0, res);
        return res;
    }
    void DO(int n, int x, vector<vector<string>> & res)
    {
        if (x == n) {
            res.push_back(place);
            return;
        }

        for (int y = 0; y < n; y++) {
            if (IsOk(n, x, y))
            {
                Set(n, x, y);
                DO(n, x + 1, res);
                Del(n, x, y);
            }
        }
    }

    bool IsOk(int n, int x, int y)
    {
        if (y_bit & (1 << y)) return false;
        if (a_bit & (1 << (x - y + n))) return false;
        if (b_bit & (1 << (x + y))) return false;
        return true;
    }

    void Set(int n, int x, int y)
    {
        y_bit |= (1 << y);
        a_bit |= (1 << (x - y + n));
        b_bit |= (1 << (x + y));
        place[x][y] = 'Q';
    }

    void Del(int n, int x, int y)
    {
        y_bit &= ~(1 << y);
        a_bit &= ~(1 << (x - y + n));
        b_bit &= ~(1 << (x + y));
        place[x][y] = '.';
    }

private:
    long long y_bit;
    long long a_bit; // i - j + MAX;
    long long b_bit; // i + j;
    vector<string> place;
};
__________________________________________________________________________________________________