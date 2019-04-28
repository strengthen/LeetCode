__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int result = 0;
        
        int m = A.size();
        int n = A[0].size();
        
        for(int i = 0; i < m; i++)
        {
            if(A[i][0] == 1)
                continue;
            for(int j = 0; j < n; j++)
                A[i][j] = 1 - A[i][j];
        }
        
        for(int j = 0; j < n; j++)
        {
            int tmp = 0;
            for(int i = 0; i < m; i++)
                tmp += A[i][j];
            if(m - tmp < tmp)
                continue;
            for(int i = 0; i < m; i++)
                A[i][j] = 1 - A[i][j];
        }
        
        for(int i = 0; i < m; i++)
        {
            int tmp = 0;
            for(int j = 0; j < n; j++)
            {
                tmp = tmp * 2 + A[i][j];
            }
            result += tmp;
        }
        
        return result;
    }
};
__________________________________________________________________________________________________
sample 9056 kb submission
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        if(!m)
            return 0;
        int n = A[0].size();
        for(int i=0;i<m;i++){
            if(A[i][0]==0){
                for(auto & c: A[i]){
                    if(c)
                        c=0;
                    else
                        c=1;
                }
            }
        }
        int res = 0;
        res += m*(1<<(n-1));
        for(int i=1;i<n;i++){
            int n0 = 0;
            for(int j=0;j<m;j++){
                if(A[j][i]==0)
                    n0++;
            }
            int b = max(n0, m-n0);
            res += b*(1<<(n-1-i));
        }
        return res;
    }
};
__________________________________________________________________________________________________
