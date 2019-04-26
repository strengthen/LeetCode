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
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    }
    int Max = 0;
    int diameterOfBinaryTree(TreeNode*root) {
        if(root == nullptr) return 0;
        helper(root);
        return Max-1;
    }
private:
    int helper(TreeNode*&root){
         if (root == nullptr) return 0;
        int left = 1 + helper(root->left);
        int right = 1 + helper(root->right);
        if (right + left -1 > Max) Max = left + right -1;
        return max(left, right);
    }
};
__________________________________________________________________________________________________
sample 19848 kb submission
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
    int dia(TreeNode * root, int * ans){
          if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        int lefty = dia(root->left,ans);
        int righty = dia(root->right,ans);
        if(*ans<lefty+righty){
            *ans=lefty+righty;
        }
        int max=lefty;
        if(max<righty)
            max=righty;
        return max+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        dia(root,&ans); 
        return ans;
    }
};
__________________________________________________________________________________________________
