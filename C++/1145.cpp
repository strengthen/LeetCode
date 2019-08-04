__________________________________________________________________________________________________
Runtime: 0 ms
Memory Usage: 11.8 MB
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* xN = findNode(root, x);
        int left = 0, right = 0;
        nodeCount(xN->left, left);
        nodeCount(xN->right, right);
        //cout<<left<<' '<<right;
        return max(left, max(right, n-left-right-1))>n/2;
    }
    
    TreeNode* findNode(TreeNode* root, int x){
        if (!root) return root;
        if (root->val == x) return root;
        TreeNode* res = findNode(root->left, x);
        if (res) return res;
        res = findNode(root->right, x);
        return res;
    }
    
    void nodeCount(TreeNode* root, int& res){
        if (!root) return;
        res++;
        nodeCount(root->left, res);
        nodeCount(root->right, res);
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
