__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto &row:A)
            reverse(row.begin(),row.end());
        for(auto &row:A)
            for(auto &a:row)
                a^=1;
        return A;
    }
};
__________________________________________________________________________________________________
sample 9292 kb submission
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto & row : A) {
            int l = 0;
            int r = row.size() - 1;
            while (l < r) {
                int t = row[l] ^ 1;
                row[l] = row[r] ^ 1;
                row[r] = t;
                ++l;
                --r;
            }
            if (l == r){
                row[r] ^= 1;
            }
        }
        return std::move(A);
    }
};

static const auto _____ = []()
{
    // fast IO code : this I understand
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
