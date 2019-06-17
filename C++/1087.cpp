__________________________________________________________________________________________________
class Solution {
public:
    vector<string> ret;
    string cur;
    void dfs(int k, vector<string> &v)
    {
        if (k == v.size())
        {
            ret.push_back(cur);
            return;
        }
        for (auto c : v[k])
        {
            cur += c;
            dfs(k+1, v);
            cur.pop_back();
        }
    }
    vector<string> permute(string s) {
        int n = s.size();
        vector<string> v;
        for (int i = 0; i < n; ++ i)
        {
            if (s[i] == '{')
            {
                string t;
                for (; i < n; ++ i)
                {
                    if (s[i] == '}') break;
                    if (isalpha(s[i])) t += s[i];
                }
                sort(t.begin(), t.end());
                v.push_back(t);
            }
            else
            {
                string t;
                t += s[i];
                v.push_back(t);
            }
        }
        ret.clear();
        cur = "";
        dfs(0, v);
        return ret;
    }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
