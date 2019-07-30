__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& mat) {
        
              if(mat.empty())
                  return 0;
            int max = 0; int m = mat.size() , n = mat[0].size();
    vector<vector<int>> hor(m,vector<int> (n,0)) , ver(m,vector<int> (n,0));
   
    for (int i=0; i<m; i++) { 
        for (int j=0; j<n; j++) { 
            if (mat[i][j] == 1) 
            { 
                hor[i][j] = (j==0)? 1: hor[i][j-1] + 1;   
                ver[i][j] = (i==0)? 1: ver[i-1][j] + 1; 
            } 
        } 
    } 
        
    for (int i = m-1; i>=0; i--) { 
        for (int j = n-1; j>=0; j--) { 
            int small = min(hor[i][j], ver[i][j]);  // choose smallest of horizontal and vertical value
            while (small > max) { 
                if (ver[i][j-small+1] >= small &&  hor[i-small+1][j] >= small)  // check if square exists with 'small' length
                    max = small; 
                small--; 
            } 
        } 
    } 
    return max*max; 
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        vector<vector<int> > left(m, vector<int> (n, 0)), right(m, vector<int> (n, 0)), up(m, vector<int> (n, 0)), down(m, vector<int> (n, 0));
        
        for(int i = 0; i < m; i++)
        {
            int cur = 0;
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    cur++;
                else
                    cur = 0;
                left[i][j] = cur;
            }
        }
        for(int i = 0; i < m; i++)
        {
            int cur = 0;
            for(int j = n-1; j >= 0; j--)
            {
                if(grid[i][j] == 1)
                    cur++;
                else
                    cur = 0;
                right[i][j] = cur;
            }
        }
        for(int j = 0; j < n; j++)
        {
            int cur = 0;
            for(int i = 0; i < m; i++)
            {
                if(grid[i][j] == 1)
                    cur++;
                else
                    cur = 0;
                up[i][j] = cur;
            }
        }
        for(int j = 0; j < n; j++)
        {
            int cur = 0;
            for(int i = m-1; i >= 0; i--)
            {
                if(grid[i][j] == 1)
                    cur++;
                else
                    cur = 0;
                down[i][j] = cur;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int cur = grid[i][j];
                for(int k = 1; k < min(right[i][j], down[i][j]); k++)
                {
                    if(left[i + k][j + k] >= k+1 && up[i + k][j + k] >= k+1)
                        cur = pow(k+1, 2);
                }
                ans = max(cur, ans);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
