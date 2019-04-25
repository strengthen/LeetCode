__________________________________________________________________________________________________
sample 4 ms submission
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& A)
    {
        int N = A.size();
        
        int result = 0;
        if (N <= 2)
            return result;
        
        int dp = 0;
        for (int i = 2; i < N; ++i)
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                dp = 1 + dp;
                result += dp;
            }
            else
            {
                dp = 0;
            }
        
        return result;
    }
};
__________________________________________________________________________________________________
sample 8592 kb submission
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        // Base case
        if (A.size() < 3) return 0;
        
        // Variables
        int ans = 0;
        int diff = A[1] - A[0];
        int streak = 1;
        
        // Iterate through array
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == diff) ++streak;
            else {
                diff = A[i] - A[i - 1];
                ans += (streak) * (streak - 1) / 2;
                streak = 1;
            }
        }
        if (streak > 1) ans += ((streak) * (streak - 1)) / 2;
        return ans;
    }
};
__________________________________________________________________________________________________
