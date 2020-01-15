__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    int r,c;
    
    void preProcess(vector<vector<int>>& mat, vector<vector<int>>& aux) 
    { 
       // Copy first row of mat[][] to aux[][] 
       for (int i=0; i<c; i++) 
          aux[0][i] = mat[0][i]; 

       // Do column wise sum 
       for (int i=1; i<r; i++) 
          for (int j=0; j<c; j++) 
             aux[i][j] = mat[i][j] + aux[i-1][j]; 

       // Do row wise sum 
       for (int i=0; i<r; i++) 
          for (int j=1; j<c; j++) 
             aux[i][j] += aux[i][j-1]; 
    }
    
    int sumQuery(vector<vector<int>>& aux, int tli, int tlj, int rbi, int rbj) 
    { 
        // result is now sum of elements between (0, 0) and 
        // (rbi, rbj) 
        int res = aux[rbi][rbj]; 

        // Remove elements between (0, 0) and (tli-1, rbj) 
        if (tli > 0) 
           res = res - aux[tli-1][rbj]; 

        // Remove elements between (0, 0) and (rbi, tlj-1) 
        if (tlj > 0) 
           res = res - aux[rbi][tlj-1]; 

        // Add aux[tli-1][tlj-1] as elements between (0, 0) 
        // and (tli-1, tlj-1) are subtracted twice 
        if (tli > 0 && tlj > 0) 
           res = res + aux[tli-1][tlj-1]; 

        return res; 
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> aux = mat;
        r=mat.size(), c=mat[0].size();
        preProcess(mat, aux);
        vector<vector<int>> ans = mat;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int tli=max(i-k,0), tlj=max(j-k,0), rbi=min(i+k,r-1), rbj=min(j+k,c-1);
                ans[i][j] = sumQuery(aux, tli, tlj, rbi, rbj);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
      const int N = mat.size();
      const int M = mat[0].size();        
      vector<vector<int>> sum(N + 1, vector<int>(M + 1, 0));
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          sum[i + 1][j + 1] = mat[i][j] + sum[i + 1][j] + 
                              sum[i][j + 1] - sum[i][j];
        }
      }
      vector<vector<int>> res(N, vector<int>(M, 0));
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          int x1 = max(1, i - K + 1);
          int y1 = max(1, j - K + 1);
          int x2 = min(N, i + K + 1);
          int y2 = min(M, j + K + 1);
          res[i][j] = sum[x2][y2] - sum[x2][y1 - 1] - 
                      sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
        }
      }
      return res;
    }
};
__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        
        int** sum = (int**)malloc(m*sizeof(int*));
        
        for(int i=0;i<m;i++)
            {sum[i] = (int*)malloc(n*sizeof(int));}
        
        sum[0][0] = mat[0][0];
        for(int i=1;i<m;i++)
            sum[i][0] = sum[i-1][0] + mat[i][0];
        for(int i=1;i<n;i++)
            sum[0][i]= sum[0][i-1] + mat[0][i];
        for(int i=1;i<m;i++)
            for(int j =1;j<n;j++)
            {
                sum[i][j] = sum[i-1][j]+sum[i][j-1] -sum[i-1][j-1] + mat[i][j];
                
            }
        for(int i =0;i<m;i++)
            for(int j =0;j<n;j++)
            {
                //cout<<sum[i][j]<<" ,";
                int top_r = max(0, i-K);
                int top_c = max(0, j-K);
                int bot_r = min(m-1, i+K);
                int bot_c = min(n-1, j+K);
                int sub=0;
                if(top_r-1>=0 && top_c-1>=0)
                    {sub = (sum[bot_r][top_c-1] + sum[top_r-1][bot_c] - sum[top_r-1][top_c-1]);
                     }
                else if(top_r>=1)
                    sub = ( sum[top_r-1][bot_c]);
                else if(top_c>=1)
                    sub = sum[bot_r][top_c-1];
                mat[i][j] = sum[bot_r][bot_c] - sub;
                    
            }
        return mat;
    }
};
static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();