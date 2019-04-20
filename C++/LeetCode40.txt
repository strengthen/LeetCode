__________________________________________________________________________________________________
8ms
#define debug(args...)
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    
vvi ccs2(vi &v, int t, map<int,vvi> &m, int st){
	
	vvi pans;
	for(int i = st;i<v.size();i++){
		if(v[i]==t){
			pans.pb({v[i]});
			break;
		}
	}
	
	for(int i = st;i<v.size();i++){
		if(t-v[i]<=0)continue;
		if(i>st && v[i] == v[i-1])continue;
		vvi cans = ccs2(v, t - v[i], m, i+1);
		for(int j = 0;j<cans.size();j++){
			vi t = cans[j];
			t.pb(v[i]);
			pans.pb(t);
		}
	}
	debug("Building t:", t, " with:", pans);
	return pans;
}

vvi cs2(vi &v, int t){
	sort(v.begin(), v.end(), greater<int>());
	map<int,vvi> m;
	int st = 0;
	vvi ans = ccs2(v,t,m, st);
	return ans;
}
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        return cs2(candidates, target);    
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> list;
        helper(candidates, 0, target, list, res);
        return res;
    }
    
    void helper(vector<int>& candidates, int start, int target, vector<int>& list, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(list);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i-1]) continue;
            list.push_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i], list, res);
            list.pop_back();
        }
    }
};
__________________________________________________________________________________________________
16ms
class Solution {
public:
    typedef vector<vector<int>> Combination;
    
    void showSet(auto &candidates, vector<int> &sets) {
        for (const auto &set : sets)
            cout << candidates[set] << " ";
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<Combination> dp(target + 1);
        
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= candidates.size(); ++i) {
            for (int j = target; j >= candidates[i - 1]; --j) {
                if (j == candidates[i - 1] && (i < 2 || candidates[i - 1] != candidates[i - 2])) {
                    // cout << "insert " << candidates[i - 1] << " to " << j << endl;
                    dp[j].push_back({i - 1});
                    continue;
                }

                for (auto comb : dp[j - candidates[i - 1]]) {
                    if (i >= 2 && candidates[i - 2] == candidates[i - 1] && comb.back() != i - 2)
                        continue;

                    comb.push_back(i - 1);
                    // cout << "insert set "; 
                    // showSet(candidates, comb);
                    // cout << " to " << j << endl;
                    dp[j].push_back(comb);
                }
            }
        }
        
        vector<vector<int>> rets;
        for (const auto &comb : dp[target]) {
            vector<int> ret;
            for (const auto &i : comb)
                ret.push_back(candidates[i]);
            rets.push_back(ret);
        }
        return rets;
    }
    
    vector<vector<int>> methodI(vector<int> &candidates, int target) {
        int n = candidates.size();
        vector<vector<Combination>> dp(n + 1, vector<Combination>(target + 1));
        
        sort(candidates.begin(), candidates.end());
        for (int i = 1; i <= candidates.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                
                if (j < candidates[i - 1])
                    continue;

                if (j == candidates[i - 1] && (i < 2 || candidates[i - 1] != candidates[i - 2])) {
                    // cout << "insert " << candidates[i - 1] << " to " << j << endl;
                    dp[i][j].push_back({i - 1});
                    continue;
                }

                for (auto comb : dp[i - 1][j - candidates[i - 1]]) {
                    if (i >= 2 && candidates[i - 2] == candidates[i - 1] && comb.back() != i - 2)
                        continue;

                    comb.push_back(i - 1);
                    dp[i][j].push_back(comb);
                }
            }
        }
        
        vector<vector<int>> rets;
        for (const auto &comb : dp[n][target]) {
            vector<int> ret;
            for (const auto &i : comb)
                ret.push_back(candidates[i]);
            rets.push_back(ret);
        }
        return rets;
    }
};
__________________________________________________________________________________________________

static int x = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
    
private:

    void solve(vector<int>& candidates, int target, int idx, vector<int>& current, vector<vector<int>>& results) {
        
        if(target < 0) return;
        
        if(target == 0) {
            results.push_back(current);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i-1] == candidates[i]) continue;
            current.push_back(candidates[i]);
            solve(candidates, target-candidates[i],i+1,current, results);
            current.resize(current.size() - 1); // shirnk the vector
        }
        
    }   
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> results;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, current, results);
        
        return results;
        
    }
};
__________________________________________________________________________________________________
9324 kb
#include <algorithm>

static const auto fastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
} ();

class Solution {
protected:
    vector<vector<int>> r;
    vector<int> c;
    
    void f_rec(vector<int>& v, int index, int c_index, int t){
        if(t == 0){
            return ;
        }
        int q = 0;
        c.resize(c_index+1);
        for(int i=index;i<v.size();i++){
            const int t2 = t-v[i];
            c[c_index] = v[i];
            if(t2 == 0){
                r.push_back(vector<int>(c));
                break;
            }
            if(t2 < 0){
                break;
            }
            f_rec(v,i+1,c_index+1,t2);
            while(i+1 < v.size() && v[i+1] == v[i]){
                i++;
            }
        }
        c.resize(c_index);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        r.resize(0);
        c.resize(0);
        f_rec(candidates,0,0,target);
        return r;
    }
};
__________________________________________________________________________________________________