__________________________________________________________________________________________________
4ms
class Solution {
public:
    unordered_map<char, string> hashMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()<1)
        {
            return {};
        }
        
        vector<string> resp;
        helper(resp, digits, 0, "");
        return resp;
        
    }
    
    void helper(vector<string>& resp, string& digits, int pos, string currentStr)
    {
        if(pos == digits.size())
        {
            resp.push_back(currentStr);
        }
        
        auto letters = hashMap.find(digits[pos]);
        if(letters != hashMap.end())
        {
            for(int i=0 ; i<letters->second.size() ; i++)
            {
                helper(resp, digits, pos+1, currentStr + letters->second[i]);
            }
        }
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits, dict, 0, "", res);
        return res;
    }
    void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res) {
        if (level == digits.size()) {res.push_back(out); return;}
        string str = dict[digits[level] - '0'];
        for (int i = 0; i < str.size(); ++i) {
            letterCombinationsDFS(digits, dict, level + 1, out + string(1, str[i]), res);
        }
    }
};
__________________________________________________________________________________________________
8292 kb
class Solution {
public:
    vector<string> letterCombinations(string digits) {
      if (digits.empty()) return {};
      vector<string> ans;
      string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      letterCombinationsDFS(digits, dict, 0, "", ans);
      return ans;
    }
  void letterCombinationsDFS(const string& digits, string dict[], int index, string out, vector<string>& ans) {
    if (index == digits.length()) {
      ans.emplace_back(out);
      return;
    }
    string str = dict[digits[index] - '0'];
    for (char c : str) {
      letterCombinationsDFS(digits, dict, index + 1, out + c, ans);
    }
  }
};
__________________________________________________________________________________________________
8408 kb
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;
        
        string d[8] = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        
        res.push_back("");
        
        for(char& c : digits) {
            int idx = (int)(c-'0')-2;
            size_t l = res.size();
            for(int i=0; i<l; i++) {
                string s = res.front();
                for(char& cc : d[idx]) {
                    string cp = s;
                    cp.append(1, cc);
                    res.push_back(cp);
                }
                res.erase(res.begin());
            }    
        }
        return res;
    }
};
__________________________________________________________________________________________________
8416 kb 
class Solution {
public:
    vector<string> m_results;
    string m_curResult;
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        dfs(digits, 0);
        return move(m_results);
    }
    
    void dfs(const string& digits, int start) {
        if (start == digits.size()) {
            m_results.push_back(m_curResult);
            return;
        }
        
        constexpr const char* dict = "adgjmptw";
        char letter = dict[digits[start] - '2'];
        int count = letter == 'p' || letter == 'w' ? 4 : 3;
        for (int i = 0; i < count; ++i, ++letter) {
            m_curResult.push_back(letter);
            dfs(digits, start + 1);
            m_curResult.pop_back();
        }
    }
};
__________________________________________________________________________________________________
