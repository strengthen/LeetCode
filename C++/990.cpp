__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    vector<int> p;
    int findRoot(int x){
        int r = x;
        for(;p[r] != r; ) r = p[r];
        for(; p[x] != r;){
            int tp = p[x];
            p[x] = r;
            x = tp;
        }
        return r;
    }
    
    bool equationsPossible(vector<string>& equations) {
        sort(equations.begin(), equations.end(), [](const auto & a, const auto&b) {
            return a[1] > b[1];
        });
        int C = 26;
        p.assign(C, -1);
        for(int i = 0; i < C; ++ i) p[i] = i;
        
        for(auto & s: equations)
        {
            int a = s[0] - 'a', b = s[3] - 'a';
            if(a > b) swap(a, b);
            int ra = findRoot(a), rb = findRoot(b);
            if(s[1] == '=')                
            {                
                p[ra] = rb;
            }
            else 
            {
                if(ra == rb)  return false;                
            }
        }
        return true;
        
    }
};
__________________________________________________________________________________________________
sample 9392 kb submission
static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    bool equationsPossible(vector<string>& e) 
    {
        int dp[26];
        for(int i=0;i<26;i++)dp[i]=i;
        int rank[26]{0};
        for(auto a: e)
        {
            int i=a[0]-'a';
            int j=a[3]-'a';
            
            if(a[1]=='=')
            {
               // cout<<i<<" " <<j<<endl;
                if(i==j)continue;
                if(rank[dp[i]]>rank[dp[j]])
                {
                    rank[dp[i]]++;
                    dp[j]=dp[i];
                }
                else
                {
                    rank[dp[j]]++;
                    dp[i]=dp[j];
                }
            }
            
        }
        for(auto a:e)
        {
            int i=a[0]-'a';
            int j=a[3]-'a';
            if(a[1]=='!')
            {
                if(dp[i]==dp[j])return false;
            } 
        }
        return true;
    }
};
__________________________________________________________________________________________________
