__________________________________________________________________________________________________
28ms
#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <complex>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define REP(i,n) for (int i=0; i<(n); ++i)
#define ALL(c) c.begin(), c.end()
#define CLR(c,n) memset(c, n, sizeof(c))
#define MCPY(d, s) memcpy(d, s, sizeof(d))
#define TR(it, c) for (auto it = c.begin();it != c.end(); ++it)
#define CONTAIN(it, c) (c.find(it) != c.end())
typedef vector<int> VI;
typedef pair<int, int> PII;
template <class T> void checkmin(T &a, T b) { if (b<a) a=b; }
template <class T> void checkmax(T &a, T b) { if (b>a) a=b; }
typedef long long LL;
const int INF=0x3F3F3F3F;

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
      int n = SZ(A), mx = *max_element(ALL(A));
      VI head(mx+1, -1), tail(mx+1, -1),  nxt(n, -1);
      for (int i = n - 1; i >= 0; --i) {
        int val = A[i];
        if (tail[val] == -1) tail[val] = i;
        nxt[i] = head[val];
        head[val] = i;
      }
      int best = 2;
      REP(i1, n) {
        int a0 = A[i1];
        for (int i2 = i1 + 1; i2 < n; ++i2) {
          int d = A[i2] - a0, ap = a0 - d;
          if(ap >= 0 && ap <= mx && head[ap]>=0 && head[ap] < i1) continue;
          int req = a0 + d * best;
          if (req < 0 || req > mx || tail[req] < i2 + best - 1) continue;
          int cnt = 2, a = A[i2], id = i2;
          while ((a+=d) >= 0 && a <= mx && tail[a] >= id + 1) {
            int inxt = head[a];
            while (inxt <= id) inxt = nxt[inxt];
            ++cnt;
            id = inxt;
          }
          checkmax(best, cnt);
        }
      }
      return best;
    }
};
__________________________________________________________________________________________________
44ms
class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n = a.size(), ans = 2, i = 0;
        vector<vector<int>> pos(10002);
        
        for (int i = 0; i < n; ++i)
            pos[a[i]].push_back(i);
        
        for (int i = 0; i < n-1; ++i)
            for (int j = i+1; j < n && n-j+1 > ans; ++j) {
                int d = a[j] - a[i], len = 2;
                int last = j, v = a[j] + d;
                while (v >= 0 && v <= 10000 && pos[v].size() > 0) {
                    int k = 0;
                    while (k < pos[v].size() && pos[v][k] <= last)
                        ++k;
                    
                    if (k == pos[v].size())
                        break;
                    
                    ++len;
                    last = pos[v][k];
                    v += d;
                }
                
                ans = max(ans, len);
            }
        
        return ans;
    }
};
__________________________________________________________________________________________________
56ms
const int MAXN = 2010;
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];
const int MAXM = 20100;
int pos[MAXM];

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }
        int maxV = *max_element(A.begin(), A.end());
        for (int i = 0; i < MAXM; ++i) {
            pos[i] = -1;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                pre[i][j] = -1;
                int num = A[i] * 2 - A[j];
                if (num >= 0) {
                    pre[i][j] = pos[num];
                }
            }
            pos[A[i]] = i;
        }
        
        int res = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = 0;
                
                int k = pre[i][j];
                if (k >= 0) {
                    dp[i][j] = max(dp[i][j], dp[k][i] + 1);
                } else {
                    dp[i][j] = 2;
                }
                // cout << i << " " << j <<  " " << k << ", " << A[j] - A[i] << " " << dp[i][j] << endl;
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
60ms
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<int> present[20000+5];
        int n = A.size();
        for(int i=0; i<n; ++i){
            present[A[i]].push_back(i);
        }
        int ma = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int start = A[i];
                int cd = A[j] - A[i];
                int ans = 2;
                int chek = cd + A[j];
                int ptr = j+1;
                while(true){
                    if( chek < 0 ){ break; }
                    if( present[chek].empty() ){ break; }
                    auto get = lower_bound( present[chek].begin(), present[chek].end(), ptr);
                    if( get == present[chek].end() ){ break; } 
                    ans++;
                    ptr = *get + 1;
                    chek += cd;
                }
                ma = max( ans, ma);
            }
        }
        return ma;
    }
};
__________________________________________________________________________________________________
64ms
inline void checkMax(int &y, int x) {
    if (x > y) {
        y = x;
    }
}
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        const int N = 2019;
        const int M = 11000;
        static int firstIndex[M];
        for (int i = 0; i < M; i += 1) {
            firstIndex[i] = -1;
        }
        const int n = A.size();
        static int f[N][N];
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                f[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i -= 1) {
            for (int j = n - 1; j > i; j -= 1) {
                f[i][j] = 2;
                int nextValue = A[j] * 2 - A[i];
                if (nextValue >= 0 && nextValue < M) {
                    int k = firstIndex[nextValue];
                    if (k != -1) {
                        checkMax(f[i][j], 1 + f[j][k]);
                    }
                }
                firstIndex[A[j]] = j;
                checkMax(ans, f[i][j]);
            }
            for (int j = i + 1; j < n; j += 1) {
                firstIndex[A[j]] = -1;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________