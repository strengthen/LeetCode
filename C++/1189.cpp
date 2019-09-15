__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);
        for(auto c: text) {
            ++count[c-'a'];
        }
        int ans = text.size();
        ans = std::min(ans, count['b'-'a']);
        ans = std::min(ans, count['a'-'a']);
        ans = std::min(ans, count['l'-'a']/2);
        ans = std::min(ans, count['o'-'a']/2);
        //ans = std::min(ans, count['n'-'a']);
        return ans;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string s = "balon";
    int maxNumberOfBalloons(string A) {
        vector < int > cnt(30, 0);
        int n = A.size();
        for(int i = 0;i < n;++i) {
            ++cnt[A[i] - 'a'];
        }
        
        int ans = n;
        for(int i = 0;i < s.size();++i) {
            if(s[i] == 'l' or s[i] == 'o') {
                ans = min(ans, cnt[s[i] - 'a']/2);
            } else {
                
               ans = min(ans, cnt[s[i] - 'a']);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
