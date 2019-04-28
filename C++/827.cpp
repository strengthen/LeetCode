__________________________________________________________________________________________________
sample 8 ms submission

class Solution {
public:
    int a[50][50]={0};//对岛分类编号
    int area[700]={0};//不同编号的岛对应不同的面积
    int islandnum=0;//编号
    void search(vector<vector<int>>& grid,int x,int y)
    {
        int X=grid.size();
        int Y=grid[0].size();
        if(grid[x][y]==1&&a[x][y]==0)
        {
            area[islandnum]++;//累计相同编号的岛的陆地
            a[x][y]=islandnum;//给陆地附上编号
            if(x-1>=0)  search(grid,x-1,y);//四个方向
            if(x+1<X)  search(grid,x+1,y);
            if(y-1>=0)  search(grid,x,y-1);
            if(y+1<Y)  search(grid,x,y+1);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {    
        int X=grid.size();
        int Y=grid[0].size();
        for(int i=0;i<X;i++)
        {
            for(int j=0;j<Y;j++)
            {
                if(grid[i][j]==1&&a[i][j]==0)
                {
                    islandnum++;//找到的第一个岛，应该从编号1开始
                    search(grid,i,j);
                }
            }
        }
        int b[4]={0};//海的四个方向的岛的编号，上下左右
        int maxsum=0,sum;
        for(int i=0;i<X;i++)
        {
            for(int j=0;j<Y;j++)
            {
                if(grid[i][j]==0)
                {
                    sum=1;//毕竟填海嘛，面积得从1算起
                    if(i-1<0)  b[0]=0;
                    else b[0]=a[i-1][j];//上没有越界，则附值上方的岛的编号
                    if(i+1>=X)  b[1]=0;
                    else b[1]=a[i+1][j];//同理
                    if(j-1<0)  b[2]=0;
                    else b[2]=a[i][j-1];//同理
                    if(j+1>=Y)  b[3]=0;
                    else b[3]=a[i][j+1];//同理
                    for(int k=0;k<4;k++)
                    {
                        if(b[k]!=0)
                        {
                            sum+=area[b[k]];//加上该方向的岛的编号的面积
                            for(int l=k+1;l<4;l++)
                            {
                                if(b[l]==b[k])  b[l]=0;//保证四个方向不会出现相同编号的岛
                            }
                            //b[k]=0;
                        }
                        if(sum>maxsum)  maxsum=sum;
                    }
                }
            }
        }
        if(maxsum==0)  maxsum=X*Y;//没有海的情况下
        return maxsum;
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
    // with changes as in a submission 
    class Solution {
        vector<vector<int> > dir = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
    public:
        int largestIsland(vector<vector<int> >& grid) {
            int index = 2, m = grid.size(), n = grid[0].size();
            vector<int> area(2);
            int res = 0;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (grid[i][j] == 1) {
                        int a = dfs(i, j, grid, index++);
                        res = max(res, a);
                        area.push_back(a);
                    }
            vector<int> seen;
            for (int i = 0; i < m; i++) 
                for (int j = 0; j < n; j++)
                    if (grid[i][j] == 0) {
                        //unordered_set<int> hs;
                        int r = 1;
                        for (int d = 0; d < 4; d++) {
                            int ii = i + dir[d][0], jj = j + dir[d][1];
                            if (ii >= 0 && ii < m && jj >= 0 && jj < n && area[grid[ii][jj]] > 0) { // !hs.count(grid[ii][jj])) {
                                int& a = area[grid[ii][jj]];
                                r += a;
                                a *= -1;
                                seen.push_back(grid[ii][jj]); // to restore later
                                //hs.insert(grid[ii][jj]);
                            }
                        }
                        res = max(res, r);
                        for (int x : seen) area[x] *= -1; // restore area values
                        seen.clear();
                    }
            return res;
        }
        int dfs(int i, int j, vector<vector<int> >& g, int x) {
            g[i][j] = x;
            int res = 1;
            for (int d = 0; d < 4; d++) {
                int ii = i + dir[d][0], jj = j + dir[d][1];
                if (ii >= 0 && ii < g.size() && jj >= 0 && jj < g[0].size() && g[ii][jj] == 1)
                    res += dfs(ii, jj, g, x);
            }
            return res;
        }
    };
__________________________________________________________________________________________________
sample 16 ms submission
class UnionFind {
public:
    UnionFind(int n): sz(n,0),id(n,0) {
        for (int i=0;i<n;i++) id[i]=i;
    }
    
    bool find(int p, int q) {
        if (root(p)!=root(q)) return false;
        else return true;
    }
    
    void merge(int p, int q) {
        int rp=root(p), rq=root(q);
        if (rp==rq) return;
        if (sz[rp]>=sz[rq]) {
            id[rq]=rp;
            sz[rp]+=sz[rq];
        }
        else {
            id[rp]=rq;
            sz[rq]+=sz[rp];
        }
    }
    
    int root(int p) {
        while (id[p]!=p) {
            id[p]=id[id[p]];
            p=id[p];
        }
        return p;
    }
    
    int trial(int x, int y, int n, int m) {
        int index=x*n+y;
        vector<int> r(4,-1),s(4,0);
        if (x>0) {r[0]=root(index-m); s[0]=sz[r[0]];}//up
        if (y>0) {r[1]=root(index-1); s[1]=sz[r[1]];}//left
        if (x<n-1) {r[2]=root(index+m); s[2]=sz[r[2]];}//below
        if (y<m-1) {r[3]=root(index+1); s[3]=sz[r[3]];}//right
        //cout<<x<<","<<y<<":"<<s[0]<<" "<<s[1]<<" "<<s[2]<<" "<<s[3]<<endl;
        for (int i=0;i<4;i++) {
            if (r[i]==-1) continue;
            for (int j=i+1;j<4;j++) {
                if (r[i]==r[j]) s[i]=0;
            }
        }
        return s[0]+s[1]+s[2]+s[3]+1;
    }
    
    void add(int p) {
        sz[p]=1;
    }
//private:
    vector<int> id;
    vector<int> sz;
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        UnionFind obj(n*m);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) {
                int index=i*m+j;
                if (grid[i][j]==1) {
                    obj.add(index);
                    if (i>0 && grid[i-1][j]==1) obj.merge(index,index-m);
                    if (j>0 && grid[i][j-1]==1) obj.merge(index,index-1);
                }
            }
        //cout<<"1111"<<endl;
        int res=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) {
                if (grid[i][j]==0) {
                    res=max(res,obj.trial(i,j,n,m));
                }
            }
        if (res==0) res=n*m;
        return res;
    }
};
__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<int> areas;
        vector<vector<int>> ids(rows, vector<int>(cols, -1));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1 && ids[i][j] < 0){
                    int k = areas.size();
                    areas.push_back(dfs(grid, i, j, ids, k));
                }
            }
        }
        int res = 0;
        int dirs[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    set<int> s;
                    int cur = 1;
                    for(int k = 0; k < 4; k++){
                        int x = i + dirs[k][0], y = j + dirs[k][1];
                        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1 && s.count(ids[x][y]) == 0){
                            s.insert(ids[x][y]);
                            cur += areas[ids[x][y]];
                        }
                    }
                    res = max(res, cur);
                }
            }
        }
        return res == 0 ? rows*cols : res;
    }
    
    int dfs(const vector<vector<int>>& grid, int row, int col, vector<vector<int>>& gridIds, int id){
        int dirs[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
        int area = 1;
        gridIds[row][col] = id;
        for(int i = 0; i < 4; i++){
            int x = row + dirs[i][0], y = col + dirs[i][1];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1 && gridIds[x][y] < 0) {
                area += dfs(grid, x, y, gridIds, id);
            }
        }
        return area;
    }
};
__________________________________________________________________________________________________
sample 10004 kb submission
class Solution {
    int color = 2;
    int count = 0;
    unordered_map<int, int> m;
    int curmax = 0;
public:
    void dfs(vector<vector<int>> &grid, int i, int j) {
        if (grid[i][j] != 1) return;
        grid [i][j] = color;
        count++;
        if (i > 0) dfs(grid, i-1, j);
        if (i < grid.size()-1) dfs(grid, i+1, j);
        if (j > 0) dfs(grid, i, j-1);
        if (j < grid[0].size()-1) dfs(grid, i, j+1);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        // color the grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    m[color] = count;
                    if (count > curmax) {
                        curmax = count;
                    }
                    count = 0;
                    color++;
                }
            }
        }
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    int a = 0;
                    int b = 0;
                    int c = 0;
                    int d = 0;
                    int temp = 1;
                    if (i > 0) {
                        a = grid[i-1][j];
                    }
                    if (i < grid.size()-1) {
                        b = grid[i+1][j];
                    }
                    if (j > 0) {
                        c = grid[i][j-1];
                    }
                    if (j < grid[0].size()-1) {
                        d = grid[i][j+1];
                    }
                    if (a != 0) {
                        temp += m[a];
                    }
                    if (b != 0 && b != a) {
                        temp += m[b];
                    }
                    if (c != 0 && c != b && c != a) {
                        temp += m[c];
                    }
                    if (d != 0 && d != c && d != b && d != a) {
                        temp += m[d];
                    }
                    if (temp > curmax) {
                        curmax = temp;
                    }
                }
            }
        }
        return curmax;
    }
};
__________________________________________________________________________________________________