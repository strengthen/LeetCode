__________________________________________________________________________________________________
sample 4 ms submission
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.length() == 0) return "";
        if(s.length() == 1) return s;

        vector<int> count(26, 0);
        for(char c: s){
            count[c-'a']++;
        }

        vector<bool> added(26, false);
        stack<char> x;

        for(char c: s){
            int i = c-'a';
            count[i] --;
            if(added[i]) continue;
            while(!x.empty() && x.top()>i && count[x.top()]>0){
                added[x.top()] = false;
                x.pop();
            }
            x.push(i);
            added[i] = true;
        }

        string res = "";
        while(!x.empty()){
            char c= 'a' + x.top();
            res = c + res;
            x.pop();
        }

        return res;
    }
};
__________________________________________________________________________________________________
sample 8388 kb submission
class Solution {
public:
    int seen[30];
    int in[30];
    int check(int i, string& s) {
        int tseen[30];
        memcpy(tseen, seen, sizeof seen);
        for(int j = i; j<s.length(); j++) {
            if(in[s[j]-'a']) continue;
            if(s[j] < s[i]) {
                memcpy(seen, tseen, sizeof tseen);
                return j;
            }
            tseen[s[j]-'a']--;
            if(tseen[s[j]-'a'] == 0) return 0;
        }
        return 0;
    }
    string removeDuplicateLetters(string s) {
        memset(in, 0, sizeof in);
        memset(seen, 0, sizeof seen);
        for(int i=0; i<s.length(); i++) {
            seen[s[i]-'a'] ++;
        }
        string ans;
        for(int i=0; i<s.length(); ) {
            //cout << i << " " << ans << endl;
            if(in[s[i]-'a']) {
                i++;
                continue;
            }
            if(seen[s[i]-'a'] == 1) ans += s[i], in[s[i]-'a'] = 1, i++;
            else {
                int t = check(i, s);
                if(t) {
                    i = t;
                } else {
                    ans += s[i], in[s[i]-'a'] = 1, i++;
                }
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
