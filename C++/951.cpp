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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 and !root2) return true;
        if (!root1 or !root2) return false;
        if (root1->val != root2->val) return false;
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) or
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
__________________________________________________________________________________________________
sample 11860 kb submission
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (root1 && root2) {
            if (root1->val != root2->val) {
                return false;
            }
            return flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right) || 
                flipEquiv(root1->right, root2->right) && flipEquiv(root1->left, root2->left);
        }
        return false;
    }
};
__________________________________________________________________________________________________
