__________________________________________________________________________________________________
12ms
static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& Board, std::string Word) {
      
      const int WordLen = Word.length();
      if (WordLen < 1)
        return true;
      
      const int RowNum = Board.size();
      if (RowNum < 1)
        return false;
      const int ColNum = Board[0].size();
      if (ColNum < 1)
        return false;
      
      std::function<bool(int,int,int)> BackTrack;
      BackTrack = [&](int Row, int Col, int CharIdx) {
        
        if (CharIdx >= WordLen)
          return true;
        
        const char &WordCh = Word[CharIdx];
        char &BoardCh = Board[Row][Col];
        
        BoardCh = ~BoardCh;
        bool IsMatch = false;
        if (Row > 0 &&
            Board[Row - 1][Col] == WordCh &&
            BackTrack(Row - 1, Col, CharIdx + 1))
          IsMatch = true;
        else if (Col > 0 &&
                 Board[Row][Col - 1] == WordCh &&
                 BackTrack(Row, Col - 1, CharIdx + 1))
          IsMatch = true;
        else if (Row < RowNum - 1 &&
                 Board[Row + 1][Col] == WordCh &&
                 BackTrack(Row + 1, Col, CharIdx + 1))
          IsMatch = true;
        else if (Col < ColNum - 1 &&
                 Board[Row][Col + 1] == WordCh &&
                 BackTrack(Row, Col + 1, CharIdx + 1))
          IsMatch = true;
        BoardCh = ~BoardCh;
        
        return IsMatch;
      };
      
      for (int Row = 0; Row < RowNum; ++Row) {
        for (int Col = 0; Col < ColNum; ++Col) {
          if (Board[Row][Col] == Word[0] && BackTrack(Row, Col, 1))
            return true;
        }
      }
      
      return false;
    }
};
__________________________________________________________________________________________________
10004 kb
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    bool exist(vector<vector<char>>& board, string word) { 
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0] && helper(i, j, 0, board, word)) return 1; 
                    // if(helper(i, j, 0, board, word)) return 1;
        return 0;
    } 
    
    bool helper(int i, int j, int w, vector<vector<char>> &board, string &word)
    {
        if(++w == word.size()) return 1;
        // char c = board[i][j];
        // board[i][j] = 0;
        board[i][j] ^= -1;
        
        for(auto &t : dir)
        {
            int a = i + t[0], b = j + t[1];
            if(a >= 0 && b >= 0 && a < board.size() && b < board[0].size() && board[a][b] == word[w])
                if(helper(a, b, w, board, word)) return 1;;
        }
        // board[i][j] = c;
        board[i][j] ^= -1;
        return 0;
    } 
};

static int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return NULL;
}(); 
__________________________________________________________________________________________________
