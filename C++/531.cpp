__________________________________________________________________________________________________
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty() || picture[0].empty()) return 0;
        int m = picture.size(), n = picture[0].size(), res = 0;
        vector<int> rowCnt(m, 0), colCnt(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++rowCnt[i];
                    ++colCnt[j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    if (rowCnt[i] == 1 && colCnt[j] == 1) {
                        ++res;
                    }
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
