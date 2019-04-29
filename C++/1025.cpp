__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool divisorGame(int N) {
        vector<int> mem(N+1, 0);
        return divisorGame(mem, N);
    }
private:
    bool divisorGame(vector<int>& mem, int N){
        if(N == 1)
            return false;
        if(N == 2)
            return true;
        if(mem[N] != 0)
            return mem[N] == 1 ? true : false;
        for(int i = 1; i < N; ++i){
            if(N%i == 0){
                if(!divisorGame(mem, N-i)){
                    mem[N] = 1;
                    return true;
                }
            }
        }
        mem[N] = -1;
        return false;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N + 1);
        dp[0] = false;
        dp[1] = false;
        for(int i = 2; i < N + 1; i++){
            for(int j = 1; j < i; j++){
                if(i % j == 0){
                    if(dp[i - j] == false){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[N];
    }
};
__________________________________________________________________________________________________
