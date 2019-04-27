__________________________________________________________________________________________________
sample 76 ms submission
static int fast = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); return 0;}();

class UF
{
public:
    UF(int n) :
        parents(n)
    {
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }
    }
    
    int find(int x)
    {
        if (x != parents[x])
            parents[x] = find(parents[x]);
        
        return parents[x];
    }
    
    bool unionFind(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        
        if (px == py)
            return false;
        
        parents[py] = px;
        return true;
    }

private:
    vector<int> parents;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        vector<vector<string>> out;
        unordered_map<string, std::pair<string, int>> accountsMap;
        
        int index = 0;
        for (auto &v : accounts)
        {
            string &name = v[0];
            
            for (int i = 1; i < v.size(); ++i)
            {
                if (accountsMap.find(v[i]) == accountsMap.end())
                    accountsMap[v[i]] = std::pair<string, int>(name, index++);
            }
        }
        
        UF uf(accountsMap.size());
        
        for (auto &v : accounts)
        {
            int indexRef = accountsMap[v[1]].second;
            
            for (int i = 2; i < v.size(); ++i)
                uf.unionFind(indexRef, accountsMap[v[i]].second);
        }
        
        unordered_map<int, int> lastIndex;
        
        for (auto it = accountsMap.begin(); it != accountsMap.end(); ++it)
        {
            int pi = uf.find(it->second.second);
            
            if (lastIndex.find(pi) == lastIndex.end())
            {
                out.push_back(vector<string>({it->second.first}));
                lastIndex[pi] = out.size() - 1;
            }
            
            int outIndex = lastIndex[pi];
            out[outIndex].push_back(it->first);
        }
        
        for (auto &v: out)
            std::sort(v.begin(), v.end());
        
        return out;
    }
};
__________________________________________________________________________________________________
sample 32028 kb submission
class Solution {
public:
	int find(vector<int>& parent, int k) {
		if (parent[k] != k) parent[k] = find(parent, parent[k]);
		return parent[k];
	}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		vector<vector<string>> ret;
		int n=accounts.size();
		vector<int> parent(n);
		unordered_map<string, int> ids;
		for (int i=0; i <n; ++i) parent[i] = i;
		for (int i=0; i < n; ++i) {
			for (int j=1; j < accounts[i].size(); ++j) {
				if (!ids.count(accounts[i][j])) ids[accounts[i][j]] = i;
				else parent[find(parent, ids[accounts[i][j]])] = find(parent, i);
			}
		}
		unordered_map<int, set<string>> all;
		for (int i=0; i <n ;++i) all[find(parent, i)].insert(accounts[i].begin()+1, accounts[i].end());
		for (auto& p : all) {
			ret.resize(ret.size()+1);
			ret.back().push_back(accounts[p.first][0]);
			ret.back().insert(ret.back().end(), p.second.begin(), p.second.end());
		}
		return ret;
    }
};
__________________________________________________________________________________________________
