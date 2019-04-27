__________________________________________________________________________________________________
sample 100 ms submission
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) 
            return 0;
        connect.push_back(root);
        helper(root, root, 0);
        int ret = 0;
        for(auto r : connect) 
        {
            diameter(r, ret);
        }
        return ret;
    }
private:
    vector<TreeNode*> connect;
    void helper(TreeNode* node, TreeNode* parent, int mode) {
        if(node == NULL) return;
        if(node->val == parent->val) {
            helper(node->left, node, 1);
            helper(node->right, node, 2);
        }
        else {
            connect.push_back(node);
            helper(node, node, 0);
            if(mode == 1) parent->left = NULL; 
            else parent->right = NULL;
        }
    }
    int diameter(TreeNode* node, int& edge) 
    {
        if(node == NULL) 
            return 0;
        int left = diameter(node->left, edge);
        int right = diameter(node->right, edge);
        edge = max(edge, left + right);
        return max(left, right) + 1;
    }
};
__________________________________________________________________________________________________
sample 49596 kb submission
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
    int max = 0;
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        helper(root);
        return max;
    }


    int helper(TreeNode* node) {
        int left = 0;
        int right = 0;
        // longest arrow to left
        if (node->left) {
            if (node->left->val == node->val)
                left = helper(node->left) + 1;
            // lonest arrow from current root found, consider left child as new root
            else helper(node->left);
        }

        // longest arrow to right
        if (node->right) {
            if (node->right->val == node->val)
                right = helper(node->right) + 1;
            // lonest arrow from current root found, consider right child as new root
            else
                helper(node->right);
        }

        // record the UNIVALUE PATH len with current node as root
        if (left + right > max) max = left + right;

        // return the longer arrow of from this node, used in calculation of its parent's arrow
        return left > right ? left : right;
    }
};
__________________________________________________________________________________________________
