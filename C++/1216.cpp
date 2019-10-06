__________________________________________________________________________________________________
sample 44 ms submission
class Solution {
public:
    bool isValidPalindrome(string s, int K) {
        vector<int> dp(s.size(), 1);
        for (int i = 0; i < s.size(); i++) {
            for (int j = i - 1, last = 0; j >= 0; j--) {
                int t = dp[j];
                if (s[i] == s[j])
                    dp[j] = last + 2;
                else
                    dp[j] = max(dp[j], dp[j + 1]);
                last = t;
            }
        }
        return s.size() - dp[0] <= K;
    }
};
__________________________________________________________________________________________________
sample 48 ms submission

typedef long long Long;
typedef vector<int> vInt;
typedef vector<vInt> vvInt;
typedef vector<vvInt> vvvInt;
typedef vector<string> vStr;
typedef pair<int, int> Pair;
typedef vector<Pair> vPair;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define PB push_back

class Solution {
    int n;
    string S;
    vvInt memo;
   public:
    bool isValidPalindrome(string str, int K) {
        S = str;
        n = SZ(S);
        memo = vvInt(n + 1, vInt(n + 1, -1));
        return dp(0, n - 1) >= n - K;
    }

    int dp(int lo, int hi) {
        if (lo > hi) return 0;
        if (memo[lo][hi] != -1) return memo[lo][hi];
        int &ans = memo[lo][hi] = max(dp(lo + 1, hi), dp(lo, hi - 1));
        if (S[lo] == S[hi]) {
            ans = max(ans, 1 + (hi != lo) + dp(lo + 1, hi - 1));
        }
        return ans;
    }

};
__________________________________________________________________________________________________
24ms
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
	int N = (int)s.size();
	vector<vector<int>> dp(N,vector<int>(N, 0));
	for(int r=1;r<N;r++) {
		dp[r][r]=1;
		for(int l=r-1;l>=0;l--) {
			dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
			if (s[l]==s[r]) dp[l][r]=max(dp[l][r],2+dp[l+1][r-1]);
		}
	}
	return dp[0][N-1]>=N-k;
}
};
