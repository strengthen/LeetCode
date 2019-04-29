__________________________________________________________________________________________________
sample 8 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const int _ = []() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();
class Solution {
public:
    void help(TreeNode* node, int &sum, int cur){
        if(!node){
            return;
        }
        int temp = cur * 2 + node->val;
        help(node->left, sum, temp);
        help(node->right, sum, temp);
        if(!node->left && !node->right){
            sum += temp;
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        help(root, sum, 0);
        return sum;
    }
};
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
class Solution {
public:
    void dfs(TreeNode* root,int sum,int &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans += (sum*2 + root->val);
            return;
        }
        dfs(root->left,sum*2 + root->val,ans);
        dfs(root->right,sum*2 + root->val,ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        dfs(root,0,ans);
        return ans;
    }
};
__________________________________________________________________________________________________
sample 16 ms submission
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
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL)return 0;
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
    
    void helper(TreeNode* root, int cur, int& sum){
        cur = (cur << 1) | root->val;
        if(root->left == NULL && root->right == NULL){
            sum += cur;
            return;
        }
        
        if(root->left){
            helper(root->left, cur, sum);
        }
        if(root->right){
            helper(root->right, cur, sum);
        }
    }
};