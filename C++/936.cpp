__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
    vector<int> ans;
    vector<int> seen(target.length());
    int total = 0;
    while (total < target.length()) {      
      bool found = false;
      for (int i = 0; i <= target.length() - stamp.length(); ++i) {
        if (seen[i]) continue;
        int l = unStamp(stamp, target, i);
        if (l == 0) continue;
        seen[i] = 1;
        total += l;
        ans.push_back(i);
        found = true;
      }
      if (!found) return {};
    }
    reverse(begin(ans), end(ans));
    return ans;
  }

  int unStamp(const string& stamp, string& target, int s) {    
    int l = stamp.size();
    for (int i = 0; i < stamp.length(); ++i) {
      if (target[s + i] == '?')
        --l;
      else if (target[s + i] != stamp[i])
        return 0;
    }
    
    if (l != 0)
      std::fill(begin(target) + s, begin(target) + s + stamp.length(), '?');
    return l;
  }
};
__________________________________________________________________________________________________
sample 9132 kb submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

bool match(string& stamp, string& target, int stamp_len, int match_len, int index)
{
    int compare_len = 0;
    while(compare_len < stamp_len && target[index + compare_len] == '*')
        compare_len++;
    if(compare_len + match_len > stamp_len)
        return false;
    for(int i = 0; i < match_len; i++)
        if(target[index + compare_len + i] != stamp[compare_len + i])
            return false;
    compare_len += match_len;
    while(compare_len < stamp_len)
    {
        if(target[index + compare_len] != '*')
            return false;
        compare_len++;
    }
    for(int i = 0; i < stamp_len; i++)
        target[index + i] = '*';
    return true;
}

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) 
    {
        int target_len = target.length(), stamp_len = stamp.length(), match_num = 0;
        vector <int> ans;
        bool match_found = true;
        while(match_found)
        {
            match_found = false;
            for(int match_len = stamp_len; match_len >= 1; match_len--)
            {
                for(int i = 0; i <= (target_len - stamp_len); i++)
                {
                    if(match(stamp, target, stamp_len, match_len, i))
                    {
                        match_found = true;
                        match_num += match_len;
                        ans.push_back(i);
                        if(match_num == target_len)
                        {
                            reverse(ans.begin(), ans.end());
                            return ans;
                        }
                    }
                }
            }
        }
        return vector <int>();
    }
};
__________________________________________________________________________________________________
