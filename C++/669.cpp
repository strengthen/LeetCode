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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL) return NULL;
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        if(root->val < L) return root->right;
        if(root->val > R) return root->left;
        return root;
    }
};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
sample 13116 kb submission
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
    //  0
    // 1 2
    TreeNode* helper(TreeNode* root, int L, int R) {
        if(root) {
            root->left = helper(root->left, L, R);
            root->right = helper(root->right, L, R);
            int val = root->val;
            if(val < L || R < val) {
                if(val < L) return root->right;
                if(R < val) return root->left;
            }
            return root;
        } else {
            return nullptr;
        }
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return helper(root, L, R);
    }
};
__________________________________________________________________________________________________
