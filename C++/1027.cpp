__________________________________________________________________________________________________
sample 28 ms submission
static int x = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
   int n = A.size();
   int biggest = *max_element(A.begin(), A.end());
   
   // We make queues for all elements to easily check whether we
   // have an element with a given value and to get the first and last
   // index of the element with that value.
   
   // Contains the index of the first element with a given value.
   vector<int> head(biggest + 1, -1);
   
   // Contains the index of the last element with a given value.
   vector<int> tail(biggest + 1, -1);
   
   // Contains the index of the next element with the same value for given index.
   vector<int> next(n, -1);
   
   // Fill the queues
   for (int i = n - 1; i >= 0; --i) {
      int value = A[i];
      if (tail[value] == -1) {
         tail[value] = i;
      }
      next[i] = head[value];
      head[value] = i;
   }

   int best = 2;
   for (int i = 0; i < n; ++i) {
      // A[i] should be the first element of the sequence
      int first = A[i];
      for (int j = i + 1; j < n; ++j) {
         int dist = A[j] - first;
         // Check if we have already visited a sequence with the same distance
         int aPrev = first - dist;
         if (aPrev >= 0 && aPrev <= biggest && head[aPrev] >= 0 && head[aPrev] < i) {
            continue;
         }
		 
         // Check if it is possible to have longer sequence than the current best sequence
         int required = first + dist * best;
         if (required < 0 || required > biggest || tail[required] < j + best - 1) {
            continue;
         }
		 
         
         // Try to find a longer sequence
         int count = 2;
         int value = A[j] + dist;
         int idx = j;
         while (value >= 0 && value <= biggest && tail[value] > idx) {
            int nextIdx = head[value];
            while (nextIdx <= idx) {
               nextIdx = next[nextIdx];
            }
            ++count;
            idx = nextIdx;
            value += dist;
         }
         best = max(best, count);
      }
   }
   return best;
}
};
__________________________________________________________________________________________________
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
× Close
sample 44 ms submission
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