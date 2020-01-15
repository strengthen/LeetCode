__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
	int minPushBox(vector<vector<char>>& grid) {
		/* key (Box position, Man's position next to box or direction the box moving) 
		 * box's position (x, y) 0 <= x <= m-1, 0 <= y <= n-1
		 * man's position 0 - on left of box, 1 - top, 2 - right, 3 - bottom 
		 */
        
        /* get target, man and box's position */
		int m = grid.size(), n = grid[0].size();
		int Tx = -1, Ty = -1, Mx = -1, My = -1, Bx = -1, By = -1;
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (grid[i][j] == 'T'){Tx = i; Ty = j; grid[i][j] = '.';}
				if (grid[i][j] == 'B'){Bx = i; By = j; grid[i][j] = '.';}
				if (grid[i][j] == 'S'){Mx = i; My = j; grid[i][j] = '.';}
			}
		}

		/* 1. BFS find steps to push boxes to target
		 * 2. BFS find whether the person can move to the desired position
		 */
		constexpr int dirs[] = {0, +1, 0, -1, 0};
        
		/* bfsman, return true if man can move from (xman, yman) to (xdst, ydst) when box @ (xbox, ybox) */
		function<bool(int, int, int, int, int, int)>bfsman;
		bfsman = [&](int xman, int yman, int xdst, int ydst, int xbox, int ybox){
			queue<int> qt; qt.push((xman << 5) | yman); 
			// int visd[1024] = {0}; visd[(xman << 5) | yman] = 1;
            int visd[20][20] = {0}; visd[xman][yman] = 1; // (xman << 5) | yman] = 1;
			while (!qt.empty()){
				auto curr = qt.front(); qt.pop();
				int p = (curr >> 5), q = curr & 31;
				if ((p == xdst) && (q == ydst)){return true;}

				for (int d = 0; d < 4; ++d){
					int x = p + dirs[d], y = q + dirs[d+1];
					if ((x < 0) || (x >= m) || (y < 0) || (y >= n) || visd[x][y] || ((x == xbox) && (y == ybox)) || (grid[x][y] != '.')){continue;}
					visd[x][y] = 1;
					qt.push((x << 5) | y);
				}
			}

			return false;
		};

        /* bfsbox(box-x-pos, box-y-pos, man-x-pos, man-y-pos); */
		function<int(int, int, int, int)> bfsbox;
		bfsbox = [&](int p, int q, int u, int w){
			// queue<int> qt; int visd[4096] = {0}, steps = 0;
			queue<int> qt; int visd[4][20][20] = {0}, steps = 0;

			/* collect starting points */
			for (int d = 0; d < 4; ++d){
				/* man-x-next, man-y-next, box-x-next, box-y-next */
				int u2 = p - dirs[d], w2 = q - dirs[d+1], p2 = p + dirs[d], q2 = q + dirs[d+1];
				if ((u2 < 0) || (u2 >= m) || (w2 < 0) || (w2 >= n) || (p2 < 0) || (p2 >= m) || (q2 < 0) || (q2 >= n) || (grid[u2][w2] != '.') || (grid[p2][q2] != '.')){continue;}

				/* check whether man can move to desired position */
				if (bfsman(u, w, u2, w2, p, q)){
					qt.push((d << 10) | (p << 5) | q);
					visd[d][p][q] = 1;
				}
			}

			while (!qt.empty()){
				int L = qt.size(); ++steps;
				for (int i = 0; i < L; ++i){
					int curr = qt.front(), side = curr >> 10; qt.pop();

					/* man-x-pos, man-y-pos */
					u = (curr >> 5) & 31, w = (curr >> 0) & 31;

					/* box-x-pos, box-y-pos */
					p = u + dirs[side], q = w + dirs[side + 1];
					if ((p == Tx) && (q == Ty)) return steps;

					// printf("man = (%d, %d), box = (%d, %d), dir = %d\n", u, w, p, q, side);

					for (int d = 0; d < 4; ++d){
						/* man-x-next, man-y-next, box-x-next, box-y-next */
						int u2 = p - dirs[d], w2 = q - dirs[d+1], p2 = p + dirs[d], q2 = q + dirs[d+1];
						if ((u2 < 0) || (u2 >= m) || (w2 < 0) || (w2 >= n) || (p2 < 0) || (p2 >= m) || (q2 < 0) || (q2 >= n) || visd[d][p][q] || (grid[u2][w2] != '.') || (grid[p2][q2] != '.')){continue;}

						/* check whether man can move to desired position */
						if (bfsman(u, w, u2, w2, p, q)){
							qt.push((d << 10) | (p << 5) | q);
							visd[d][p][q] = 1;
						}
					}
				}
			}

			return (-1);
		};

		return bfsbox(Bx, By, Mx, My);
	};
};
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool canwalk(vector<vector<char>>& grid, int box, int dst, int src){
        int m = grid.size();
        int n = grid[0].size();
        vector<int> vis(m*n);
        queue<int> q;
        q.push(src);
        vis[src]=1;
        grid[box/n][box%n]='#';
        while(q.size()){
            int sz = q.size();
            while(sz--){
                int p = q.front();q.pop();
                if(p==dst){
                    grid[box/n][box%n]='.';
                    return 1;
                }
                int x = p/n, y = p%n;
                for(int i=0;i<4;i++){
                    int xx = x+dx[i];
                    int yy = y+dy[i];
                    if(xx<0 || yy<0 || xx>=m || yy>=n || grid[xx][yy]!='.'||vis[xx*n+yy]) continue;
                    vis[xx*n+yy] = 1;
                    q.push(xx*n+yy);
                }
            }
        }
        grid[box/n][box%n]='.';
        return 0;
    }
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int box, player, target;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='B'){
                    box = i*n+j;
                    grid[i][j]='.';
                }
                if(grid[i][j]=='T'){
                    target = i*n+j;
                    grid[i][j]='.';
                }
                if(grid[i][j]=='S'){
                    player = i*n+j;
                    grid[i][j]='.';
                }
            }
        }
        if(box==target) return 0;
        queue<pair<int,int>> q;
        q.push({box,player});
        unordered_set<string> v;
        int step = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto info = q.front();q.pop();
                int b = info.first;
                int p = info.second;
                if(b==target) return step;
                int x = b/n, y = b%n;
                for(int i=0;i<4;i++){
                    int new_bx = x+dx[i];
                    int new_by = y+dy[i];
                    int new_px = x-dx[i];
                    int new_py = y-dy[i];
                    if(new_bx<0 || new_bx>=m || new_by<0 || new_by>=n || grid[new_bx][new_by]=='#') continue;
                    if(new_px<0 || new_px>=m || new_py<0 || new_py>=n || grid[new_px][new_py]=='#') continue;
                    string s = to_string(b)+","+to_string(new_px*n+new_py);
                    if(v.count(s)) continue;
                    if(canwalk(grid,b,new_px*n+new_py,p)){
                        q.push({new_bx*n+new_by, b});
                        v.insert(s);
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
    
};
__________________________________________________________________________________________________
