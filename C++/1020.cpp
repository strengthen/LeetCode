__________________________________________________________________________________________________
sample 28 ms submission
static int _ = [](){std::ios::sync_with_stdio(false);cin.tie(NULL);return 0;}();

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<class K,class V> using umap = unordered_map<K,V>;
template<class T> using uset = unordered_set<T>;

#define F(i,l,r) for(int i=(l);i<(r);i++)
#define RF(i,l,r) for(int i=(r)-1;i>=l;i--)
#define FILL(a,v) memset(a,v,sizeof(a))
#define LOG(arg) cout << ""#arg" = " << (arg) << endl

const int MOD = 1e9+7;

class Solution {
public:
    void walk(vector<vector<int>>& a,int x,int y){
        int mx = a.size();
        int my = a[0].size();
        if(x < 0 || x >= mx || y < 0 || y >= my) return;
        if(a[x][y] == 0 || a[x][y] == 2) return;
        a[x][y] = 2;
        walk(a,x+1,y);
        walk(a,x-1,y);
        walk(a,x,y+1);
        walk(a,x,y-1);
    }
    
    int numEnclaves(vector<vector<int>>& a) {
        int mx = a.size();
        int my = a[0].size();
        F(i,0,mx){
            walk(a,i,0);
            walk(a,i,my-1);
        }
        F(i,0,my){
            walk(a,0,i);
            walk(a,mx-1,i);
        }
        int cnt = 0;
        F(x,0,mx){
            F(y,0,my){
                if(a[x][y] == 1) cnt++;
            }
        }
        return cnt;
    }
};
__________________________________________________________________________________________________
sample 32 ms submission
//广度优先搜索
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int h = A.size();
        int w = A[0].size();
        std::queue<std::pair<int,int>> help;
        
        for(int i=0;i<w;i++){
            if(A[0][i]==1){
                help.emplace(0,i);
                A[0][i] = -1;
            }
        }
        
        for(int i=0;i<w;i++){
            if(A[h-1][i]==1){
                help.emplace(h-1,i);
                A[h-1][i] = -1;
            }
        }       
        
        for(int i=1;i<h-1;i++){
            if(A[i][0]==1){
                help.emplace(i,0);
                A[i][0] = -1;
            }
        }        
 
        for(int i=1;i<h-1;i++){
            if(A[i][w-1]==1){
                help.emplace(i,w-1);
                A[i][w-1] = -1;
            }
        }
        
        while(!help.empty()){
            int x = help.front().first;
            int y = help.front().second;
            
            if(x>0 && A[x-1][y]==1){
                A[x-1][y] = -1;
                help.emplace(x-1,y);
            }
            
            if(x<h-1 && A[x+1][y]==1){
                A[x+1][y] = -1;
                help.emplace(x+1,y);
            }           
            
            if(y>0 && A[x][y-1]==1){
                A[x][y-1] = -1;
                help.emplace(x,y-1);
            }
            
            if(y<w-1 && A[x][y+1]==1){
                A[x][y+1] = -1;
                help.emplace(x,y+1);
            }            
            
            help.pop();
        }
        
        int res = 0;
        for(int i=1;i<h-1;i++){
            for(int j=1;j<w-1;j++){
                if(A[i][j]==1) res++;
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
