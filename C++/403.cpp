__________________________________________________________________________________________________
sample 4 ms submission
auto gucciGang = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class Solution {
public:
	bool canCross(vector<int>& stones) {
		for (size_t i = 0; ++i<stones.size();){ if (stones[i] - stones[i - 1] > i) { return false; } }
		priority_queue<pair<size_t, int>> q;
		q.push({ 0, 0 });
		for (; !q.empty();) {
			auto t = q.top(); q.pop();
			if (t.first + 1 == stones.size()) { return true; }
			for (size_t i = t.first; ++i < stones.size();) {
				int k = stones[i] - stones[t.first];
				if (k > t.second + 1){
					//if (k > stones[t.first] + 8) { return false; }
					break;
				}
				else if (k >= t.second - 1) { q.push({ i, k }); }
			}
		}
		return false;
	}
};
__________________________________________________________________________________________________
sample 10224 kb submission
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n < 2 || stones[1] != 1) return false;
        if (n == 2) return true;
    	if (stones[n-1] == n-1) return true;
    	if (stones[n-1] > (n-1)*n/2) return false;
        
        unordered_set<int> setStones(stones.begin(), stones.end());
        
        return dfs(setStones, 1, 1, stones.back());
    }
    
    bool dfs(unordered_set<int>& stones, int steps, int pos, int target) {
        if (steps <= 0 || stones.find(pos) == stones.end()) return false;
        if (pos == target) return true;
        
        return dfs(stones, steps + 1, pos + steps + 1, target) 
            || dfs(stones, steps, pos + steps, target)
            || dfs(stones, steps - 1, pos + steps - 1, target);
    }
};
__________________________________________________________________________________________________
