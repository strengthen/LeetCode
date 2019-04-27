__________________________________________________________________________________________________
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; ++i) {
            int l = K, r = K, n = heights.size();
            while (l > 0 && heights[l] >= heights[l - 1]) --l;
            while (l < K && heights[l] == heights[l + 1]) ++l;
            while (r < n - 1 && heights[r] >= heights[r + 1]) ++r;
            while (r > K && heights[r] == heights[r - 1]) --r;
            (heights[l] < heights[K]) ? ++heights[l] : ++heights[r];
        }
        return heights;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
