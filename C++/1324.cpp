__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    vector<string> printVertically(string s) {
        vector < string > A, ans;
        int ma = 0;
        int n = s.size();
        string x;
        for(int i = 0;i < n;++i) {
            if(s[i] == ' ') {
                A.push_back(x);
                 ma = max(ma, (int)x.size());
                x = "";
            } else {
                x += s[i];
            }
        }
        if(x.size()) {
            A.push_back(x);
            ma = max(ma, (int)x.size());
            x = "";
        }
        
        for(int i = 0;i < ma;++i) {
            for(int j = 0;j < A.size();++j) {
                if(i >= A[j].size()) {
                    x += ' ';
                } else {
                    x += A[j][i];
                }
            }
            while(x[(int)x.size() - 1] == ' ') {
                x.pop_back();
            }
            ans.push_back(x);
            x = "";
        }
        return ans;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int minc = 0;
    vector<string> splits(string s)
    {
        vector<string> v;
        string delim = " ";
        int pos = s.find(delim), start = 0;
        while(pos != -1)
        {
            string p = s.substr(start, pos - start);
            minc = max((int)p.size(), minc);
            v.push_back(p);
            start = pos + delim.size();
            pos = s.find(delim, start);
        }
        string p = s.substr(start, pos - start);
        minc = max((int)p.size(), minc);
        v.push_back(p);
        return v;
    }
    vector<string> printVertically(string s) {
        vector<string>v = splits(s);
        vector<string> ans;
        int i, j = 0;
        string p;
        while(j < minc)
        {
            for(i = 0; i < v.size(); i++)
            {
                if(j < v[i].size())
                    p.push_back(v[i][j]);
                else
                    p.push_back(' ');
            }
            for(int k = p.size() - 1; k >= 0; k--)
            {
                if(p[k]==' ')
                    p.pop_back();
                else
                    break;
            }
            ans.push_back(p);
            j++;
            p.clear();
        }
        return ans;
    }
};
__________________________________________________________________________________________________
