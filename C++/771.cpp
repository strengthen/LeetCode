__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int a = J.size();
        int b = S.size();
        int num = 0;
        
        for(int i = 0; i < a; ++i)
        {
            for(int j = 0; j < b; ++j)
            {
                if(J[i]==S[j])
                {
                    ++num;
                }
            }
        }
        return num;
    }
};
__________________________________________________________________________________________________
sample 8172 kb submission
static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        char has[256] = {0};
        for(auto & a :J){
            has[a] = 1;
        }
        int count = 0;
        for(auto &a:S){
            if(has[a]) ++count;
        }
        return count;
    }
};
__________________________________________________________________________________________________
