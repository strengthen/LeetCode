__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        const size_t N = books.size();
        vector<int> d(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            int local_min = numeric_limits<int>::max();
            int cur_width = 0;
            int cur_height = 0;
            for (int j = i; j >= 1; --j) {
                cur_width += books[j-1][0];
                if (cur_width > shelf_width) break;
                cur_height = max(cur_height, books[j-1][1]);
                local_min = min(local_min, d[j-1] + cur_height);
            }
            d[i] = local_min;
        }
        return d[N];
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> f(n + 1, 1e9);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int sum_width = books[i][0];
            int max_height = books[i][1];
            for (int j = i + 1; j <= n && sum_width <= shelf_width; j++) {
                f[j] = min(f[j], f[i] + max_height);
                if (j == n) break;
                max_height = max(max_height, books[j][1]);
                sum_width += books[j][0];
            }
        }
        return f[n];
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        struct Node {
            int used_width, min_height;
            Node() {}
            Node(int w, int h): used_width(w), min_height(h) {}
        };
        // dp[i]: books[0, i] min height
        vector<Node> dp;
        dp.resize(books.size());
        dp[0] = Node(books[0][0], books[0][1]);
        for (int i = 1; i < books.size(); i++) {
            // books [j, i]
            int width = books[i][0];
            int height = books[i][1];
            dp[i] = Node(width, height + dp[i - 1].min_height);
            for (int j = i - 1; j >= 0; j--) {
                if (width + books[j][0] > shelf_width) break;
                width += books[j][0];
                height = max(height, books[j][1]);
                int cur_height = height + (j == 0 ? 0 : dp[j - 1].min_height);
                if (cur_height < dp[i].min_height) {
                    dp[i].used_width = width;
                    dp[i].min_height = cur_height;
                }
            }
        }
        return dp[books.size() - 1].min_height;
    }
};