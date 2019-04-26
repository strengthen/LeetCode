__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    // 并查集
    vector<int> fa;
    
    void init() {
        for(int i=0;i<fa.size();i++) {
            fa[i]=i;   
        }
    }
    
    int findf(int i) {
        while(fa[i]!=i) {
            fa[i]=fa[fa[i]];
            i=fa[i];
        }
        return fa[i];
    }
    
    void unionfa(int i, int j) {
        int a=findf(i);
        int b=findf(j);
        if(a==b) return ;
        fa[a]=b;
        return ;
    }
    
    
    int findCircleNum(vector<vector<int>>& M) {
        
        int len=M.size();
        if(len==0) return 0;
        fa.resize(len+1);
        init();
        for(int i=0;i<len;i++) {
            for(int j=0;j<len;j++) {
                if(i!=j && M[i][j] == 1)
                    unionfa(i,j);
            }
        }
        
        int us=0;
        for(int i=0;i<len;i++){
            if(fa[i] == i) us++; 
        }
        return us;
    }
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 11368 kb submission

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        
        for(int i=0; i<M.size(); i++)
        {
            for(int j=0; j<M[i].size(); j++)
            {
                if(i==j)
                    continue;
                if(M[i][j]==1)
                {
                    for(int k=0; k<M[j].size(); k++)
                        if(M[i][k]==1)
                            M[j][k]=1;
                }
            }
        }
        
        int circles=0;
        for(int i=0; i<M.size(); i++)
        {
            for(int j=0; j<M[i].size(); j++)
            {
                if(M[i][j]==1)
                {
                    if(i<=j)
                        circles++;
                    break;
                }
            }
        }
        return circles;
    }
};
__________________________________________________________________________________________________
