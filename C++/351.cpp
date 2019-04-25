__________________________________________________________________________________________________
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int res = 0;
        vector<bool> visited(10, false);
        vector<vector<int>> jumps(10, vector<int>(10, 0));
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
        res += helper(1, 1, 0, m, n, jumps, visited) * 4;
        res += helper(2, 1, 0, m, n, jumps, visited) * 4;
        res += helper(5, 1, 0, m, n, jumps, visited);
        return res;
    }
    int helper(int num, int len, int res, int m, int n, vector<vector<int>> &jumps, vector<bool> &visited) {
        if (len >= m) ++res;
        ++len;
        if (len > n) return res;
        visited[num] = true;
        for (int next = 1; next <= 9; ++next) {
            int jump = jumps[num][next];
            if (!visited[next] && (jump == 0 || visited[jump])) {
                res = helper(next, len, res, m, n, jumps, visited);
            }
        }
        visited[num] = false;
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        return count(m, n, 0, 1, 1);
    }
    int count(int m, int n, int used, int i1, int j1) {
        int res = m <= 0;
        if (!n) return 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int I = i1 + i, J = j1 + j, used2 = used | (1 << (i * 3 + j));
                if (used2 > used && (I % 2 || J % 2 || used2 & (1 << (I / 2 * 3 + J / 2)))) {
                    res += count(m - 1, n - 1, used2, i, j);
                }
            }
        }
        return res;
    }
};
__________________________________________________________________________________________________
