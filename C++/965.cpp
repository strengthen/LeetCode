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
    bool isUnivalTree(TreeNode * root,int value){
        if(root==NULL) return true;
        
        if(root->val != value) return false;
        
        return isUnivalTree(root->left, value) && isUnivalTree(root->right, value);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        
        int value=root->val;
        
        return isUnivalTree(root, value);
        
    }
};
__________________________________________________________________________________________________
sample 10568 kb submission
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
    bool recurse( TreeNode* root, int val )
    {
      if( !root ) return true;
      if( root->val != val ) return false;
      return recurse( root->left, val ) && recurse( root->right, val );
    }
    bool isUnivalTree(TreeNode* root) {
      if( !root ) return true;
      return recurse( root, root->val );
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
