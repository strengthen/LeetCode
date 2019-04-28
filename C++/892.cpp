__________________________________________________________________________________________________
sample 4 ms submission
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();



class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size();
        if (N == 0) return 0;
        
        int output = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) output += 2;
                if (i == 0)
                    output += grid[i][j];
                if (i == N-1)
                    output += grid[i][j];
                if (i < N-1)
                    output += abs(grid[i+1][j]-grid[i][j]);
                if (j == 0)
                    output += grid[i][j];
                if (j == N-1)
                    output += grid[i][j];
                if (j < N-1)
                    output += abs(grid[i][j+1]-grid[i][j]);
            }
        }
        return output;
    }
};
__________________________________________________________________________________________________
sample 9664 kb submission
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid[0].size();
        //std::cout<<"size="<<n<<endl;
        int cubenum = 0;
        int layerdecrease = 0;
        int rc = 0;
        int sumnum = 0;
        
        if(n == 1)
        {
            return (grid[0][0]*4 + 2);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] > cubenum) cubenum = grid[i][j];
                if(grid[i][j] > 1) layerdecrease += (grid[i][j] - 1)*2;
                sumnum += grid[i][j];
            }
        }
        //std::cout<<"maxlayer:"<<cubenum<<endl<<"shuzhichongdie"<<layerdecrease<<endl<<"cube num:"<<sumnum<<endl;
        
        for(int k=1;k<=cubenum;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j] != 0)
                    {
                    //r1
                    if(i == 0)
                    {
                        if(j == 0)
                        {
                            if(grid[i][j+1] != 0) rc++;
                            if(grid[i+1][j] != 0) rc++;
                        }
                        else if(j == (n-1))
                        {
                            if(grid[i][j-1] != 0) rc++;
                            if(grid[i+1][j] != 0) rc++;
                        }
                        else
                        {
                            if(grid[i+1][j] != 0) rc++;
                            if(grid[i][j-1] != 0) rc++;
                            if(grid[i][j+1] != 0) rc++;
                        }
                    }
                    
                    //rn
                    if(i == (n-1))
                    {
                        if(j == 0)
                        {
                            if(grid[i-1][j] != 0) rc++;
                            if(grid[i][j+1] != 0) rc++;
                        }
                        else if(j == (n-1))
                        {
                            if(grid[i-1][j] != 0) rc++;
                            if(grid[i][j-1] != 0) rc++;
                        }
                        else
                        {
                            if(grid[i-1][j] != 0) rc++;
                            if(grid[i][j-1] != 0) rc++;
                            if(grid[i][j+1] != 0) rc++;
                        }
                    }
                    
                    if((j == 0) && (i != 0) && (i != (n-1)))
                    {
                        if(grid[i][j+1] != 0) rc++;
                        if(grid[i-1][j] != 0) rc++;
                        if(grid[i+1][j] != 0) rc++;
                    }
                    
                    if((j == (n-1)) && (i != 0) && (i != (n-1)))
                    {
                        if(grid[i][j-1] != 0) rc++;
                        if(grid[i-1][j] != 0) rc++;
                        if(grid[i+1][j] != 0) rc++;
                    }
                    
                    if((i != 0) && (i != (n-1)) && (j != 0) && (j != (n-1)))
                    {
                        if(grid[i-1][j] != 0) rc++;
                        if(grid[i][j+1] != 0) rc++;
                        if(grid[i+1][j] != 0) rc++;
                        if(grid[i][j-1] != 0) rc++;
                    }
                    
                }
            }
                //std::cout<<"row"<<i<<":"<<rc<<endl;
            }
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]>0) grid[i][j]--;
                    //std::cout<<grid[i][j]<<" ";
                }
               // std::cout<<endl;
            }
            
            //std::cout<<k<<"layer-rc:"<<rc<<endl;
        }
        
        return (sumnum*6 - layerdecrease - rc);
    }
};
__________________________________________________________________________________________________
