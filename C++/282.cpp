__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string exp(num.length() * 2, '\0');
        dfs(num, target, 0, exp, 0, 0 , 0, res);
        return res;
    }
    
private:
    void dfs(const string& num, const int target, 
            int pos, string& exp, int len, long prev, 
            long curr, vector<string>& res){
        
        if(pos == num.length()){
            if(curr == target) res.emplace_back(
                exp.substr(0, len));
            return;
        }
        
        long n = 0;
        int s = pos;
        int l = len;
        if(s != 0) ++len;
        while(pos < num.size()){
            n = n * 10 + (num[pos] - '0');
            if(num[s] == '0' && pos - s > 0) break;
            if(n > INT_MAX) break;
            exp[len++] = num[pos++];
            if(s == 0){
                dfs(num, target, pos, exp, len, n, n, res);
                continue;
            }
            exp[l] = '+'; dfs(num, target, pos, exp, len, n, curr + n, res);
            exp[l] = '-'; dfs(num, target, pos, exp, len, -n, curr - n, res);
            exp[l] = '*'; dfs(num, target, pos, exp, len, prev * n, curr - prev + prev * n, res);
        }
   
    }
};
__________________________________________________________________________________________________
sample 17056 kb submission
class Solution {
public:
  vector<string> addOperators(string num, int target) {
    std::vector<std::string> res;
    std::string ansBuf(num.size()*2, '\0');
    helper(num, ansBuf, target, 0, 0, res, 0, 0);
    return res;
  }

  /*
   * Need mul to do multiplication
   * eval is the previous evaluation, not considering multiplication in the back.
   * therefore we need mul to augument it.
   */
  void helper(const std::string &num,
              std::string &ansBuf,
              int target,
              int start_pos1, //int end_pos,
              int start_pos2,
              std::vector<std::string> &res,
              long eval, long mul)
  {
    if (num.size() == start_pos1) {
      if (target == eval) {
        res.push_back(ansBuf.substr(0, start_pos2));
      }
    }
    else {
      long number = 0;
      for (int i = 0; i < num.size() - start_pos1; ++ i) {
        if (num[start_pos1] == '0' && i > 0) return;
        number = 10*number + (num[start_pos1+i] - '0');

        if (start_pos1 == 0) {
          ansBuf[start_pos2+i] = num[start_pos1+i];
          helper(num, ansBuf, target, start_pos1+1+i, start_pos2+1+i, res, number, number);
        }
        else {
          ansBuf[start_pos2+1+i] = num[start_pos1+i];
          ansBuf[start_pos2] = '+';
          helper(num, ansBuf, target, start_pos1+1+i, start_pos2+2+i, res, eval + number, number);
          ansBuf[start_pos2] = '-';
          helper(num, ansBuf, target, start_pos1+1+i, start_pos2+2+i, res, eval - number, -number);
          // need to take care of passing mul
          ansBuf[start_pos2] = '*';
          helper(num, ansBuf, target, start_pos1+1+i, start_pos2+2+i, res, (eval - mul) + mul * number, mul * number);
        }
      }
    }
  }
};
__________________________________________________________________________________________________
