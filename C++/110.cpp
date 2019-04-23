__________________________________________________________________________________________________
12ms
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int optmization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int helper(TreeNode *root) {
        if (!root) return 0;
        
        int l = helper(root->left);
        if (l == -1) return -1;
        int r = helper(root->right);
        if (r == -1) return -1;
        
        if (abs(l - r) > 1) return -1;
        
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }
};
__________________________________________________________________________________________________
16220 kb
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
    bool state = true;
    int helper(TreeNode* root) {
        if(root == NULL) return 0;
        int Left = helper(root->left) + 1;
        int Right = helper(root->right) + 1;
        if(fabs(Left - Right) > 1)  state = false;
        return  fmax(Left, Right);
    }
public:
    bool isBalanced(TreeNode* root) {
        helper(root);
        return state;
    }
};
__________________________________________________________________________________________________
