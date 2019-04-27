__________________________________________________________________________________________________
sample 88 ms submission
int mp[505][505], r[505][505], c[505][505];
class Solution {
    int n;
    bool Ok(int v) {
        for (int i = v; i + v - 1 <= n; i++) {
            for (int j = v; j + v - 1 <= n; j++) {
                if (r[i][j + v - 1] - r[i][j - v] == 0
                   && c[i + v - 1][j] - c[i - v][j] == 0) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        n = N;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                mp[i][j] = 0;
                r[i][j] = 0;
                c[i][j] = 0;
            }
        }
        for (int i = 0; i < mines.size(); i++) {
            mp[mines[i][0] + 1][mines[i][1] + 1] = 1;
        }
        for (int i = 1; i <= N; i++) {
            r[i][0] = 0;
            c[0][i] = 0;
            for (int j = 1; j <= N; j++) {
                r[i][j] = r[i][j - 1] + mp[i][j];
                c[j][i] = c[j - 1][i] + mp[j][i];
            }
        }
        int l = 0, h = N, mid;
        while (l < h) {
            mid = (l + h + 1) / 2;
            if (Ok(mid)) l = mid;
            else h = mid - 1;
        }
        return l;
    }
};
__________________________________________________________________________________________________
sample 18956 kb submission
int mp[505][505], r[505][505], c[505][505];
class Solution {
    int n;
    bool Ok(int v) {
        for (int i = v; i + v - 1 <= n; i++) {
            for (int j = v; j + v - 1 <= n; j++) {
                if (r[i][j + v - 1] - r[i][j - v] == 0
                   && c[i + v - 1][j] - c[i - v][j] == 0) {
                    // cout << i << " " << j << endl;
                    // for (int i = 1; i <= n; i++) {
                    //     for (int j = 1; j <= n; j++) {
                    //         cout << r[i][j] << " ";
                    //     }
                    //     cout << endl;
                    // }
                    // for (int i = 1; i <= n; i++) {
                    //     for (int j = 1; j <= n; j++) {
                    //         cout << c[i][j] << " ";
                    //     }
                    //     cout << endl;
                    // }
                    return true;
                }
            }
        }
        return false;
    }
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        n = N;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                mp[i][j] = 0;
                r[i][j] = 0;
                c[i][j] = 0;
            }
        }
        for (int i = 0; i < mines.size(); i++) {
            mp[mines[i][0] + 1][mines[i][1] + 1] = 1;
        }
        for (int i = 1; i <= N; i++) {
            r[i][0] = 0;
            c[0][i] = 0;
            for (int j = 1; j <= N; j++) {
                r[i][j] = r[i][j - 1] + mp[i][j];
                c[j][i] = c[j - 1][i] + mp[j][i];
            }
        }
        int l = 0, h = N, mid;
        while (l < h) {
            mid = (l + h + 1) / 2;
            if (Ok(mid)) l = mid;
            else h = mid - 1;
        }
        return l;
    }
};
__________________________________________________________________________________________________
