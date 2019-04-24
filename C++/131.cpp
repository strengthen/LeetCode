__________________________________________________________________________________________________
12ms
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        dfs(s, 0, path, ans);
        return ans;
    }
    
    void dfs(const string& s, int pos, vector<string>& path, vector<vector<string>>& ans) {
        if ( pos == s.size() ) {
            ans.push_back(path);
            return;
        } 
        
        for ( int i = pos; i < s.size(); i++ ) {
            if ( isP(s, pos, i) ) {
                string tmp = s.substr(pos, i-pos+1);
                path.push_back(tmp);
                dfs(s, i+1, path, ans);
                path.pop_back();
            }
        }
    }
    
    bool isP(const string& s, int b, int e) {
        while ( b < e ) {
            if ( s[b] != s[e] )
                return false;
            b++;
            e--;
        }
        
        return true;
    }
};
__________________________________________________________________________________________________
12376 kb
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur_res;
        vector<vector<string>> res;
        dfs(s, 0, cur_res, res);
        return res;
    }
private:
    bool check_palindrome(const string & word, int s, int e){
        while(s < e){
            if(word[s] != word[e])
                return false;
            ++s;
            --e;
        }
        return true;
    }
    
    void dfs(const string& s, int cur_index, vector<string> & cur_res, vector<vector<string>> & res){
        if(cur_index == s.size()){
            res.emplace_back(cur_res);
            return;
        }
        
        for(int l = 0; cur_index + l < s.size(); ++l){
            if(check_palindrome(s, cur_index, cur_index + l)){
                cur_res.push_back(s.substr(cur_index, l + 1));
                dfs(s, cur_index + l + 1, cur_res, res);
                cur_res.pop_back();
            }
        }
    }
};
__________________________________________________________________________________________________
