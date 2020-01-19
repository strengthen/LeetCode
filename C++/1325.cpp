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
    int tar;
    bool empty = false;
    void rec(TreeNode* par, TreeNode* node, int which) {
        if(node == NULL) {
            return;
        }
        rec(node, node -> left, 0);
        rec(node, node -> right, 1);
        
        if(node -> left == NULL and node -> right == NULL and node -> val == tar) {
            if(which == -1) {
                empty = true;
                return;
            }
            if(which == 0) {
                par -> left = NULL;
            }
            if(which == 1) {
                par -> right = NULL;
            }
        }
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        tar = target;
        rec(NULL, root, -1);
        if(empty) {
            return NULL;
        }
        return root;
    }
};
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root->left) root->left = removeLeafNodes(root->left, target);
        if (root->right) root->right = removeLeafNodes(root->right, target);
        return root->left == root->right && root->val == target ? NULL : root;
    }
};
__________________________________________________________________________________________________
