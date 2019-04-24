__________________________________________________________________________________________________
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        return minTotalDistance(rows) + minTotalDistance(cols);
    }
    int minTotalDistance(vector<int> v) {
        int res = 0;
        sort(v.begin(), v.end());
        int i = 0, j = v.size() - 1;
        while (i < j) res += v[j--] - v[i++];
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        sort(cols.begin(), cols.end());
        int res = 0, i = 0, j = rows.size() - 1;
        while (i < j) res += rows[j] - rows[i] + cols[j--] - cols[i++];
        return res;
    }
};
__________________________________________________________________________________________________
