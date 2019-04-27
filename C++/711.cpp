__________________________________________________________________________________________________

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int row_num = grid.size(), col_num = grid[0].size();
        set<vector<pair<int, int>>> islands;
        for (int r = 0; r < row_num; ++r) {
            for (int c = 0; c < col_num; ++c) {
                if (grid[r][c] == 1) {
                    vector<pair<int, int>> island;
                    DFS(grid, r, c, r, c, island);
                    islands.insert(normalize(island));
                }
            }
        }
        return islands.size();
    }
private:
    void DFS(vector<vector<int>> &grid, int r0, int c0, int r, int c, vector<pair<int, int>> &island) {
        int row_num = grid.size(), col_num = grid[0].size();
        if (r < 0 || r >= row_num || c < 0 || c >= col_num || grid[r][c] <= 0) {
            return;
        }
        grid[r][c] = -1;
        island.push_back(make_pair(r - r0, c - c0));
        for (int d = 0; d < 4; ++d) {
            DFS(grid, r0, c0, r + delta[d][0], c + delta[d][1], island);
        }
    }
    vector<pair<int, int>> normalize(vector<pair<int, int>> &a) {
        vector<vector<pair<int, int>>> ret(8, vector<pair<int, int>>());
        for (auto &p : a) {
            int x = p.first, y = p.second;
            ret[0].push_back(make_pair(x, y));
            ret[1].push_back(make_pair(x, -y));
            ret[2].push_back(make_pair(-x, y));
            ret[3].push_back(make_pair(-x, -y));
            ret[4].push_back(make_pair(y, x));
            ret[5].push_back(make_pair(y, -x));
            ret[6].push_back(make_pair(-y, x));
            ret[7].push_back(make_pair(-y, -x));
        }
        for (int i = 0; i < 8; ++i) {
            sort(ret[i].begin(), ret[i].end());
            int r_offset = 0 - ret[i][0].first, c_offset = 0 - ret[i][0].second;
            for (int j = 0; j < ret[i].size(); ++j) {
                ret[i][j].first += r_offset;
                ret[i][j].second += c_offset;
            }
        }
        sort(ret.begin(), ret.end());
        return ret[0];
    } 
    int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

--------------------- 
作者：魔豆Magicbean 
来源：CSDN 
原文：https://blog.csdn.net/magicbean2/article/details/79282937 
版权声明：本文为博主原创文章，转载请附上博文链接！
__________________________________________________________________________________________________

__________________________________________________________________________________________________
