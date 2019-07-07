__________________________________________________________________________________________________
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> roots;

    void dfs(TreeNode *root, bool has_parent, const vector<int> &to_delete) {
        if (root == nullptr)
            return;

        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            dfs(root->left, false, to_delete);
            dfs(root->right, false, to_delete);
            return;
        }

        if (!has_parent)
            roots.push_back(root);

        dfs(root->left, true, to_delete);
        dfs(root->right, true, to_delete);

        if (root->left != nullptr && find(to_delete.begin(), to_delete.end(), root->left->val) != to_delete.end())
            root->left = nullptr;

        if (root->right != nullptr && find(to_delete.begin(), to_delete.end(), root->right->val) != to_delete.end())
            root->right = nullptr;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        roots = {};
        dfs(root, false, to_delete);
        return roots;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
