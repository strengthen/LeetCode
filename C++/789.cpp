__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[0]) + abs(target[1]);
        for (auto ghost : ghosts) {
            int t = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            if (t <= dist) return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 9504 kb submission
const static int _= []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int m_dist = abs(target[0])+abs(target[1]);
        int dist;
        for (auto g:ghosts)
        {
            dist = abs(target[0]-g[0])+abs(target[1]-g[1]);
            if (dist<=m_dist)
                return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
