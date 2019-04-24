__________________________________________________________________________________________________
8ms
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (!wordBreakTest(s, wordDict)) { return {}; }
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        int maxLen = INT_MIN, minLen = INT_MAX;
        for (string word : wordDict) {
            int n = word.size();
            maxLen = max(maxLen, n);
            minLen = min(minLen, n);
        }
        vector<string> res;
        string cur;
        int n = s.size();
        if (n == 0) { return {}; }
        vector<vector<string>> dp(n);
        for (int i = 0; i < n; ++i) {
            if (m.count(s.substr(0, i + 1))) { dp[i].push_back(s.substr(0, i + 1)); }
            for (int j = minLen; j <= maxLen; ++j) {
                int cur = i - j;
                if (cur < 0) { break; }
                string tmp = s.substr(cur + 1, j);
                if (dp[cur].size() && m.count(tmp)) {
                    for (string item : dp[cur]) {
                        dp[i].push_back(item + " " + tmp);
                    }
                }
            }
        }
        return dp[n - 1];
    }
    
    bool wordBreakTest(string s, vector<string>& wordDict) {
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        int maxLen = INT_MIN, minLen = INT_MAX;
        for (string word : wordDict) {
            int n = word.size();
            maxLen = max(maxLen, n);
            minLen = min(minLen, n);
        }
        int n = s.size();
        if (n == 0) { return true; }
        bool dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = m.count(s.substr(0, i + 1)) ? true : false;
            if (dp[i]) { continue; }
            for (int j = minLen; j <= maxLen; ++j) {
                int cur = i - j;
                if (cur < 0) { break; }
                dp[i] = dp[cur] && m.count(s.substr(cur + 1, j));
                if (dp[i]) { break; }
            }
        }
        return dp[n - 1];
    }
};
__________________________________________________________________________________________________
10068 kb
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> graph = generateGraph(wordDict, s);
        vector<string> paths = generatePaths(graph, s);
        
        return paths;
    }
    
private:
    vector<vector<int>> generateGraph(vector<string>& wordDict, string &s) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        vector<vector<int>> graph(s.size(), vector<int>());
        for (int i = s.size() - 1; i >= 0; --i) {
            string t = s.substr(i, s.size() - i);
            for (; !t.empty(); t.pop_back()) {
                if ((i + t.size() == s.size() || !graph[i+t.size()].empty()) && dict.find(t) != dict.end()) {
                    graph[i].push_back(t.size());
                }
            }
        }
        return graph;
    }
    
    vector<string> generatePaths(vector<vector<int>> &graph, string &s) {
        string path;
        vector<string> ret;
        subGeneartePaths(graph, s, 0, path, ret);
        
        return ret;
    }
    
    void subGeneartePaths(vector<vector<int>> &graph, string &s, int idx, string& path, vector<string> &res) {
        if (idx == s.size()) {
            res.push_back(path);
            return;
        }
        
        if (idx != 0) {
            path.push_back(' ');
        }
        int pathSize = path.size();
        for (int i = 0; i < graph[idx].size(); ++i) {
            path.insert(path.end(), s.begin() + idx, s.begin() + idx + graph[idx][i]);
            subGeneartePaths(graph, s, idx + graph[idx][i], path, res);
            path.resize(pathSize);
        }
        if (idx != 0) {
            path.pop_back();
        }
    }
};
__________________________________________________________________________________________________
