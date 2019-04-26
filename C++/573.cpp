__________________________________________________________________________________________________
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int res = 0, mxDiff = INT_MIN, idx = 0;
        for (auto nut : nuts) {
            int dist = abs(tree[0] - nut[0]) + abs(tree[1] - nut[1]);
            res += 2 * dist;
            mxDiff = max(mxDiff, dist - abs(squirrel[0] - nut[0]) - abs(squirrel[1] - nut[1]));
        }
        return res - mxDiff;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
