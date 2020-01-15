__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (auto& ind:indices) {
            row[ind[0]]++;
            col[ind[1]]++;
        }
        int r_count = 0;
        for (int i = 0; i < n; i++) {
            if (row[i] % 2 == 1)
                r_count++;
        }
        int ret = r_count * m;
        for (int i = 0; i < m; i++) {
            if (col[i] % 2 == 1) {
                ret -= r_count;
                ret += (n - r_count);
            }
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i =0;i<indices.size();i++)
        {
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }
        int ans=0;
        for(int i =0;i<n;i++)
            for(int j =0;j<m;j++)
            {
                if((row[i]+col[j])%2==1)
                    ans++;
            }
        return ans;
    }
};
static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices)
    {
        int count=0;
        bool matrix[n][m];
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<m;b++)
            {
                matrix[a][b]=false;
            }
        }

        for(vector<int> a: indices)
        {
            cout<<a[0]<<" "<<a[1]<<endl;
            for(int i=0;i<m;i++)
            {
                matrix[a[0]][i]=!matrix[a[0]][i];
                if(matrix[a[0]][i]==false) count--;
                else count++;
            }
            for(int j=0;j<n;j++)
            {
                matrix[j][a[1]]=!matrix[j][a[1]];
                if(matrix[j][a[1]]==false) count--;
                else count++;
            }
        }
            return count;
        
    }
};