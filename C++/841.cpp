__________________________________________________________________________________________________
sample 8 ms submission
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& r) {
        int n = r.size();
        bitset<1000> vis;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            vis.set(cur);
            for(auto v: r[cur]) {
                if(vis.test(v)) continue;
                q.push(v);
            }
        }
        return vis.count() == n;
    }
};
__________________________________________________________________________________________________
sample 10704 kb submission
static const auto s = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> res(rooms.size(), false);
        queue<int>q;
        q.push(0);
        
        while(!q.empty()) {
           int r = q.front();
            q.pop();
            if (res[r] == false) {
                res[r] = true;
                for (int i=0; i<rooms[r].size(); i++) {
                    q.push(rooms[r][i]);
                }
            }
        }
        for (int i=0; i<res.size(); i++) {
            if (res[i] == false)
                return false;
        }
        return true;
    }
};
__________________________________________________________________________________________________
