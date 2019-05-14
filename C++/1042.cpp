__________________________________________________________________________________________________
sample 116 ms submission
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ans(N, 0);
        int conn[N][3] = {{0}};
        int size[N] = {0};
        for(int i = 0; i < paths.size(); i++)
        {
            int src = paths[i][0] - 1;
            int tgt = paths[i][1] - 1;
            conn[src][size[src]++] = tgt;
            conn[tgt][size[tgt]++] = src;
        }
        for(int i = 0; i < paths.size(); i++)
        {
            int src = paths[i][0] - 1;
            int tgt = paths[i][1] - 1;
            if(ans[src] == ans[tgt])
            {
                if(ans[src] == 0)
                {
                    ans[src] = 1;
                    ans[tgt] = 2;
                }else{
                    int used[4] = {0};
                    used[ans[tgt] - 1] = 1;
                    for(int i = 0; i < size[src]; i++) if(ans[conn[src][i]] != 0) used[ans[conn[src][i]] - 1] = 1;
                    int j = 0;
                    while(j < 4 && used[j] == 1) j++;
                    ans[src] = j + 1;
                }
            }else{
                if(ans[src] == 0 || ans[tgt] == 0)
                {
                    int p = ans[src] == 0 ? src : tgt;
                    int q = ans[src] == 0 ? tgt : src;
                    ans[p] = ans[q] == 1 ? 2 : 1;
                }
            }
        }
        for(int i = 0; i < N; i++) if(ans[i] == 0) ans[i] = 1;
        return ans;
    }
};
__________________________________________________________________________________________________
sample 124 ms submission
class Solution {
public:
    int k[10005];
    int e[10005][4];
    
    void iterate(int m) {
        
        if(k[m] != 0) return;

        int c = (1<<4) -1;
        for(int j = 0; j < 4; ++j){
            if(e[m][j] == 0) break;
            if(k[e[m][j]] == 0) continue;
            c &= ~(1<<(k[e[m][j]]-1));
        }
  
        for(int i=0; i < 4; ++i){
            if((c & (1<<i)) > 0){
                k[m] = i + 1; 
                break;
            }
        }
//                cout << m << " " << c << " " << k[m] << endl;
        for(int j = 0; j < 4; ++j){
            if(e[m][j] == 0) break;
            iterate(e[m][j]);
        }
    }
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        
        for(int i = 0; i < paths.size(); ++i){
            int a = paths[i][0];
            int b = paths[i][1];
            for(int k = 0; k < 4;++k){
                if(e[a][k] == 0) { e[a][k] = b; break;}
            }
            for(int k = 0; k < 4;++k){
                if(e[b][k] == 0) { e[b][k] = a; break;}
            }
        }
        
        vector<int> ret;
        for(int i = 1; i <= N; ++i){
            if(k[i] == 0)    
                iterate(i);
            ret.push_back(k[i]);
        }
        return ret;
    }
};
__________________________________________________________________________________________________
