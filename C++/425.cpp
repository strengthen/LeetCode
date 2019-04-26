__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        unordered_map<string, set<string>> m;
        int n = words[0].size();
        for (string word : words) {
            for (int i = 0; i < n; ++i) {
                string key = word.substr(0, i);
                m[key].insert(word);
            }
        }
        vector<vector<char>> mat(n, vector<char>(n));
        helper(0, n, mat, m, res);
        return res;
    }
      void helper(int i, int n, vector<vector<char>>& mat, unordered_map<string, set<string>>& m, vector<vector<string>>& res) {
            if (i == n) {
                vector<string> out;
                for (int j = 0; j < n; ++j) out.push_back(string(mat[j].begin(), mat[j].end()));
                res.push_back(out);
                return;
            }
            string key = string(mat[i].begin(), mat[i].begin() + i);
        for (string str : m[key]) { 
            mat[i][i] = str[i];
            int j = i + 1;
            for (; j < n; ++j) {
                mat[i][j] = str[j];
                mat[j][i] = str[j];
                if (!m.count(string(mat[j].begin(), mat[j].begin() + i + 1))) break;
            }
            if (j == n) helper(i + 1, n, mat, m, res);
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    struct TrieNode {
        vector<int> indexs;
        vector<TrieNode*> children;
        TrieNode(): children(26, nullptr) {}
    };
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *t = root;
            for (int j = 0; j < words[i].size(); ++j) {
                if (!t->children[words[i][j] - 'a']) {
                    t->children[words[i][j] - 'a'] = new TrieNode();
                }
                t = t->children[words[i][j] - 'a'];
                t->indexs.push_back(i);
            }
        }
        return root;
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<string> out(words[0].size());
        vector<vector<string>> res;
        for (string word : words) {
            out[0] = word;
            helper(words, 1, root, out, res);
        }
        return res;
    }
    void helper(vector<string>& words, int level, TrieNode* root, vector<string>& out, vector<vector<string>>& res) {
        if (level >= words[0].size()) {
            res.push_back(out);
            return;
        }
        string str = "";
        for (int i = 0; i < level; ++i) {
            str += out[i][level];
        }
        TrieNode *t = root;
        for (int i = 0; i < str.size(); ++i) {
            if (!t->children[str[i] - 'a']) return;
            t = t->children[str[i] - 'a'];
        }
        for (int idx : t->indexs) {
            out[level] = words[idx];
            helper(words, level + 1, root, out, res);
        }
    }
};
__________________________________________________________________________________________________
