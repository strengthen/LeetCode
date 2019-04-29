__________________________________________________________________________________________________
sample 96 ms submission
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        int maxDist = max(r0, R - r0 - 1) + max(c0, C - c0 - 1);
        
        result.reserve(R * C);
        result.push_back({r0, c0});
        
        for (int d = 1; d <= maxDist; ++d) {
            int r = r0 + d;
            int c = c0;
            
            // 1. Decrease r until it becomes r0 - d 
            // 1.1 Increase c until it become c0 + d
            while (c < c0 + d) {
                addToResult(result, R, C, r, c);
                --r;
                ++c;
            }
            
            // 1.2 Decrease c until it become c0
            while (c > c0) {
                addToResult(result, R, C, r, c);
                --r;
                --c;
            }
            
            // 2 Increase r until it become r0 + d
            // 2.1 Decrease c until it become c0 - d
            while (c > c0 - d) {
                addToResult(result, R, C, r, c);
                ++r;
                --c;
            }
            
            // 2.2 Increase c until it become c0
            while (c < c0) {
                addToResult(result, R, C, r, c);
                ++r;
                ++c;
            }
        }
        
        return result;
    }
    
private:
    void addToResult(vector<vector<int>>& result, int R, int C, int r, int c) {
        // Skip out of bound r, c
        if (r >= 0 && r < R && c >= 0 && c < C) {
            result.push_back({r, c});    
        }
        
        return;
    }
};
__________________________________________________________________________________________________
sample 100 ms submission
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res = { {r0, c0} };
        
        for(int d = 1; d < R + C; d++)
            for(int x = d; x >= -d; x--){
                insert(res, R, C, r0 + x, c0 + d - abs(x));
                
                if(d != abs(x))
                    insert(res, R, C, r0 + x, c0 + abs(x) - d);
            }
        return res;
    }
    
    void insert(vector<vector<int>> &res, int R, int C, int r, int c){
        if(r >= 0 && c >= 0 && r < R && c < C) res.push_back({r, c});
    }
};
__________________________________________________________________________________________________
sample 104 ms submission
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>> m;
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                int d=abs(r-r0)+abs(c-c0);
                m[d].push_back({r,c});
            }
        }
        for(auto a:m){
            for(auto v:a.second){
                res.push_back({v.first, v.second});
            }
        }
            
        return res;
    }
};