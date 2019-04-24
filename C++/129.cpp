__________________________________________________________________________________________________
4ms
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
    int sumNumbers(TreeNode* root) {
        int pre = 0, ret = 0;
        helper(root, pre, ret);
        return ret;
    }
    
    void helper(TreeNode* root, int pre, int& ret){
        if(root){
            pre = pre * 10 + root->val;
            if(!root->left && !root->right) ret += pre;
            if(root->left) helper(root->left, pre, ret);
            if(root->right) helper(root->right, pre, ret);
        }
    }
};
__________________________________________________________________________________________________
12068 kb
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
    long long  ss(TreeNode* root, int ps){
        if (!root){return 0;}
        if (!root->left && !root->right){
            return ps*10 + root->val;
        }
        long long s1 = ss(root->left, ps*10 + root->val);
        long long s2 = ss(root->right, ps*10 + root->val);
        
        return s1+s2;
    }
    
    int sumNumbers(TreeNode* root) {
        return ss(root, 0);
    }
};
__________________________________________________________________________________________________
