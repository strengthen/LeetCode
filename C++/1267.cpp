__________________________________________________________________________________________________
sample 20 ms submission
[[maybe_unused]] static const auto _ = []() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
    int countServers(std::vector<std::vector<int>> const & grid) {
        if (grid.empty())
            return 0;
        size_t const m = grid.size();
        size_t const n = grid[0].size();
        int res = 0;
        std::vector<int> sl(m, 0);
        std::vector<int> sc(n, 0);

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++)
            {
                auto const value = grid[i][j];
                sl[i] += value;
                sc[j] += value;
                res += value;
            }
        }
        for (size_t i = 0; i < m; i++)
            for (size_t j = 0; j < n; j++)
                if (sl[i] * sc[j] * grid[i][j] == 1)
                    res--;
        return res;
    }
};
__________________________________________________________________________________________________
sample 24 ms submission

// Observation

// For each server, the row or the column must have another server except the current one.
// We can simply keep a count of servers in each row and column and use this information to get the result while traversing the grid.

// Solution

// Complexity
// Here m is the number of rows and n is the number of columns.
// Space: O(m+n).This can be reduced to min(m,n).
// Time: O(m*n).
    
    
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        int dim1 = grid.size();
        int dim2 = grid[0].size();
        vector<int> rows(dim1, 0);
        vector<int> cols(dim2, 0);
        for(int i=0; i<dim1; ++i) for(int j=0; j<dim2; ++j){
            if(grid[i][j]) ++rows[i], ++cols[j];
        }
        for(int i=0; i<dim1; ++i) for(int j=0; j<dim2; ++j){
            if(grid[i][j] && (rows[i]>1 || cols[j]>1))
                ++res;
        }
        return res;
    }
};

__________________________________________________________________________________________________
