__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    
    string alphabetBoardPath(string target) {
        string t = "a" + target;
        string answer;
        for (int i = 0; i < t.size() - 1; ++i) {
            answer += solvetwo(t[i], t[i + 1]);
        }
        return answer;
    }

private:
    unordered_map<char, vector<int>> char_coords = {{'a',{0,0}}, {'b',{0,1}}, {'c',{0,2}}, {'d',{0,3}}, {'e',{0,4}}, {'f',{1,0}}, {'g',{1,1}}, {'h',{1,2}}, {'i',{1,3}}, {'j',{1,4}}, {'k',{2,0}}, {'l',{2,1}}, {'m',{2,2}}, {'n',{2,3}}, {'o',{2,4}}, {'p',{3,0}}, {'q',{3,1}}, {'r',{3,2}}, {'s',{3,3}}, {'t',{3,4}}, {'u',{4,0}}, {'v',{4,1}}, {'w',{4,2}}, {'x',{4,3}}, {'y',{4,4}}, {'z',{5,0}}};
    
    unordered_map<string, string> answer_map;
    
    string solvetwo(char from, char to) {
        if (from == to) {
            return "!";
        }        
        vector<int>& x_coords = char_coords[from];
        vector<int>& y_coords = char_coords[to];
        vector<char> answer;
        if (from != 'z') {
            int d = y_coords[1] - x_coords[1];
            if (d > 0) {
                for (int i = 0; i < d; ++i) {
                    answer.push_back('R');
                }
            } else if (d < 0) {
                d = -1*d;
                for (int i = 0; i < d; ++i) {
                    answer.push_back('L');
                }
            }
            d = y_coords[0] - x_coords[0];
            if (d > 0) {
                for (int i = 0; i < d; ++i) {
                    answer.push_back('D');
                }
            } else if (d < 0) {
                d = -1*d;
                for (int i = 0; i < d; ++i) {
                    answer.push_back('U');
                }
            } 
            answer.push_back('!');
        } else {
            int d = y_coords[0] - x_coords[0];
            if (d > 0) {
                for (int i = 0; i < d; ++i) {
                    answer.push_back('D');
                }
            } else if (d < 0) {
                d = -1*d;
                for (int i = 0; i < d; ++i) {
                    answer.push_back('U');
                }
            }
            d = y_coords[1] - x_coords[1];
            if (d > 0) {
                for (int i = 0; i < d; ++i) {
                    answer.push_back('R');
                }
            } else if (d < 0) {
                d = -1*d;
                for (int i = 0; i < d; ++i) {
                    answer.push_back('L');
                }
            }             
            answer.push_back('!');
        }
        
        return string(answer.begin(), answer.end());
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    string alphabetBoardPath(string target, int x = 0, int y = 0) {
  string res;
  for (auto ch : target) {
    int x1 = (ch - 'a') % 5, y1 = (ch - 'a') / 5;
    res += string(max(0, y - y1), 'U') + string(max(0, x1 - x), 'R') +
      string(max(0, x - x1), 'L') + string(max(0, y1 - y), 'D') + "!";
    x = x1, y = y1;
  }
  return res;
}
};
__________________________________________________________________________________________________
