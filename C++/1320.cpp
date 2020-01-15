__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int minimumDistance(string word) {
        vector<int> dp(26);
        int res = 0, save = 0, n = word.size();
        for (int i = 0; i < n - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            for (int a = 0; a < 26; ++a)
                dp[b] = max(dp[b], dp[a] + d(b, c) - d(a, c));
            save = max(save, dp[b]);
            res += d(b, c);
        }
        return res - save;
    }

    int d(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int minimumDistance(string w) {
        int n = w.size();
        vector<vector<int>> dp(n, vector<int>(27, 0));

        for(int i=1;i<n;++i)
            for(int c=0;c<27;++c)
                dp[i][c] = min(cost(w[i]-'A', w[i-1]-'A') + dp[i-1][c], cost(c, w[i-1]-'A') + dp[i-1][w[i]-'A']);

        return dp[n-1][26];
    }

    int cost(int i, int j) {
        if(i == 26) return 0;
        return abs(i/6 - j/6) + abs(i%6 - j%6);
    }

    int threeFinger(string w) {
        int n = w.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27,0)));

        for(int i=1;i<n;++i)
            for(int c1=0;c1<27;++c1)
                for(int c2=0;c2<27;++c2)
                    dp[i][c1][c2] = min({cost(w[i]-'A', w[i-1]-'A')+dp[i-1][c1][c2], cost(c1, w[i-1]-'A')+dp[i-1][w[i]-'A'][c2],
                                        cost(c2, w[i-1]-'A')+dp[i-1][c1][w[i]-'A']});

        return dp[n-1][26][26];
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
const int ALPHABET = 26;
const int INF = 1e9;

class Solution {
public:
    int minimumDistance(string word) {
        vector<int> dp(ALPHABET, 0);
        int N = word.size();
        
        for (int i = 0; i < N - 1; i++) {
            char next = word[i + 1], current = word[i];
            vector<int> next_dp(ALPHABET, INF);

            for (int c = 0; c < ALPHABET; c++) {
                next_dp[c] = dp[c] + distance(current, next);
            }

            for (int c = 0; c < ALPHABET; c++) {
                next_dp[current - 'A'] = min(next_dp[current - 'A'], dp[c] + distance('A' + c, next));
            }

            dp = next_dp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
    
    int distance(char a, char b) {
        assert('A' <= a && a <= 'Z');
        assert('A' <= b && b <= 'Z');
        int x = a - 'A';
        int y = b - 'A';
        return abs(x / 6 - y / 6) + abs(x % 6 - y % 6);
    }
};