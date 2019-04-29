 __________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string removeOuterParentheses(string S) {        
        int num_left = 0;
        int num_right = 0;
        int break_point = 0;
        string ret = "";
        for (int idx = 0; idx < S.length(); ++idx) {
            if (S[idx] == '(') {
                num_left++;
            }
            else {
                num_right++;
            }
            if (num_left == num_right) {
                ret.append(S.substr(break_point+1, idx-break_point-1));
                num_left = num_right = 0;
                break_point = idx+1;
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    string removeOuterParentheses(string S) {
        int n = S.length();
        int i = 0,j = 0;
        int a = 0;
        string ans = "";
        while(j < n){
            if(S[j] == '('){
                a -= 1;
            }
            else if(S[j] == ')'){
                a += 1;
            }
            if(a == 0 && j > 0){
                int k = i+1;
                while(k<j){
                    ans += S[k];
                    k++;
                }
                i = j + 1;
            }
            j++;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
     string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++ > 0) res += c;
            if (c == ')' && opened-- > 1) res += c;
        }
        return res;
    }
};