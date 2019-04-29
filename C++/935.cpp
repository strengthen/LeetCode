__________________________________________________________________________________________________
sample 4 ms submission
uint64_t dp[10][5001];
int max_n = 1;
constexpr uint64_t mod = 1000000007;
vector<vector<int>> walk = {
    {4,6}, // 0
    {6,8}, // 1
    {7,9}, // 2
    {4,8}, // 3
    {0,3,9}, // 4
    {},
    {0,1,7}, // 6
    {2,6}, // 7
    {1,3}, // 8
    {2,4}, // 9 
};

class Solution {
public:
    int knightDialer(int N) {
        if (N >= max_n) {
            // 每个位置，一开始走0步的时候，都可以走到
            for (int k = 0; k < 10; k++) {
                dp[k][1] = 1;
            }
            for (int i = max_n; i < N; i++) {
                for  (int k = 0; k < 10; k++) {
                    for (auto &pos: walk[k]) {
                        dp[pos][i+1] += dp[k][i];
                        dp[pos][i+1] %= mod;
                    }
                }
            }
            max_n = N;
        }
        
        uint64_t sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += dp[i][N];
            sum %= mod;
        }
        
        return sum;
    }
};
__________________________________________________________________________________________________
sample 8804 kb submission
class Solution {
public:
    constexpr static int moduloNumber = 1000000007;
    
    int knightDialer(int N) {
        vector<int> dp1 (10, 0);
        vector<int> dp2 (10, 1);
        dp2[5] = 1;
        
        auto thisStep = &dp1;
        auto lastStep = &dp2;
        for(int i = 1; i < N; ++i) {
            countAtStepNMinusi(thisStep, lastStep);
            // Swap d1 and d2
            auto temp = lastStep;
            lastStep = thisStep;
            thisStep = temp;
        }
        
        int output = 0;
        for(int i = 0; i < 10; ++i) {
            output = (output + (*lastStep)[i]) % moduloNumber;
        }
        return output;
    }
    
    void countAtStepNMinusi(vector<int>* thisStep, vector<int>* lastStep) {
        (*thisStep)[0] = ((*lastStep)[4] + (*lastStep)[6]);
        (*thisStep)[0] = (*thisStep)[0] <= moduloNumber 
                         ? (*thisStep)[0] 
                         : (*thisStep)[0] % moduloNumber;
        
        (*thisStep)[1] = ((*lastStep)[6] + (*lastStep)[8]);
        (*thisStep)[1] = (*thisStep)[1] <= moduloNumber 
                         ? (*thisStep)[1] 
                         : (*thisStep)[1] % moduloNumber;
        
        (*thisStep)[2] = ((*lastStep)[7] + (*lastStep)[9]);
        (*thisStep)[2] = (*thisStep)[2] <= moduloNumber 
                         ? (*thisStep)[2] 
                         : (*thisStep)[2] % moduloNumber;
        
        (*thisStep)[3] = ((*lastStep)[4] + (*lastStep)[8]);
        (*thisStep)[3] = (*thisStep)[3] <= moduloNumber 
                         ? (*thisStep)[3] 
                         : (*thisStep)[3] % moduloNumber;
        
        (*thisStep)[4] = (((*lastStep)[0] + (*lastStep)[3]) % moduloNumber
                         + (*lastStep)[9]) % moduloNumber;
        
        (*thisStep)[5] = 0;
        
        (*thisStep)[6] = (((*lastStep)[0] + (*lastStep)[1]) % moduloNumber
                         + (*lastStep)[7]) % moduloNumber;
        
        (*thisStep)[7] = ((*lastStep)[2] + (*lastStep)[6]);
        (*thisStep)[7] = (*thisStep)[7] <= moduloNumber 
                         ? (*thisStep)[7] 
                         : (*thisStep)[7] % moduloNumber;
        
        (*thisStep)[8] = ((*lastStep)[1] + (*lastStep)[3]);
        (*thisStep)[8] = (*thisStep)[8] <= moduloNumber 
                         ? (*thisStep)[8] 
                         : (*thisStep)[8] % moduloNumber;
        
        (*thisStep)[9] = ((*lastStep)[2] + (*lastStep)[4]);
        (*thisStep)[9] = (*thisStep)[9] <= moduloNumber 
                         ? (*thisStep)[9] 
                         : (*thisStep)[9] % moduloNumber;
    }
};
__________________________________________________________________________________________________
