__________________________________________________________________________________________________
60ms
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return res;
    }
    
private:
    void dfs(int index,int n,int k){
        if(k==0){
            res.push_back(oneres);
            return;
        }
        if(index==n+1) return;
        for(int i=index;i<=n-k+1;++i){
            oneres.push_back(i);
            dfs(i+1,n,k-1);
            oneres.pop_back();
        }
        
    }
    vector<vector<int>> res;
    vector<int> oneres;
};
__________________________________________________________________________________________________
11564 kb
class Solution {
public:

vector<vector<int>> combine(int n, int k) 
{
    vector<vector<int>> sol;
    vector<int> sol1(k, 0);
        
    int i = 0;
    while (i>=0) {
        sol1[i]++;
        //left position, i+1, i+2,..., k-1 (total count k-i-1)
        //left numbers,  s[i]+1, s[i]+2, ..., n (total n-s[i])
        //if left number<left position, no need to continue
        if (sol1[i]>n-k+i+1 ) 
            --i;
        else if (i==k-1) 
            sol.push_back(sol1);
        else {
            ++i;
            sol1[i] = sol1[i-1];
        }
    }
    return sol;
}
};
__________________________________________________________________________________________________
