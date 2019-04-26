__________________________________________________________________________________________________
sample 8 ms submission
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_m = m;
        int min_n = n;
        for(int i=0;i<ops.size();i++){
            if(min_m>ops[i][0]) min_m = ops[i][0];
            if(min_n>ops[i][1]) min_n = ops[i][1];
        }
        
        return min_m*min_n;
    }
};
__________________________________________________________________________________________________
sample 11796 kb submission
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = m;
        int y = n;
        for (int i = 0; i < ops.size(); i++) {
            x = x < ops[i][0] ? x : ops[i][0];
            y = y < ops[i][1] ? y : ops[i][1];
        }
        return x*y;
    }
};
__________________________________________________________________________________________________
