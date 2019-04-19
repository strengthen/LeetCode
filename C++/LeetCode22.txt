__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left = n;
        int right = n;
        vector<string> res;
        string s;
        while (left--) {
            s += '(';
        }
        left++;
        while (right--) {
            s += ')';
        }
        right++;
        res.push_back(s);
        while (!s.empty()) {
            if (s.back() == ')') {
                s.pop_back();
                right++;
            } else if (left+1 < right) {
                left++; right--;
                s.back() = ')';
                while (left--) s.push_back('(');
                left++;
                while (right--) s.push_back(')');
                right++;
                res.push_back(s);
            } else {
                s.pop_back();
                left++;
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ret;
        string s;
        dfs(n,n,ret,s);
        return ret;
    }
    void dfs(int left,int right,vector<string>& ret, string& s){
        if(left<0||right<0||left>right)return;
        if(left==0&&right==0){
            ret.push_back(s);
            return;
        }
        
        s.push_back('(');
        dfs(left-1,right,ret,s);
        s.pop_back();
        s.push_back(')');
        dfs(left,right-1,ret,s);
        s.pop_back();
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    
    void core_function(string prefix, vector<string> &ans, int left, int right) {
        if(left == 0 && right == 0) return;
        if(left == 0) {
            while(right--)
                prefix += ')';
            ans.push_back(prefix);
        } else {
            core_function(prefix+'(', ans, left-1, right);
    
            if(right > left) {
                core_function(prefix+')', ans, left, right-1);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string prefix = "";
        vector<string> ans;
        core_function(prefix, ans, n, n);
        return ans;
    }
};
__________________________________________________________________________________________________
9176 kb
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; ans.clear();
        if(n == 0) return ans;
        string s = "";
        for(int i = 0; i < n; ++i) s += '(';
        for(int i = 0; i < n; ++i) s += ')';
        do {
            if(s[0] == ')') break;
            int sum = 0;
            for(int i = 0; i < 2 * n; ++i) {
                if(s[i] == '(') ++sum;
                else --sum;
                if(sum < 0) break;
            }
            if(sum == 0) ans.push_back(s);
        } while(next_permutation(s.begin(), s.end()));
        return ans;
    }
};
__________________________________________________________________________________________________
9212 kb
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int size = 2*n;
        int countLeft = n;
        int countRight = n;
        string tmp = "";        
        vector<string> res;
        res.push_back("(");
        int i=0;
        while(res[res.size()-1].size() != size)
        {            
            countLeft = n;
            countRight = n;
            for(int j = 0;j<res[i].size();j++)
            {
                if(res[i][j]=='(')
                    countLeft--;
                if(res[i][j]==')')
                    countRight--;
            }
            while(res[i].size()!=size)
            {
                if(countLeft!=countRight && countLeft>0)
                {
                    //Two options
                    res.push_back(res[i]+')');

                    res[i] += '(';
                    countLeft--;
                }
                else if(countLeft==countRight)
                {
                    res[i]+='(';
                    countLeft--;
                }
                else
                {
                    res[i]+=')';
                    countRight--;
                }
            }
            
            i++;
        }
        return res;
    }
};
__________________________________________________________________________________________________
