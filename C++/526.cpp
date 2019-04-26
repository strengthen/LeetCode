__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    Solution() {

    }

    int countArrangement(int N) {
        SuitableNumbers.assign(16, vector<int>());
        for (int i = 1; i <= 15; ++i) {
            for (int j = 1; j <= 15; ++j) {
                if (i % j == 0 || j % i == 0) {
                    SuitableNumbers[i].push_back(j - 1);
                }
            }
        }
        memset(WasCalced, false, sizeof(WasCalced));
        return getCount((1 << N) - 1, N, N);
    }
private:
    unsigned long long getCount(int mask, int usedCount, int n) {
        if (usedCount == 0) {
            return 1;
        }
        if (WasCalced[mask]) {
            return CountByMask[mask];
        }
        WasCalced[mask] = true;
        CountByMask[mask] = 0;
        for (int i = 0; i < SuitableNumbers[usedCount].size() && SuitableNumbers[usedCount][i] < n; ++i) {
            if (mask & (1 << (SuitableNumbers[usedCount][i]))) {
                CountByMask[mask] += getCount(mask ^ (1 << (SuitableNumbers[usedCount][i])), usedCount - 1, n);
            }
        }
        return CountByMask[mask];
    }
    
private:
    vector<vector<int>> SuitableNumbers;
    unsigned long long CountByMask[1 << 15];
    bool WasCalced[1 << 15];  
};
__________________________________________________________________________________________________
sample 8136 kb submission
class Solution {
public:
    int ans = 0;
    int n;
    bool used[20];
    void dfs(int x, int y) {
        if(y == n) {
            ans++;
            return;
        }
        used[x] = true;
        for(int i = 1 ; i <= n ; i++) {
            if(!used[i]) {
                if(i % (y+1) == 0 || (y+1) % i == 0) {
                    dfs(i, y+1);
                }
            }
        }
        used[x] = false;
    }
    
    int countArrangement(int N) {
        memset(used, 0, sizeof(used));
        n = N;
        for(int i = 1 ; i <= N ; i++) {
            dfs(i, 1);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
