__________________________________________________________________________________________________
sample 32 ms submission
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>> pos;
        for(int i = 0 ; i < A.size(); ++i){
            pos[A[i]].push_back(i);
        }
        int max_array = 0;
        for(int i = 0; i < B.size(); ++i){
            if ( pos.find(B[i]) != pos.end() ){
                int max_right_B = i; 
                for(int pa : pos[B[i]]){
                    int left_B = i;
                    int right_B = i;
                    int left_A =  pa;
                    int right_A = pa;
                    while(left_B > 0 && left_A > 0 && A[left_A-1] == B[left_B-1]){
                        --left_A;
                        --left_B;
                    }
                    while(right_B < B.size()-1 && right_A < A.size()-1 && A[right_A+1] == B[right_B+1]){
                        ++right_A;
                        ++right_B;
                    }
                    max_right_B = max(max_right_B, right_B);
                    max_array = max(max_array, right_B-left_B + 1 );
                }
                i = max_right_B;
            }
        }
        return max_array;
        
    }
};
__________________________________________________________________________________________________
sample 9144 kb submission
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0, m = A.size(), n = B.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = n; j > 0; j--)  {
                if (A[i - 1] == B[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                    res = max(res, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
