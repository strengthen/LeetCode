__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        std::unordered_map<std::string, int> mapAB;
        std::istringstream ss(std::move(A + " " + B));
        std::string tk;
        while (ss >> tk) {mapAB[tk]++;}
        std::vector<std::string> uni;
        uni.reserve(mapAB.size());
        for (const auto& e : mapAB) {
            if (e.second == 1) {
                uni.emplace_back(e.first);
            }
        }
        return uni;
    }
};

static int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
sample 8956 kb submission
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) 
    {
        map<string, int> m;
        string current = "";
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i]!= ' '){current += A[i];}
            else {++m[current]; current = "";}
        }
        ++m[current];
        current = "";
        for(int i = 0; i < B.size(); ++i)
        {
            if(B[i]!= ' '){current += B[i];}
            else {++m[current]; current = "";}
        }
        ++m[current];
        vector<string> result;
        for(const auto entry : m)
        {
            if(entry.second==1){result.push_back(entry.first);}
        }
        return result;
    }
};
__________________________________________________________________________________________________
