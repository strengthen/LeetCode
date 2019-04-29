__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    #define LL long long
    #define MOD 1000000007
public:
    int numPermsDISequence(string S) {
        int N = S.length();
        // A[i][j]: the number of ways that
        // perm of {0..i} ends with j
        // and fits S[0..i-1]
        vector<vector<LL>> A(2, vector<LL>(N+1, 0));
        A[0][0] = 1;
        for(int i = 1 ; i <= N ; ++i){
            int I = i & 1, preI = ~i&1;
            if(S[i-1] == 'I'){
                // P[i-1] < P[i]
                int Low = 0;
                for(int k = 0 ; k <= i ; ++k){
                    // choosing P[i] = k
                    // Low = sum of A[i-1][0, k)
                    A[I][k] = Low;
                    Low = (Low + A[preI][k]) % MOD;
                }
            }
            else{
                // P[i-1] > P[i]
                int High = 0;
                A[I][i] = 0;
                for(int k = i - 1 ; k >= 0 ; --k){
                    // choosing P[i] = k
                    // High = sum of A[i-1][k, i)
                    High = (High + A[preI][k]) % MOD;
                    A[I][k] = High;
                }
            }
        }
        int ANS = 0;
        for(int k = 0 ; k <= N ; ++k)
            ANS = (ANS + A[N&1][k]) % MOD;
        return ANS;
    }
};
__________________________________________________________________________________________________
sample 8888 kb submission
class Solution {
public:
    int numPermsDISequence(string S) {
        int const MOD_NUM = 1e9 + 7; // 1_000_000_000 + 7
        // copy method from standard solution
        int len = S.size();
        if (0 == len) {
            return 0;
        }
        
        vector<long> preDp(len + 1, 1);
        vector<long> curDp(len + 1, 0);
        for (int index = 1; index <= len; index++) {
            if (S[index - 1] == 'D') {
                for (int r2l = index; r2l > -1; r2l--) {
                    for (int upper = r2l; upper < index; upper++) {
                        curDp[r2l] += preDp[upper];
                        curDp[r2l] %= MOD_NUM;
                        // std::cout << "index: " << r2l << " val: " << curDp[r2l] << std::endl;
                    }
                }
            } else if (S[index - 1] == 'I') {
                for (int r2l = index; r2l > -1; r2l--) {
                    for (int lower = 0; lower < r2l; lower++) {
                        curDp[r2l] += preDp[lower];
                        curDp[r2l] %= MOD_NUM;
                        // std::cout << "index: " << r2l << " val: " << curDp[r2l] << std::endl;
                    }
                }
            }
            preDp.swap(curDp);
            std::fill(curDp.begin(), curDp.end(), 0);
        }
        long ans = 0;
        for (int ele : preDp) {
            ans += ele;
            ans %= MOD_NUM;
        }

        return ans;
    }
};
__________________________________________________________________________________________________
