__________________________________________________________________________________________________
sample 0 ms submission
int n;
int sum[105][105];
int dp[105][105];

int recurse(int M, int i) {
    if (i >= n) return 0;
    if (dp[M][i] != -1) return dp[M][i];
    for (int x = 1; x <= 2 * M; x++) {
        if (i + x - 1 >= n) break;
        dp[M][i] = max(dp[M][i], sum[i][n - 1] - recurse(max(M, x), i + x));
    }
    return dp[M][i];
}

class Solution {
public:
    int stoneGameII(vector<int>& a) {
        n = a.size();
        for (int i = 0; i < n; i++) {
            sum[i][i] = a[i];
            for (int j = i + 1; j < n; j++) sum[i][j] = sum[i][j - 1] + a[j];
        }
        memset(dp, -1, sizeof(dp));
        return recurse(1, 0);
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
	vector<vector<int>> dp;
	int helper(vector<int>& p, int k, int m) {
		if (k==dp.size()) return 0;
		if (dp[k][m] != INT_MIN) return dp[k][m];
		int& v=dp[k][m];
		for (int i=k, s=0; i+1-k <= 2*m && i < p.size(); ++i) {
			s += p[i];	
			v = max(v, s - helper(p, i+1, max(m, i+1-k)));
		}
		return v;
	}
    int stoneGameII(vector<int>& piles) {
		int n=piles.size(), s=0;
		for (auto i : piles) s+=i;
		dp.resize(n, vector<int>(n, INT_MIN));
		int v=helper(piles, 0, 1);
		return (s-v)/2 + v;
    }
};
__________________________________________________________________________________________________
