__________________________________________________________________________________________________
4ms
class Solution
{
public:
  vector<bitset<9>> rm = vector<bitset<9>>(9);
  vector<uint8_t> rmSize = vector<uint8_t>(9);
  vector<bitset<9>> cm = vector<bitset<9>>(9);
  vector<uint8_t> cmSize = vector<uint8_t>(9);
  vector<vector<bitset<9>>> gm = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3));
  vector<vector<uint8_t>> gmSize = vector<vector<uint8_t>>(3, vector<uint8_t>(3));

  vector<uint8_t> cis;
  struct MyComp
  {
    Solution& m_s;
    MyComp(Solution& s) : m_s(s)
    {
    }

    bool operator() (uint8_t& ci1, uint8_t&ci2)
    {
      auto r1 = ci1 / 9;
      auto c1 = ci1 % 9;
      auto r2 = ci2 / 9;
      auto c2 = ci2 % 9;
      return
        (m_s.rmSize[r1] + m_s.cmSize[c1] + m_s.gmSize[r1 / 3][c1 / 3]) <
        (m_s.rmSize[r2] + m_s.cmSize[c2] + m_s.gmSize[r2 / 3][c2 / 3]);
    }
  };


  void solveSudoku(vector<vector<char>>& board)
  {
    for (uint8_t r = 0; r < board.size(); r++)
    {
      for (uint8_t c = 0; c < board.size(); c++)
      {
        if (board[r][c] != '.')
        {
          uint8_t v = board[r][c] - '1';
          rm[r][v] = true;
          ++rmSize[r];
          cm[c][v] = true;
          ++cmSize[c];
          gm[r / 3][c / 3][v] = true;
          ++gmSize[r/3][c/3];
        }
        else
        {
          cis.push_back(r * 9 + c);
        }
      }
    }

    TestInt(board);
  }

  bool TestInt(vector<vector<char>>& board)
  {
    if (cis.empty()) return true;

    auto maxIt = std::max_element(cis.begin(), cis.end(), MyComp(*this));
    std::swap(*maxIt, *(cis.end() - 1));
    auto ci = cis.back();
    cis.pop_back();
    auto r = ci / 9;
    auto c = ci % 9;

    for (uint8_t i=0; i<9; i++)
    {
      if (!rm[r][i] && !cm[c][i] && !gm[r / 3][c / 3][i])
      {
        board[ci / 9][ci % 9] = '1' + i;
        rm[r][i] = true;
        ++rmSize[r];
        cm[c][i] = true;
        ++cmSize[c];
        gm[r / 3][c / 3][i] = true;
        ++gmSize[r/3][c/3];

        if (TestInt(board))
          return true;
        board[ci / 9][ci % 9] = '.';
        rm[r][i]=false;
        --rmSize[r];
        cm[c][i]=false;
        --cmSize[c];
        gm[r / 3][c / 3][i]=false;
        --gmSize[r/3][c/3];
      }
    }

    cis.push_back(ci);

    return false;
  }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    bool check(vector<vector<char>> &board, int i, int j, char val)
{
    int row = i - i%3, column = j - j%3;
    for(int x=0; x<9; x++) if(board[x][j] == val) return false;
    for(int y=0; y<9; y++) if(board[i][y] == val) return false;
    for(int x=0; x<3; x++)
    for(int y=0; y<3; y++)
        if(board[row+x][column+y] == val) return false;
    return true;
}
bool solveSudoku(vector<vector<char>> &board, int i, int j)
{
    if(i==9) return true;
    if(j==9) return solveSudoku(board, i+1, 0);
    if(board[i][j] != '.') return solveSudoku(board, i, j+1);

    for(char c='1'; c<='9'; c++)
    {
        if(check(board, i, j, c))
        {
            board[i][j] = c;
            if(solveSudoku(board, i, j+1)) return true;
            board[i][j] = '.';
        }
    }
        
    return false;
}
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    
    //检查当前i，j位置放置val是否符合要求
    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        int row = i - i%3, column = j - j%3;
        for(int x=0; x<9; x++) if(board[x][j] == val) return false;
        for(int y=0; y<9; y++) if(board[i][y] == val) return false;
        for(int x=0; x<3; x++)
            for(int y=0; y<3; y++)
                if(board[row+x][column+y] == val) return false;
        return true;
    }
    
    // 
    bool solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        
        if(i==9) return true;  
        if(j==9) return solveSudoku(board, i+1, 0);
        // 如果当前i,j已经有值的话，说明是输入给的固定的数，我们应该去判断下一位
        if(board[i][j] != '.') return solveSudoku(board, i, j+1);

        for(char c='1'; c<='9'; c++)
        {
            if(check(board, i, j, c))
            {
                board[i][j] = c;
                if(solveSudoku(board, i, j+1)) return true;
            }
        }
        //如果当前i,j放置什么值都不行的话，说明问题出现在前面，需要将i,j置回成"."，否则重新判断时，i,j位置上会已经有值了
        board[i][j] = '.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
};
__________________________________________________________________________________________________
8496 kb
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
        memset(c,0,sizeof(c));
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]=='.')
                    v.push_back(pair<int,int>(i,j));
                else
                    c[i][j]=1<<(board[i][j]-'0'-1);
        dfs(0);
        for(int i=0;i<v.size();i++)
            board[v[i].first][v[i].second]=getValue(c[v[i].first][v[i].second]);
	}
private:
    bool dfs(int d)
    {
        int i = v[d].first, j = v[d].second;
		int f =  ((1<<9) -1); 
        for (int k = 0; k < 9; k++)
            f&=(~c[i][k])&(~c[k][j]&(~c[3*(i/3)+k/3][3*(j/3)+k%3]));
		while (f) {
            c[i][j] = f & (-f);
            f ^= c[i][j];
			if(d+1 < v.size() && !dfs(d+1)) continue ;
			else return true;
		}
        c[i][j] = 0;
        return false;
    }
    char getValue(int num)
    {
        int count=0;
        while(num)
        {
            count++;
            num=num>>1;
        }
        return count+'0';
    }
    int c[9][9];
	vector<pair<int, int>> v;
};
__________________________________________________________________________________________________
8552 kb
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char v){
        for(int i=0; i<9; i++) {
            if(board[i][c] == v) return false;
        }
        for(int j=0; j<9; j++) {
            if(board[r][j] == v) return false;
        }
        int startr = (r/3)*3;
        int startc = (c/3)*3;
        for(int i=startr; i<startr + 3; i++){
            for(int j=startc; j<startc + 3; j++){
                if(board[i][j] == v){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool sodukuHelper(vector<vector<char>>& board, int r, int c){
        if(c==8){
            if(r == 8){
                if(board[r][c] != '.'){
                    return true;
                }
                
                for(char n='1'; n<='9'; n++){
                    if(isValid(board, r, c, n)){
                        board[r][c] = n;
                        return true;
                    }
                }
                
                return false;
            }
            r++;
            c = 0;
        } else {
            c++;
        }
        
        if(board[r][c] != '.')
            return sodukuHelper(board, r, c);
            
        for(char n='1'; n<='9'; n++){
            if(isValid(board, r, c, n)){
                board[r][c] = n;
                if(sodukuHelper(board, r, c))
                    return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        sodukuHelper(board, 0, -1);
    }
};
__________________________________________________________________________________________________