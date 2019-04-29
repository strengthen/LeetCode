__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    typedef pair<int, int> pii;
    vector<int> parent;
    int getParent(int idx) {
        while (parent[idx] != idx)
            idx = parent[idx];
        return idx;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        vector<pii> yx;
        int sx = source[0];
        int sy = source[1];
        int tx = target[0]; 
        int ty = target[1];
        int sz = blocked.size();
        if (sz == 0) return true;
        unordered_set<int> ys;
        for (int i=0; i < sz; ++i) {
            yx.push_back(pii(blocked[i][1], blocked[i][0]));
            ys.insert(blocked[i][1]);
        }
        unordered_set<int>::iterator itr = ys.begin();
        for (; itr != ys.end(); ++itr)
            yx.push_back(pii(*itr, 1000000));
        vector<vector<pair<int, pii>>> stk;
        sort(yx.begin(), yx.end());
        int prevY = -1;
        int idx = 0;
        int sIdx = -1;
        int tIdx = -1;
        for (int i=0; i < yx.size(); ) {
            int y = yx[i].first;
            if ((y-1) >= (prevY+1)) {
                if (sy > prevY && sy < y) {
                    sIdx = idx;
                }
                if (ty > prevY && ty < y) {
                    tIdx = idx;
                }
                stk.push_back(vector<pair<int, pii>>());
                stk.back().push_back(make_pair(idx, pii(0, 1000000)));
                ++idx;
            } 
            stk.push_back(vector<pair<int, pii>>());
            int prevX = -1;
            for (; i < yx.size() && yx[i].first == y; ++i) {
                int x = yx[i].second;
                if ( (x-1) >= (prevX+1)) {
                    int beg = prevX+1;
                    int end = x-1;
                    if (sy == y && sx >= beg && sx <= end) {
                        sIdx = idx;
                    }
                    if (ty == y && tx >= beg && tx <= end) {
                        tIdx = idx;
                    }
                    stk.back().push_back(make_pair(idx, pii(beg, end)));
                    ++idx;
                }
                prevX = x;
            }
            prevY = y;
        }
        if (prevY < (1000000-1)) {
            if(sy > prevY)
                sIdx = idx;
            if (ty > prevY)
                tIdx = idx;
            stk.push_back(vector<pair<int, pii>>());
            stk.back().push_back(make_pair(idx, pii(0, 1000000)));
            ++idx;
        }
        for (int i=0; i < idx; ++i)
            parent.push_back(i);
        for (int i=1; i < stk.size(); ++i) {
            int sz1 = stk[i-1].size();
            int sz2 = stk[i].size();
            int i1 = 0;
            int i2 = 0;
            while (i1 < sz1 && i2 < sz2) {
                int idx1 = stk[i-1][i1].first;
                int beg1 = stk[i-1][i1].second.first;
                int end1 = stk[i-1][i1].second.second;
                int idx2 = stk[i][i2].first;
                int beg2 = stk[i][i2].second.first;
                int end2 = stk[i][i2].second.second;
                int idx2Prev = -1;
                if (i2 > 0)
                    idx2Prev = stk[i][i2-1].first;
                if (max(beg1, beg2) <= min(end1, end2)) {
                    if (idx2Prev > 0 && getParent(idx2Prev) == getParent(idx1))
                        parent[idx2] = getParent(idx1);
                    else
                        parent[getParent(idx1)] = idx2;
                }
                if (end2 == end1) {
                    ++i1;
                    ++i2;
                } else if (end1 < end2)
                    ++i1;
                else
                    ++i2;
            }
        }
        int sParent = getParent(sIdx);
        int tParent = getParent(tIdx);
        return (sParent == tParent);
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<long> visited1, visited2;
        for(auto &blk : blocked) {
            blocks.insert(blk[0] * n + blk[1]);
        }
        return dfs(source, target, source[0], source[1], visited1) && dfs(target, source, target[0], target[1], visited2);
    }
private:
    const long n = 1000000;
    set<long> blocks;
    vector<vector<int>> dire{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上下左右
    bool dfs(vector<int> &source, vector<int> &target, int r, int c, set<long> &visited) {
        if(r == target[0] && c == target[1]) return true;
        int l = blocks.size(), dr = r - source[0], dc = c - source[1];
        if(dr >= l || dr <= -l || dc >= l || dc <= -l) return true;
        for(auto &d : dire) {
            int r1 = r + d[0], c1 = c + d[1];
            if(!in_grid(r1, c1)) continue;
            long key = r1 * n + c1;
            if(visited.find(key) != visited.end()) continue;
            visited.insert(key);
            if(blocks.find(key) != blocks.end()) continue;
            if(dfs(source, target, r1, c1, visited)) return true;
        }
        return false;
    }
    bool in_grid(int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
    unordered_map<int, unordered_set<int>> blocked_map;
    unordered_map<int, unordered_set<int>> seen;
    
    vector<int> bound;
    
    int max_rc;
    
    void dfs(int r, int c) {
        seen[r].insert(c);
        
        bound[0] = min(bound[0], r);
        bound[2] = max(bound[2], r);
        
        bound[1] = min(bound[1], c);
        bound[3] = max(bound[3], c);
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;
                
                if (blocked_map[r+i].count(c+j) && !seen[r+i].count(c+j)) {
                    dfs(r+i, c+j);
                }
            }
        }
    }
    
    bool dfs4_inside_helper(int r, int c, unordered_map<int, unordered_set<int>> &visited) { 
        if (visited[r].count(c)) {
            return true;
        }
        
        visited[r].insert(c);
        
        if (blocked_map[r].count(c))
            return true;
        
        if (r < bound[0] || r > bound[2] || c < bound[1] || c > bound[3])
            return false;
        
        if (r - 1 >= 0 && dfs4_inside_helper(r-1, c, visited) == false)
            return false;
        
        if (r + 1 < max_rc && dfs4_inside_helper(r+1, c, visited) == false)
            return false;
        
        if (c - 1 >= 0 && dfs4_inside_helper(r, c-1, visited) == false)
            return false;
        
        if (c + 1 < max_rc && dfs4_inside_helper(r, c+1, visited) == false)
            return false;
        
        return true;
    }
    
    bool dfs4_inside(int r, int c) {
        unordered_map<int, unordered_set<int>> visited;
        
        return dfs4_inside_helper(r, c, visited);
    }
    
    bool connect(vector<int>& source, vector<int>& target) {        
        bool s_ret = dfs4_inside(source[0], source[1]);
        
        bool t_ret = dfs4_inside(target[0], target[1]);
        
        if (s_ret ^ t_ret)
            return false;
        
        return true;
    }
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {   
        max_rc = pow(10, 6);  
        
        for (auto v : blocked) {
            blocked_map[v[0]].insert(v[1]);
        }
        
        for (auto v : blocked) {
            if (!seen[v[0]].count(v[1])) {
                bound = {v[0], v[1], v[0], v[1]};
                
                dfs(v[0], v[1]);
                
                if (connect(source, target) == false) {
                    return false;
                }
            }
        }
        
        return true;
    }
};