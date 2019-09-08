__________________________________________________________________________________________________
sample 456 ms submission
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& A, vector<vector<int>>& queries) {
        int n = A.size();
        vector < vector < int > > near;
        near.resize(6);
        for(int c = 1;c < 4;++c) {
            int lastSeen = 1 << 22;
            int col = c;
            near[c].resize(n + 5);
            for(int i = 0;i < n;++i) {
                if(A[i] == col) {
                    lastSeen = 0;
                } else {
                    if(i) {
                        lastSeen = near[c][i - 1] + 1;
                    }
                }
                near[c][i] = lastSeen;
            }
            
            lastSeen = 1 << 22;
            for(int i = n - 1;i > -1;--i) {
                if(A[i] == col) {
                    lastSeen = 0;
                } else {
                    if(i < n - 1) {
                        lastSeen = min(near[c][i + 1] + 1, near[c][i]);
                    } else {
                        lastSeen = near[c][i];
                    }
                }
                near[c][i] = lastSeen;
            }
        }
        
        vector < int > ans;
        int q = queries.size();
        for(int i = 0;i < q;++i) {
            int idx = queries[i][0];
            int c = queries[i][1];
            int ret = near[c][idx];
            if(ret > (1 << 21)) {
                ans.push_back(-1);
            } else {
                ans.push_back(ret);
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        
        for(int i=0;i<colors.size();i++)
            mp[colors[i]].push_back(i);
        
        vector<int> res;
        for(auto x:queries)
        {
            int idx = x[0];
            int col = x[1];
            if(mp.find(col)==mp.end())
            {
                res.push_back(-1);
                continue;
            }
            
            int pos = lower_bound(mp[col].begin(),mp[col].end(), idx) - mp[col].begin();
            if(pos==0)
                res.push_back(abs(idx-mp[col][pos]));
            else if(pos==mp[col].size())
                res.push_back(abs(idx-mp[col][pos-1]));
            else
                res.push_back(min(abs(idx - mp[col][pos]), abs(idx - mp[col][pos-1])));
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
