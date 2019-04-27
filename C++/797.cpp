__________________________________________________________________________________________________
sample 72 ms submission
class Solution {
public:
    void rec(int u, vector<vector<int>> &graph, vector<int> &curPath, vector<vector<int>> &ans) {
        if (u == graph.size()-1) {
            ans.push_back(curPath);
            return;
        }
        
        for (int v : graph[u]) {
            curPath.push_back(v);
            rec(v, graph, curPath, ans);
            curPath.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curPath = { 0 };
        rec(0, graph, curPath, ans);
        return ans;
    }
};
__________________________________________________________________________________________________
sample 12564 kb submission
class Solution {
public:
    void do_dfs(int start, int end, 
                vector<vector<int>>& graph,
                vector<bool>& visited,
                vector<int>& tmp_rslt,
                vector<vector<int>>& result) {
        
        if (visited[start]) {
            return;
        }
        
        if (start == end) {
            result.push_back(tmp_rslt);
            return;
        }
        
        visited[start] = 1;
        
        for (auto neigh: graph[start]) {
             tmp_rslt.push_back(neigh);
             do_dfs(neigh, end, graph, visited, tmp_rslt, result);
             tmp_rslt.pop_back();
        }
        
        
        visited[start] = 0;
        return;
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if (!graph.size()) return {};
        int N = graph.size();
        vector<vector<int>> result;
        
        vector<int> tmp_rslt;
        vector<bool> visited(N, 0);
        tmp_rslt.push_back(0);
        do_dfs(0, N-1, graph, visited, tmp_rslt, result);
        
        return result;
        
    }
};
__________________________________________________________________________________________________
