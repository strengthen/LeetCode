__________________________________________________________________________________________________
sample 36 ms submission
[[maybe_unused]] static const auto _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {


    int squareSum(
        std::vector<std::vector<int>> const& prefixSum, size_t x1, size_t y1, size_t x2, size_t y2
    )
    {
        return prefixSum[x2][y2] - prefixSum[x1][y2] - prefixSum[x2][y1] + prefixSum[x1][y1];
    }
public:
    int maxSideLength(std::vector<std::vector<int>> const& mat, int threshold)
    {
        size_t const m = mat.size();
        size_t const n = mat[0].size();
        std::vector<std::vector<int>> prefixSum(m + 1, std::vector<int>(n + 1,0));

        for (size_t i = 1; i <= m; i++)
        {
            for (size_t j = 1; j <= n; j++)
            {
                prefixSum[i][j] = prefixSum[i - 1][j] +
                    prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int res = 0;

        for (size_t i = 0; i <= m; i++)
        {
            for (size_t j = 0; j <= n; j++)
            {
                int len = res + 1;

                while (
                    i + len <= m &&
                    j + len <= n && 
                    squareSum(prefixSum, i, j, i + len, j + len) <= threshold
                    ) 
                {
                    res = len++;

                }
            }
        }

        return res;
    }
};
__________________________________________________________________________________________________
sample 40 ms submission
[[maybe_unused]] static const auto _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {


    int squareSum(
        std::vector<std::vector<int>> const& prefixSum, size_t x1, size_t y1, size_t x2, size_t y2
    )
    {
        return prefixSum[x2][y2] - prefixSum[x1][y2] - prefixSum[x2][y1] + prefixSum[x1][y1];
    }
public:
    int maxSideLength(std::vector<std::vector<int>> const& mat, int threshold)
    {
        size_t const m = mat.size();
        size_t const n = mat[0].size();
        std::vector<std::vector<int>> prefixSum(m + 1, std::vector<int>(n + 1,0));

        for (size_t i = 1; i <= m; i++)
        {
            for (size_t j = 1; j <= n; j++)
            {
                prefixSum[i][j] = prefixSum[i - 1][j] +
                    prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int res = 0;

        for (size_t i = 0; i <= m; i++)
        {
            for (size_t j = 0; j <= n; j++)
            {
                int len = res + 1;

                while (
                    i + len <= m &&
                    j + len <= n && 
                    squareSum(prefixSum, i, j, i + len, j + len) <= threshold
                    ) 
                {
                    res = len++;

                }
            }
        }

        return res;
    }
};
__________________________________________________________________________________________________
