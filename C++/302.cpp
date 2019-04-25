__________________________________________________________________________________________________
// Brute force
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = y, right = y, up = x, down = x;
        for (int i = 0; i < image.size(); ++i) {
            for (int j = 0; j < image[i].size(); ++j) {
                if (image[i][j] == '1') {
                    left = min(left, j);
                    right = max(right, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        return (right - left + 1) * (down - up + 1);
    }
};
__________________________________________________________________________________________________
// DFS
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = y, right = y, up = x, down = x;
        dfs(image, x, y, left, right, up, down);
        return (right - left + 1) * (down - up + 1);
    }
    void dfs(vector<vector<char>> &image, int x, int y, int &left, int &right, int &up, int &down) {
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != '1') return;
        left = min(left, y); 
        right = max(right, y);
        up = min(up, x);
        down = max(down, x);
        image[x][y] = '2';
        dfs(image, x + 1, y, left, right, up, down);
        dfs(image, x - 1, y, left, right, up, down);
        dfs(image, x, y + 1, left, right, up, down);
        dfs(image, x, y - 1, left, right, up, down);
    }
};
__________________________________________________________________________________________________
// Binary Search
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int up = binary_search(image, true, 0, x, 0, n, true);
        int down = binary_search(image, true, x + 1, m, 0, n, false);
        int left = binary_search(image, false, 0, y, up, down, true);
        int right = binary_search(image, false, y + 1, n, up, down, false);
        return (right - left) * (down - up);
    }
    int binary_search(vector<vector<char>> &image, bool h, int i, int j, int low, int high, bool opt) {
        while (i < j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (h ? image[mid][k] : image[k][mid]) == '0') ++k;
            if (k < high == opt) j = mid;
            else i = mid + 1;
        }
        return i;
    }
};