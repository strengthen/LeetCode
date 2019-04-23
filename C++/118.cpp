__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> res;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> cur (i+1, 1);
            for (int j = 1; j < i; j++) {
                //cout << i << ' ' << j << endl;
                cur[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(cur);
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
8544 kb
class Solution {
public:
    vector<vector<int>> generate(int rowIndex) {
        vector<vector<int>> v;
        if(rowIndex==0) return v;
        v.push_back({1});
        if(rowIndex==1) return v;
        v.push_back({1, 1});
        if(rowIndex==2) return v;
        for(int i=2;i<rowIndex;i++){
            vector<int> vp(i+1);
            vp[0]=1; vp[i]=1;
            for(int j=1; j<=(i+1)/2; j++){
                vp[j]=v[i-1][j-1]+v[i-1][j];
                vp[i-j]=vp[j];
            }
            v.push_back(vp);
        }
        return v;
    }   
};
__________________________________________________________________________________________________
