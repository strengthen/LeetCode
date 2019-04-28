__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int scoreOfParentheses(string S) {
        int temp=0;
        stack<int> score;
        score.push(0);
        int n=S.size();
        for(int i=0; i<n; ++i){
            if(S[i]=='(') {
                score.push(0);
            }
            else{
                temp=score.top();
                score.pop();
                if(S[i-1]=='('){
                    temp++;
                }
                else{
                    temp *= 2;
                }
                score.top() += temp;
            }
        }
        
        return score.top();
    }
};
__________________________________________________________________________________________________
sample 8500 kb submission
class Solution {
public:
    int solve(string &s) {
        int ans = 0;
        int open = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') {
                open++;
            } else {
                open--;
                if(s[i-1] == '(') {
                    ans += 1<<open;
                }
            }
        }
        return ans;
    }
    int scoreOfParentheses(string S) {
        return solve(S);
    }
};
__________________________________________________________________________________________________
