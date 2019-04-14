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
    int maxAncestorDiff(TreeNode* root, int mx = 0, int mn = 1000) {
        return root ? max(max(mx - root->val, root->val - mn), max(
            maxAncestorDiff(root->left, max(mx, root->val), min(mn, root->val)),
            maxAncestorDiff(root->right, max(mx, root->val), min(mn, root->val)))) : 0;
    }
};