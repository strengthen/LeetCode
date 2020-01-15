__________________________________________________________________________________________________
sample 268 ms submission
auto static FASTIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum) {
        vector<vector<int>> ans;
        if (accumulate(colsum.begin(), colsum.end(), 0) == upper + lower) {
            int tmp = 0;
            for (int i : colsum) tmp += (i == 2 ? 1 : 0);
            upper -= tmp;
            lower -= tmp;
            if (upper < 0 || lower < 0) return ans;
            ans = vector<vector<int>>(2, vector<int>(colsum.size(), 0));
            bool flag = true;
            for (int i = 0; i < colsum.size(); ++i) {
                if (colsum[i] == 0) {
                    ans[0][i] = 0;
                    ans[1][i] = 0;
                } else if (colsum[i] == 2) {
                    ans[0][i] = 1;
                    ans[1][i] = 1;
                } else {
                    if (upper > 0) {
                        ans[0][i] = 1;
                        ans[1][i] = 0;
                        upper--;
                    } else {
                        ans[0][i] = 0;
                        ans[1][i] = 1;
                        lower--;
                    }
                }
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 272 ms submission
auto ds = []() {
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& colsum) {
       vector< vector <int> > ans(2, vector <int> (colsum.size(), 0));
        for (int i=0; i < colsum.size(); i++){
            if (colsum[i] == 2){
                u--; l--;
                ans[0][i] = 1;
                ans[1][i] = 1;
            }
            else{
                if(colsum[i] == 0) continue;
                if(l<u){ ans[0][i]=1; u--;
                       }   
                else {
                    ans[1][i] =1; l--;
                }
            }
        }
        if(u == 0 && l ==0)
        return ans; 
            else 
        return {};
    }
};
__________________________________________________________________________________________________
