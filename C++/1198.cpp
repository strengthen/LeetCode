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
    int smallestCommonElement(vector<vector<int>>& mat) {
      int n = mat.size(), m = mat[0].size();
      VI idx(n, 0);
      REP(j,0,m) {
        int v = mat[0][j];
        REP(i,1,n) {
          while (idx[i] < m && mat[i][idx[i]] < v) idx[i]++;
        }
        bool match = true;
        REP(i,1,n) {
          if (!(idx[i] < m && mat[i][idx[i]] == v)) {
            match = false;
            break;
          }
        }
        if (match) return v;
      }
      return -1;
    }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
