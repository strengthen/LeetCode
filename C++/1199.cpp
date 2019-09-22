__________________________________________________________________________________________________
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

class Solution {
public:
    int s;
    VI b;
    bool possible(int T) {
      int i = 0, free = 1, j = 0;
      VI ord;
      ord.push_back(0);
      while (i < b.size()) {
        if (j >= ord.size()) return false;
        int t = ord[j++];
        if (free < b.size() - i && t + s + b[i] <= T) {
          ord.push_back(t + s);
          ord.push_back(t + s);
          free++;
        } else {
          i++;
          free--;
        }
      }
      return true;
    }
    int minBuildTime(vector<int>& blocks, int split) {
      b = blocks; s = split;
      sort(b.rbegin(), b.rend());
      int l = 1, r = INF;
      while (l <= r) {
        int m = (l + r) / 2;
        if (possible(m)) r = m - 1;
        else l = m + 1;
      }
      return l;
    }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
