__________________________________________________________________________________________________
4ms
class Solution {
public:
    int fac(int n) {
        if (n == 1) return 1;
        
        return n * fac(n - 1);
    }
    
    void getPermutation(vector<int>& remain, vector<int>& result, int k) {
        int n = remain.size();
        if (n == 0) return;
        if (n == 1) {
            result.push_back(remain[0]);
            return;
        }
        
        int fact = fac(n - 1);
        int offset = k / fact;
        result.push_back(remain[offset]);
        remain.erase(remain.begin() + offset);
        getPermutation(remain, result, k % fact);
    }
    
    
    string getPermutation(int n, int k) {
        vector<int> remain;
        for (int i = 1; i <= n; ++i) {
            remain.push_back(i);
        }
        vector<int> result;
        
        getPermutation(remain, result, k - 1);
        
        std::ostringstream result_oss;
        for (int n : result) {
            result_oss << n;
        }
        return result_oss.str();
    }
};
__________________________________________________________________________________________________
8296 kb
static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();
class Solution {
public:
    string ans;
    int N;
    vector<bool> used;
    int factorial(int n){
        int f=1;
        for(int i=2;i<=n;i++)
            f*=i;
        return f;
    }
    void helper(int n,int k){
        int fa=factorial(n-1);
        int m=1+(k-1)/fa,j=0;
        while(n>0){
            for(int i=1;i<=N;i++){ 
                if(!used[i]&&(++j)==m){
                    ans+=to_string(i);
                    used[i]=true;
                    k-=(m-1)*fa;
                    n--;
                    fa=factorial(n-1);
                    m=1+(k-1)/fa;
                    j=0;
                    break;
                }
            }
        }
    }
    string getPermutation(int n, int k) { 
        N=n;
        used.resize(n+1);
        helper(n,k);
        return ans;
    }
};
__________________________________________________________________________________________________
