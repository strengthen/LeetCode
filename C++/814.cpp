__________________________________________________________________________________________________
sample 4 ms submission
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
    TreeNode* pruneTree(TreeNode* root) {
        return pruneR(root);
    }
    TreeNode* pruneR(TreeNode *x) {
        if (!x) return 0;
        x->left = pruneR(x->left);
        x->right = pruneR(x->right);
        if (!x->left && !x->right && x->val == 0) return 0;
        return x;
    }
};
__________________________________________________________________________________________________
sample 9624 kb submission
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
    TreeNode* pruneTree(TreeNode* root) {
      if( !root ) return nullptr;
      root->left = pruneTree( root->left );
      root->right = pruneTree( root->right );
        
      if( root->val == 0 && !root->left && !root->right )
        return nullptr;
      return root;
    }
};

static int x = []() {
	// toggle off cout & cin, instead, use printf & scanf
	std::ios::sync_with_stdio(false);
	// untie cin & cout
	cin.tie(NULL);
	return 0;
}();
__________________________________________________________________________________________________
