__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<int>> b(8, vector<int>(8, 0));
        for(auto& q: queens) b[q[0]][q[1]] = 1;
        int x = king[0], y = king[1];
        for(int i = x, j = y; j < 8; j++) if (b[i][j] == 1) {ans.push_back(vector<int>{i, j});break;}
        for(int i = x, j = y; j >= 0; j--) if (b[i][j] == 1) {ans.push_back(vector<int>{i, j}); break;}
        for(int i = x, j = y; i >= 0; i--) if (b[i][j] == 1) {ans.push_back(vector<int>{i, j}); break;}
        for(int i = x, j = y; i < 8; i++) if (b[i][j] == 1) {ans.push_back(vector<int>{i, j});break;}
        
        for(int i = x, j = y; i < 8 && j < 8; i++, j++) if (b[i][j] == 1) {ans.push_back(vector<int>{i, j}); break;}
        for(int i = x, j = y; i < 8 && j >= 0; i++, j--) if (b[i][j] == 1) {ans.push_back(vector<int>{i, j}); break;}
        for(int i = x, j = y; i >= 0 && j < 8; i--, j++) if (b[i][j] == 1) {ans.push_back(vector<int>{i, j}); break;}
        for(int i = x, j = y; i >= 0 && j >= 0; i--, j--) if (b[i][j] == 1) {ans.push_back(vector<int>{i, j}); break;}
        return ans;        
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> king;
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
         vector<vector<int>> res;
        // Queens in same row of king (left+ right)
        // Queens in same col of king(up and down)
        // Queens in diagonal
        // queens in anti diagonal
        this->king=king;
        for( const auto & queen  : queens) {
            if( king[0]==queen[0] && queen[1] > king[1] ) {
                rowRight.emplace_back(queen);
            }
            if( king[0]==queen[0] && queen[1] < king[1] ) {
                rowLeft.emplace_back(queen);
            }
            if( king[1]==queen[1] && queen[0] > king[0] ) {
                colRight.emplace_back(queen);
            }
            if( king[1]==queen[1] && queen[0] < king[0] ) {
                colLeft.emplace_back(queen);
            }
            if( king[1]+king[0]==queen[1]+queen[0] && queen[1] < king[1] ) {
                diagLeft.emplace_back(queen);
            }
            if( king[1]+king[0]==queen[1]+queen[0] && queen[1] > king[1] ) {
                diagRight.emplace_back(queen);
            }

            if( king[1]-king[0]==queen[1]-queen[0] && queen[1] < king[1] ) {
                aDiagLeft.emplace_back(queen);
            }
            if( king[1]-king[0]==queen[1]-queen[0] && queen[1] > king[1] ) {
                aDiagRight.emplace_back(queen);
            }
        }
        if(rowLeft.size()) res.emplace_back(minDistance(rowLeft));
        if(rowRight.size()) res.emplace_back(minDistance(rowRight));
        if(colLeft.size()) res.emplace_back(minDistance(colLeft));
        if(colRight.size()) res.emplace_back(minDistance(colRight));
        if(diagLeft.size()) res.emplace_back(minDistance(diagLeft));
        if(diagRight.size()) res.emplace_back(minDistance(diagRight));
        if(aDiagLeft.size()) res.emplace_back(minDistance(aDiagLeft));
        if(aDiagRight.size()) res.emplace_back(minDistance(aDiagRight));
        return res;
    }
    vector<int> minDistance(vector<vector<int>>& queens ) {
        vector<int> minQ=queens[0];
        for( auto const& queen : queens) {
            if( (abs(king[0]-queen[0]) + abs(king[1]-queen[1]) ) < 
               ( abs(king[0]-minQ[0]) + abs(king[1]-minQ[1]) ) ) {
                minQ=queen;
            }
        }
        return minQ;
    }
    vector<vector<int>> rowLeft,rowRight,colLeft,colRight,diagLeft,diagRight,aDiagLeft,aDiagRight;
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>ans;
        int r = king[0];
        int c = king[1];
        int n =8;
        int m = 8;
        vector< vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<queens.size();i++)
        {
            vis[queens[i][0]][queens[i][1]]++;
        }
        //col
        for(int i=r+1;i<n;i++)
        {
            if(vis[i][c])
            {
                ans.push_back({i,c});
                break;
            }
        }
        for(int i=r-1;i>=0;i--)
        {
            if(vis[i][c])
            {
                ans.push_back({i,c});
                break;
            }
        }
        for(int i=c+1;i<m;i++)
        {
            if(vis[r][i])
            {
                 ans.push_back({r,i});
                break;
            }
        }
        for(int i=c-1;i>=0;i--)
        {
            if(vis[r][i])
            {
                  ans.push_back({r,i});
                break;
            }
        }
        int nr=r+1,nc=c+1;
        while(nr<n && nc<m)
        {
            if(vis[nr][nc])
            {
                  ans.push_back({nr,nc});
                break;
            }
            nr++;
            nc++;
        }
        nr=r-1,nc=c-1;
        while(nr>=0 && nc>=0)
        {
            if(vis[nr][nc])
            {
               ans.push_back({nr,nc});
                break;
            }
            nr--;
            nc--;
        }
        nr=r-1,nc=c+1;
        while(nr>=0 && nc<m)
        {
            if(vis[nr][nc])
            {
               ans.push_back({nr,nc});
                break;
            }
            nr--;
            nc++;
        }
        nr=r+1,nc=c-1;
         while(nr<n && nc>=0)
        {
            if(vis[nr][nc])
            {
               ans.push_back({nr,nc});
                break;
            }
            nr++;
            nc--;
        }
        return ans;
    }
};