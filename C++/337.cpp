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
 
       int rob(TreeNode* root) 
       {
        int pre, cur;
        helper(root, pre, cur);
        return cur;
    }
    
private:
    void helper(TreeNode* root, int &pre, int &cur) {
        if (!root) {
            pre = cur = 0;
            return;
        }
        int pl, cl, pr, cr;
        helper(root -> left, pl, cl);
        helper(root -> right, pr, cr);
        int temp = max(pr + pl + root -> val, cl + cr);
        pre = cl + cr;
        cur = temp;
    }

};
__________________________________________________________________________________________________
sample 20472 kb submission
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
    
    void helper(TreeNode* root, int &v0, int &v1) {
        if (root == NULL) {
            v0 = 0;
            v1 = 0;
            return;
        }
        
        int l0;
        int l1;
        helper(root->left, l0, l1);
        
        int r0;
        int r1;
        helper(root->right, r0, r1);
        
        v1 = l0 + r0;
        v0 = max(root->val + l1 + r1, v1);
        return;
    }
    
    int rob(TreeNode* root) {
        
        int v0;
        int v1;
        helper(root, v0, v1);        
        
        return v0;
    }
};
__________________________________________________________________________________________________
