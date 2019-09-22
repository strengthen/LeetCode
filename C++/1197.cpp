__________________________________________________________________________________________________
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 310

int dir[8][2] = {-1,2,1,2,2,1,2,-1,-1,-2,1,-2,-2,1,-2,-1};
int dst[MAXN][MAXN];
class Solution {
public:
    int minKnightMoves(int X, int Y) {
      X = abs(X); Y = abs(Y);
      X += 3; Y += 3;
      queue<PII> q;
      q.push(PII(3, 3));
      REP(i,0,MAXN)REP(j,0,MAXN) dst[i][j] = INF;
      dst[3][3] = 0;
      while (q.size()) {
        PII now = q.front(); q.pop();
        int x = now.first, y = now.second;
        if (x == X && y == Y) return dst[x][y];
        REP(t,0,8) {
          int nx = x + dir[t][0], ny = y + dir[t][1];
          if (nx < 0 || ny < 0 || nx >= MAXN || ny >= MAXN) continue;
          if (dst[nx][ny] == INF) {
            dst[nx][ny] = dst[x][y] + 1;
            q.push(PII(nx, ny));
          }
        }
      }
      return -1;  
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
