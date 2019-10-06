__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        long mod = 1000000007;
        for(int j = 1; j < n; ++j) {
            long na = (e + i + u) % mod;
            long ne = (a + i) % mod;
            long ni = (e + o) % mod;
            long no = i;
            long nu = (i + o) % mod;
            a = na;
            e = ne;
            i = ni;
            o = no;
            u = nu;
        }
        return (a + e + i + o + u) % mod;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int countVowelPermutation(int n) {
        typedef long long int LL;
        LL f[5][20005];
        LL P = 1e9 + 7;
        // a=0, e=1, i=2, o=3, u=4
        f[0][0] = f[1][0] = f[2][0] = f[3][0] = f[4][0] = 1;
        for (int i = 1; i < n; i++) {
            // e/i/u + a
            f[0][i] = (f[1][i-1] + f[2][i-1] + f[4][i-1]) % P;
            // a/i + e
            f[1][i] = (f[0][i-1] + f[2][i-1]) % P;
            // e/o + i
            f[2][i] = (f[1][i-1] + f[3][i-1]) % P;
            // i + o
            f[3][i] = f[2][i-1] % P;
            // i/o + u
            f[4][i] = (f[2][i-1] + f[3][i-1]) % P;
        }
        
        return (f[0][n-1] + f[1][n-1] + f[2][n-1] + f[3][n-1] + f[4][n-1]) % P;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
constexpr int MOD = 1000000007;

class Solution {
public:
  int countVowelPermutation(int n) {
    vector<vector<long long>> f(2, vector<long long>(5));
    for (int i = 0; i < 5; ++ i) {
      f[0][i] = 1;
    }
    for (int i = 1; i < n; ++ i) {
      int x = i & 1;
      for (int j = 0; j < 5; ++ j) {
        f[x][j] = 0;
      }
      f[x][1] += f[1 - x][0];

      f[x][0] += f[1 - x][1];
      f[x][2] += f[1 - x][1];

      f[x][0] += f[1 - x][2];
      f[x][1] += f[1 - x][2];
      f[x][3] += f[1 - x][2];
      f[x][4] += f[1 - x][2];

      f[x][2] += f[1 - x][3];
      f[x][4] += f[1 - x][3];

      f[x][0] += f[1 - x][4];

      for (int j = 0; j < 5; ++ j) {
        f[x][j] %= MOD;
      }
    }
    long long ans = 0;
    for (int j = 0; j < 5; ++ j) {
      ans = (ans + f[(n - 1) & 1][j]) % MOD;
    }
    return (int)ans;
  }
};
