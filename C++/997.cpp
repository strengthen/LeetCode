__________________________________________________________________________________________________
sample 112 ms submission
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
class Solution
{
public:
    int findJudge(int N, vector<vector<int>>& trust)
    {
        if (N == 1)
            return true;
        
        bool trustsSomeone[N + 1] = {0};
        int trustedBy[N + 1] = {0};
        
        for (const auto& pair : trust)
        {
            trustsSomeone[pair[0]] = true;
            trustedBy[pair[1]] += 1;
        }
        
        for (int i = 1; i <= N; ++i)
        {
            if (trustsSomeone[i] == false && trustedBy[i] == N - 1)
                return i;
        }
        
        return -1;
    }
};
__________________________________________________________________________________________________
sample 116 ms submission
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // balance count = how many trusted me -  how many I trust
        vector<int> counts(N+1);
        for( const auto &pair : trust)
        {
            counts[pair[0]]--;
            counts[pair[1]]++;
        }
        
        for(int i=1; i <= N; i++)
            if( counts[i] == N-1 )
                return i;
        
        return -1;        
    }
};

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
__________________________________________________________________________________________________
