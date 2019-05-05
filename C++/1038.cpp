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
    
    TreeNode* bstToGst(TreeNode* root) {
        setSum(root);
        return root;
    }
    
    int setSum(TreeNode* x, int delta = 0) {
        int ret = x->val;
        x->val += delta;
        if (x->right) {
            int right = setSum(x->right, delta);
            ret += right;
            x->val += right;
        }
        if (x->left) ret += setSum(x->left, ret + delta);
        return ret;
    }
};

__________________________________________________________________________________________________

__________________________________________________________________________________________________
