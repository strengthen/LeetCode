__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        helper(s,ans,0,0,"()");
        return ans;
    }
    
    void helper(string s, vector<string>& ans, int last_i, int last_j, string para){
        int count = 0;
        for(int i=last_i;i<s.size();i++){
            if(s[i]==para[0]) count++;
            if(s[i]==para[1]) count--;
            if(count<0){
                for(int j=last_j;j<=i;j++)
                    if(s[j]==para[1] && (j==last_j || s[j-1]!=para[1]))
                        helper(s.substr(0,j)+s.substr(j+1),ans,i,j,para);
                return;
            }
        }
        if(para[0]=='('){
            std::reverse(s.begin(),s.end());
            helper(s,ans,0,0,")(");
        }else{
            std::reverse(s.begin(),s.end());
            ans.push_back(s);
            return;
        }
    }
};
__________________________________________________________________________________________________
sample 8884 kb submission
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int i = 0;
        int j = s.size()-1;
        while(i < s.size() && s[i] == ')') i++;
        while(j > i && s[j] == '(') j--;
        s = s.substr(i, j - i + 1);
        if(s.empty()) return {""};
        int left_remove = 0;
        int right_remove = 0;
        for(int k = 0; k < s.size(); ++k){
            if(s[k] == '('){
                left_remove++;
            }else if(s[k] == ')'){
                if(left_remove == 0){
                    right_remove++;
                }else{
                    left_remove--;
                }
            }
        }
        dfs(left_remove, right_remove, s, res, 0);
        return res;
    }
    
    void dfs(int l, int r, string& s, vector<string>& res, int start){
        if(l == 0 && r == 0){
            if(validate(s)){
                res.push_back(s);
            }
            return;
        }
        for(int i = start; i < s.size();){
            if(s[i] == '('){
                if(l){
                    string t = s;
                    t.erase(i, 1);
                    dfs(l-1, r, t, res, i);
                    i++;
                    while(i < s.size() && s[i-1] == s[i]) i++;
                }else{
                    i++;
                }
            }else if(s[i] == ')'){
                if(r){
                    string t = s;
                    t.erase(i, 1);
                    dfs(l, r-1, t, res, i);
                    i++;
                    while(i < s.size() && s[i-1] == s[i]) i++;
                }else{
                    i++;
                }
            }else{
                i++;
            }
        }
        return;
    }
    
    bool validate(string& s){
        int count = 0;
        for(auto ch : s){
            if(ch == '('){
                count++;
            }else if(ch == ')'){
                if(count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
};
__________________________________________________________________________________________________
