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
    void dfs(TreeNode *cur){
        swap(cur->left, cur->right);
        if(cur->left != nullptr) {
            dfs(cur->left);
        }
        if(cur->right != nullptr) {
            dfs(cur->right);
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) {
            return root;
        }
        dfs(root);
        return root;
    }
};
__________________________________________________________________________________________________
sample 8928 kb submission
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
    TreeNode* invertTree(TreeNode* root) {
       if(root==NULL){
           return NULL;
    }
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        root->left= invertTree(root->left);
        root->right= invertTree(root->right);
        return root;
    }
};
__________________________________________________________________________________________________
