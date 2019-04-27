__________________________________________________________________________________________________
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res{NULL, NULL};
        if (!root) return res;
        if (root->val <= V) {
            res = splitBST(root->right, V);
            root->right = res[0];
            res[0] = root;
        } else {
            res = splitBST(root->left, V);
            root->left = res[1];
            res[1] = root;
        }
        return res;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
