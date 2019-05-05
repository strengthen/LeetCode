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

int getMin(VI x) {
    int n = x.size();
    int next = 0;
    int best = 0;
    bool spe = false;
    for (int i = 0; i < n; ++i) {
        while (next < n && x[next] <= x[i] + n - 1) ++next;
        best = max(best, next - i);
        if (next - i == n - 1) {
            if (x[next - 1] - x[i] == n - 1) {
                spe = true;
            }
        }
    }
    if (best == n) return 0;
    if (best == n - 1) {
        return spe ? 1 : 2;
    }
    return n - best;
}

int go(VI x) {
    SORT(x);
    int n = x.size();
    return x[n - 1] - x[1] + 1 - (n - 1);
}

int getMax(VI x) {
    int ret = go(x);
    TR(it, x) *it = -*it;
    ret = max(ret, go(x));
    return ret;
}

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        SORT(stones);
        VI ret;
        ret.PB(getMin(stones));
        ret.PB(getMax(stones));
        return ret;
    }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
