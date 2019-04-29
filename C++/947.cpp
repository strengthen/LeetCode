__________________________________________________________________________________________________
sample 24 ms submission
static const auto ___ = [](){
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class _disjoint_set {
	vector<int> _parent;
	int _size;

public:
	_disjoint_set(int n) {
		_parent.reserve(n);
		for (int i = 0; i < n; i++)
			_parent.push_back(i);
		_size = n;
	}

	int find(int i) {
		if (i != _parent[i])
			_parent[i] = _parent[find(_parent[i])];
		return _parent[i];
	}

	void join(int i, int j) {
		int ri = find(i), rj = find(j);
		if (ri != rj) {
			_parent[ri] = rj;
			_size--;
		}
	}

	inline int size() { return _size; }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        _disjoint_set ds(stones.size());
        vector<pair<int, int>> vp;
        for (int i = 0; i < stones.size(); i++)
            vp.emplace_back(stones[i][0], i);
        sort(vp.begin(), vp.end());
        for (int i = 1; i < vp.size(); i++)
            if (vp[i].first == vp[i - 1].first)
                ds.join(vp[i].second, vp[i - 1].second);
        vp.clear();
        for (int i = 0; i < stones.size(); i++)
            vp.emplace_back(stones[i][1], i);
        sort(vp.begin(), vp.end());
        for (int i = 1; i < vp.size(); i++)
            if (vp[i].first == vp[i - 1].first)
                ds.join(vp[i].second, vp[i - 1].second);
        return stones.size() - ds.size();
    }
};
__________________________________________________________________________________________________
sample 13488 kb submission
class Solution {
public:
    int cnt = 0;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        cnt = n;
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    uni(parent, i, j);
                }
            }
        }
        return (n - cnt);
    }
    
    void uni(vector<int>& parent, int x, int y) {
        x = find(parent, x);
        y = find(parent, y);
        if (x == y) return;
        parent[x] = y;
        cnt--;
    }
    
    int find(vector<int>& parent, int x) {
        if (x != parent[x]) parent[x] = find(parent, parent[x]);
        return parent[x];
    }
};
__________________________________________________________________________________________________
