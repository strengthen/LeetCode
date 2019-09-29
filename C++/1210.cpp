__________________________________________________________________________________________________
24ms
class Solution {
public:
    
    struct Pos {
        int x, y, rt;
    };
    
    int dist[102][102][2];
    vector<Pos> q;
    
    void add(int newX, int newY, int newRt, int newDist) {
        if (dist[newX][newY][newRt] == -1) {
            dist[newX][newY][newRt] = newDist;
            q.push_back(Pos{newX, newY, newRt});
        }
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        memset(dist, -1, sizeof(dist));
        q.clear();
    
        int n = grid.size();
        
        dist[0][0][0] = 0;
        q.push_back(Pos{0, 0, 0});
        for (int i = 0; i < q.size(); ++i) {
            int curX = q[i].x;
            int curY = q[i].y;
            int curRt = q[i].rt;
            int curDist = dist[curX][curY][curRt];
            
            // Move right
            {
                if (curRt == 0) {
                    if (curY + 2 < n && grid[curX][curY + 2] == 0) {
                        add(curX, curY + 1, curRt, curDist + 1);
                    }
                } else {
                    if (curY + 1 < n && grid[curX][curY + 1] == 0 && grid[curX + 1][curY + 1] == 0) {
                        add(curX, curY + 1, curRt, curDist + 1);
                    }
                }
            }
            
            // Move down
            {
                if (curRt == 0) {
                    if (curX + 1 < n && grid[curX + 1][curY] == 0 && grid[curX + 1][curY + 1] == 0) {
                        add(curX + 1, curY, curRt, curDist + 1);
                    }
                } else {
                    if (curX + 2 < n && grid[curX + 2][curY] == 0) {
                        add(curX + 1, curY, curRt, curDist + 1);
                    }
                }
            }
            
            // Rotate
            {
                if (curRt == 0) {
                    if (curX + 1 < n && grid[curX + 1][curY] == 0 && grid[curX + 1][curY + 1] == 0) {
                        add(curX, curY, 1, curDist + 1);
                    }
                } else {
                    if (curY + 1 < n && grid[curX][curY + 1] == 0 && grid[curX + 1][curY + 1] == 0) {
                        add(curX, curY, 0, curDist + 1);
                    }
                }
            }
        }
        
        return dist[n - 1][n - 2][0];
    }
};

__________________________________________________________________________________________________
sample 28 ms submission
class Solution {
public:
    int n;
    int dp[103][103][3];
    vector < vector < int > > A;
    // 0 vertical
    // 1 horizontal
    int rec(int row, int col, int hor) {
        if(row == n - 1 and col == n - 1) {
            return hor == 1 ? 0 : (1 << 28);
        }
        int &ret = dp[row][col][hor];
        if(~ret) {
            return ret;
        }
        ret = 1 << 29;
        if(hor) {
            if(col + 1 < n and A[row][col + 1] == 0) {
                ret = min(ret, 1 + rec(row, col + 1, 1));
            }
            // if(row + 1 < n and A[row + 1][col] == 0) {
            // }
            if(row + 1 < n and A[row + 1][col - 1] == 0 and A[row + 1][col] == 0) {
                ret = min(ret, 1 + rec(row + 1, col, 1));
                ret = min(ret, 1 + rec(row + 1, col - 1, 0));
            }
        } else {
            if(row + 1 < n and A[row + 1][col] == 0) {
                ret = min(ret, 1 + rec(row + 1, col, 0));
            }
            // if(col + 1 < n and A[row][col + 1] == 0) {
            // }
            if(col + 1 < n and A[row][col + 1] == 0 and A[row - 1][col + 1] == 0) {
                ret = min(ret, 1 + rec(row, col + 1, 0));
                ret = min(ret, 1 + rec(row - 1, col + 1, 1));
            }
        }
        return ret;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        A = grid;
        n = A.size();
        memset(dp, 0xff, sizeof(dp));
        int ans = rec(0, 1, 1);
        if(ans > (1 << 25)) {
            return -1;
        }
        return ans;
    }
};

/*
[[0,0,0,0,0,1],[1,1,0,0,1,0],[0,0,0,0,1,1],[0,0,1,0,1,0],[0,1,1,0,0,0],[0,1,1,0,0,0]]
[[0,0,1,1,1,1],[0,0,0,0,1,1],[1,1,0,0,0,1],[1,1,1,0,0,1],[1,1,1,0,0,1],[1,1,1,0,0,0]]
*/
__________________________________________________________________________________________________
sample 104 ms submission
class Solution {
private:
    struct state{
        int x;
        int y;
        int dir; // 0 = horizontal; 1 = vertical
        int step;
        bool turn;
        state(int x_, int y_, int dir_, int step_, bool turn_){
            x = x_;
            y = y_;
            dir = dir_;
            step = step_;
            turn = turn_;
        }
    };
    struct mycmp{
        bool operator()(const state& s1, const state& s2){
            return s1.step > s2.step;
        }
    };
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<bool>>> mark(n, vector<vector<bool>>(n, vector<bool>(2, false)));
        priority_queue<state, vector<state>, mycmp> pq;
        state start(0, 0, 0, 0, false);
        pq.push(start);
        while(!pq.empty()){
            state curr = pq.top();
            pq.pop();
            if(curr.x == n-1 && curr.y == n-2 && curr.dir == 0){
                return curr.step;
            }
            if(mark[curr.x][curr.y][curr.dir]){
                continue;
            }
            else{
                mark[curr.x][curr.y][curr.dir] = true;
            }
            if(curr.dir == 0){
                if(curr.y + 2 < n && grid[curr.x][curr.y + 2] == 0){
                    pq.push(state(curr.x, curr.y+1, 0, curr.step+1, false));
                }
                if(curr.x + 1 < n && grid[curr.x+1][curr.y] == 0 && grid[curr.x+1][curr.y+1] == 0){
                    pq.push(state(curr.x+1, curr.y, 0, curr.step+1, false));
                    if(!curr.turn){
                        pq.push(state(curr.x, curr.y, 1, curr.step+1, true));
                    }
                }
            }
            if(curr.dir == 1){
                if(curr.x + 2 < n && grid[curr.x+2][curr.y] == 0){
                    pq.push(state(curr.x+1, curr.y, 1, curr.step+1, false));
                }
                if(curr.y + 1 < n && grid[curr.x][curr.y+1] == 0 && grid[curr.x+1][curr.y+1] == 0){
                    pq.push(state(curr.x, curr.y+1, 1, curr.step+1, false));
                    if(!curr.turn){
                        pq.push(state(curr.x, curr.y, 0, curr.step+1, true));
                    }
                }
            }
            
        }
        return -1;
    }
};
