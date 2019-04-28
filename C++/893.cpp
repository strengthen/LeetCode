__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        std::unordered_map<std::string, int> table;
        for (const auto& s : A) {
            std::string even, odd;
            even.reserve(s.size()/2+1);
            odd.reserve(s.size()/2+1);
            for (size_t i=0; i<s.size(); ++i) {
                if (i % 2) {
                    odd += s[i];
                } else {
                    even += s[i];
                }
            }
            std::sort(even.begin(), even.end());
            std::sort(odd.begin(), odd.end());
            std::string evenPlusOdd = even + "|" + odd;
            table[evenPlusOdd]++;
        }
        return table.size();
    }
};

static auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
sample 9944 kb submission
class Solution {
public:
    int numSpecialEquivGroups(vector<string> &A) {
        set<string> groups;
        for (auto word: A) {
            string even, odd;
            for (int i=0;i < word.size();) {
                even += word[i];
                i+=1;
                odd  += word[i];
                i+=1;
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            groups.insert(odd + even);
        }
        return groups.size();
    }
};
__________________________________________________________________________________________________
