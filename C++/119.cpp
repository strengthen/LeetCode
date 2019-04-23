__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i <= rowIndex; i++) {
            res.push_back(1);
            for (int j = i - 1; j > 0; j--) {
                res[j] = res[j] + res[j - 1];
            }
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
8168 kb
class Solution {
public:
    int p[35][35];
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i <= rowIndex; ++i){
            ans.push_back(pascal(rowIndex, i));
        }
        return ans;
    }
    int pascal(int k, int i){
        if(k == 0) return 1;
        if(i < 0 || i > k) return 0;
        if(i == 0 || i == k) return 1;
        if(p[k][i] == 0) p[k][i] = pascal(k - 1, i - 1) + pascal(k - 1, i);
        return p[k][i];
    }
};
__________________________________________________________________________________________________
