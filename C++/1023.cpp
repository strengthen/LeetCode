__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> ans(n);
        int sz = pattern.length();
        for(int i=0;i<n;i++){
            int m = queries[i].length();
            int j=0,k=0;
            int flag = 0;
            while(j<m && k<sz){
                if(pattern[k] == queries[i][j]){
                    k++;
                }
                else if(queries[i][j] >= 65 && queries[i][j] <= 90){
                        flag = 1;break;
                }
                j++;
            }
            while(j<m){
                if(queries[i][j] >= 65 && queries[i][j] <= 90){
                        flag = 1;break;
                }
                j++;
            }
            if(k<sz){flag = 1;}
            if(flag == 0){ans[i] = true;}
            else{ans[i] = false;}
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for(string& s : queries){
            res.push_back(match(s, pattern));
        }
        return res;
    }
    
    bool match(string& query, string& pattern){
        auto q = segment(query), p = segment(pattern);
        if(q.size() < p.size() || q.size() >= p.size() + 2) return false;
        int iq = 0, ip = 0;
        if(q.size() == p.size() + 1){
            // q = "aAaAa", p = "AaAa"
            if(q[0][0] >= 'A' && q[0][0] <= 'Z') return false;
            iq = 1;
        }
        for(; ip < p.size(); ip++, iq++){
            int idx = 0;
            if(q[iq][0] >= 'A' && q[iq][0] <= 'Z'){
                if(q[iq][0] != p[ip][0]) return false;
                idx = 1;
            }
            if(q[iq].length() < p[ip].length()) return false;
            for(int i = idx; i < p[ip].length(); i++){
                int next = q[iq].find_first_of(p[ip][i], idx);
                if(next == -1) return false;
                idx = next + 1;
            }
        }
        return true;
    }
    
    vector<string> segment(string& s){
        vector<string> res;
        int begin = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                res.push_back(s.substr(begin, i - begin));
                begin = i;
            }
        }
        res.push_back(s.substr(begin));
        return res;
    }
};
__________________________________________________________________________________________________
