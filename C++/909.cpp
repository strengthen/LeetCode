__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // BFS with queue
        // 2-D to 1-D
        int n = board.size();
        bool flag =true;
        int dest = n*n;
        int flat_board[dest];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
               int row = n-i-1;
               int col = flag? j:n-j-1;
               int index = n*i + j; 
               flat_board[index] = board[row][col];
            }
            flag = !flag;
        }
        vector<int> minStep(dest,-1);
        minStep[0] = 0;
        // index
        queue<int> q; 
        q.push(0);
        int res = -1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            // check if reach destination
            if(cur==dest-1){
                res = minStep[cur];
                break;
            }
            // BFS next 6 cells
            for(int i = 1;i<=6&&cur+i<dest;i++){
                // index from 0
                int index = flat_board[cur+i]>0? flat_board[cur+i]-1:cur + i;  
                // never visited or find less steps
                if(minStep[index]==-1||minStep[cur]+1<minStep[index]){
                    minStep[index] = minStep[cur] + 1;
                    q.push(index);
                  }
            }
        }
        
        
        return res;
    }
};
static int seepup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        q.push(1);
        int step =0;
        while(!q.empty()){
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                auto f = q.front();
                q.pop();
                pair<int,int> m;
                if (f == n*n) return step; 
                
                for(int move = 1;move<=6;move++){
                    int next = f+move;
                    if(next > n*n) break;
                    m = getMove(next,n);
                    int x = m.first;
                    int y = m.second;
                    if(board[x][y] != -1)
                        next = board[x][y];
                    if(board[x][y] != n*n+1){
                        q.push(next);
                        board[x][y]=n*n+1;
                    }
                    
                }
            }
            step++;
        }
        return -1;
    }
    
    pair<int,int> getMove(int next, int n){
        int x = (next-1)/n;
        int y = (next-1)%n;
        if(x % 2 == 1) {
            y = n - 1 - y;
        }
        x = n - 1 - x;
        return {x,y};
    }
};
__________________________________________________________________________________________________
sample 11012 kb submission
class Solution {
    int m_n;
    
    inline tuple<int, int> _posToRc(int pos) {
        int r = m_n - 1 - (pos - 1) / m_n;
        
        int c = ((m_n - 1 - r) % 2 == 1)
            ? m_n - 1 - (pos - 1) % m_n
            : (pos - 1) % m_n;

        return make_tuple(r, c);
    }
    
    int _sp(const vector<vector<int>> &board) {
        int N = m_n * m_n;
        vector<bool> visited(N + 1, false);
        queue<int> q;
        int dist = 0;
        
        q.push(1);
        
        while (!q.empty()) {
            int s = q.size();
            ++dist;
            for (int k = 0; k < s; ++k) {
                int n = q.front(); q.pop();
                int limit = min(N, n + 6);
                
                for (int k = n + 1; k <= limit; ++k) {
                    int rc, cc;
                    tie(rc, cc) = _posToRc(k);
                    int nc = (board[rc][cc] != -1) ? board[rc][cc] : k;
                    if (!visited[nc]) {
                        visited[nc] = true;
                        q.push(nc);
                        if (nc == N)
                            return dist;
                    }
                }
            }
        }
        
        return -1;
    }
    
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        m_n = board.size();
        return _sp(board);
    }
};