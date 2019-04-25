__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, vector<vector<int>>& res) {
        if (!root) return -1;
        int depth = 1 + max(helper(root->left, res), helper(root->right, res));
        if (depth >= res.size()) res.resize(depth + 1);
        res[depth].push_back(root->val);
        return depth;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root) {
            vector<int> leaves;
            root = remove(root, leaves);
            res.push_back(leaves);
        }
        return res;
    }
    TreeNode* remove(TreeNode* node, vector<int>& leaves) {
        if (!node) return NULL;
        if (!node->left && !node->right) {
            leaves.push_back(node->val);
            return NULL;
        }
        node->left = remove(node->left, leaves);
        node->right = remove(node->right, leaves);
        return node;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> left = findLeaves(root->left), right = findLeaves(root->right);
        vector<vector<int>> res = (left.size() >= right.size()) ? left : right;
        vector<vector<int>> t = (left.size() >= right.size()) ? right : left;
        for (int i = 0; i < t.size(); ++i) {
            res[i].insert(res[i].begin(), t[i].begin(), t[i].end());
        }
        res.push_back({root->val});
        return res;
    }
};