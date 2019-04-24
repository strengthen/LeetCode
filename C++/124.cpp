__________________________________________________________________________________________________
24ms
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
    private:
    int maxpath = -2e9;
public:
    int maxdepth(TreeNode* root) {
        if (!root) return 0;
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        int pth = left + right + root->val;
        if (pth > maxpath) {
            maxpath = pth;
        }
        return std::max(std::max(left, right) + root->val, 0);
    }
    int maxPathSum(TreeNode* root) {
        maxdepth(root);
        return maxpath;
    }
};
static int x =[](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}()
__________________________________________________________________________________________________
23364 kb
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
    int recurse(TreeNode* root, int *max) {
        if (root == NULL) {
            return 0;
        }
        
        int leftSum = recurse(root->left, max);
        int rightSum = recurse(root->right, max);
        int maxSum = (leftSum > rightSum ? leftSum : rightSum);
        
        int val = root->val;
        if (leftSum > 0) val += leftSum;
        if (rightSum > 0) val += rightSum;
        if (val > *max) *max = val;
        
        return (maxSum > 0 ? maxSum + root->val : root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        
        recurse(root,  &max);
        return max;
    }
};
__________________________________________________________________________________________________
