__________________________________________________________________________________________________
sample 164 ms submission
static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX - 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) res[i][j] = 0;
                else {
                    if (i > 0) res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                    if (j > 0) res[i][j] = min(res[i][j], res[i][j - 1] + 1);
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (res[i][j] != 0 && res[i][j] != 1) {
                    if (i < m - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                    if (j < n - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1);
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 20956 kb submission
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<int>dirI={0,1,0,-1};
        vector<int>dirJ={1,0,-1,0};
        vector<vector<int>>ans=matrix;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                {
                    if(matrix[i][j]!=0)
                    {
                        bool flag=false;
                        for(int k=0;k<4;++k)
                        {
                            int i1=i+dirI[k];
                            int j1=j+dirJ[k];
                            if(i1==-1||i1==m||j1==-1||j1==n)
                                continue;
                            if(matrix[i1][j1]==0)
                            {   flag=true;
                                ans[i][j]=1;
                            }
                        }
                        if(flag)continue;
                        ans[i][j]=10000;
                    }
                }
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
            {
                if(ans[i][j]>=1)
                {
                    for(int k=0;k<4;++k)
                    {
                        int i1=i+dirI[k];
                        int j1=j+dirJ[k];
                        if(i1==-1||i1==m||j1==-1||j1==n)
                                continue;
                        ans[i][j]=min(ans[i][j],ans[i1][j1]+1);
                    }
                }
            }
        for(int i=m-1;i>=0;--i)
            for(int j=n-1;j>=0;--j)
            {
                if(ans[i][j]>=1)
                {
                    for(int k=0;k<4;++k)
                    {
                        int i1=i+dirI[k];
                        int j1=j+dirJ[k];
                        if(i1==-1||i1==m||j1==-1||j1==n)
                                continue;
                        ans[i][j]=min(ans[i][j],ans[i1][j1]+1);
                    }
                }
            }
        return ans;
    }   
};
__________________________________________________________________________________________________
