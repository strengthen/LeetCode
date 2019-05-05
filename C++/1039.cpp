__________________________________________________________________________________________________
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int N = 122;

VI a;
int dp[N][N];

int go(int l, int r) {
    if (r <= l || l + 1 == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ret = 0x3F3F3F3F;
    for (int k = l + 1; k <= r - 1; ++k) {
        ret = min(ret, go(l, k) + go(k, r) + a[l] * a[k] * a[r]);
    }
    return dp[l][r] = ret;
}

class Solution {
public:
    int minScoreTriangulation(vector<int>& a) {
        FILL(dp, -1);
        ::a = a;
        
        int ans = 0x3F3F3F3F;
        int n = a.size();
        REP(i, n) ::a.PB(a[i]);
        if (n == 3) return a[0] * a[1] * a[2];
        for (int x = 0; x < n; ++x) {
            for (int i = 2; i + 2 <= n; ++i) {
                ans = min(ans, go(x, i + x) + go(i + x, n + x));
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
