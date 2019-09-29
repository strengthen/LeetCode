__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        pair<char, int> prev = make_pair('|', 0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == prev.first) {
                if (++prev.second >= k) {
                    // invalid, give up
                    prev = st.top();
                    st.pop();
                }
            }
            else {
                st.push(prev);
                prev = make_pair(s[i], 1);
            }
        }
        st.push(prev);
        string res = "";
        while (!st.empty()) {
            pair<char, int> t = st.top();
            st.pop();
            for (int i = 0; i < t.second; i++) {
                res += t.first;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for (auto c: s) {
            if (stk.empty() || stk.top().first!=c) {
                stk.push(make_pair(c, 1));
            } else {
                ++stk.top().second;
            }

            if (stk.top().second >= k) { stk.pop(); }
        }

        string ans;
        while (!stk.empty()) {
            auto tmp = stk.top(); stk.pop();
            for (int i=0; i<tmp.second; ++i) { ans += tmp.first; }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack < pair < char, int > > st;
        for(int i = 0;i < n;++i) {
            if(st.empty() or st.top().first != s[i]) {
                st.push({s[i], 1});
            } else {
                pair < char, int > temp = st.top();     st.pop();
                ++temp.second;
                st.push(temp);
            }
            if(st.top().second == k) {
                st.pop();
            }
        }
        string ans;
        while(!st.empty()) {
            pair < char, int > temp = st.top();     st.pop();
            for(int i = 0;i < temp.second;++i) {
                ans += temp.first;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
