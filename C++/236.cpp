__________________________________________________________________________________________________
sample 12 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Solution final {
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) noexcept {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        if (p == q) return p;
        root->left = lowestCommonAncestor(root->left, p, q);
        root->right = lowestCommonAncestor(root->right, p, q);
        return root->left && root->right 
            ? root 
            : root->left ? root->left : root->right;
    }
};

static const auto speedup = []() noexcept {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
sample 13184 kb submission
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p || root==q) return root;
        root->left = lowestCommonAncestor(root->left,p,q);
        root->right= lowestCommonAncestor(root->right,p,q);
        if(root->left && root->right) return root;
        else if(root->left) return root->left;
        else if(root->right) return root->right;
        else return NULL;
    }
};
__________________________________________________________________________________________________
