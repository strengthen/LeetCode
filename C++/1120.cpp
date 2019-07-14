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
    double ret = 0;
    pair<int, int> dfs(TreeNode* root) {
        int cal = 1;
        int sum = root->val;
        if (root->left) {
            pair<int, int> test = dfs(root->left);
            cal += test.first;
            sum += test.second;
        }
        if (root->right) {
            pair<int, int> test = dfs(root->right);
            cal += test.first;
            sum += test.second;
        }
        if (ret < (double)sum / cal) {
            ret = (double)sum / cal;
        }
        return make_pair(cal, sum);
    }
    double maximumAverageSubtree(TreeNode* root) {
        ret = 0;
        dfs(root);
        return ret;
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
    double ans;
    map<TreeNode*, double> size, sum;
    void dfs(TreeNode *x)
    {
        if (!x) return;
        size[x] = 1;
        sum[x] = x->val;
        if (x->left)
        {
            dfs(x->left);
            size[x] += size[x->left];
            sum[x] += sum[x->left];
        }
        if (x->right)
        {
            dfs(x->right);
            size[x] += size[x->right];
            sum[x] += sum[x->right];
        }
        ans = max(ans, sum[x]/size[x]);
    }
    double maximumAverageSubtree(TreeNode* root) {
        size.clear();
        sum.clear();
        ans = 0;
        dfs(root);
        return ans;
    }
};
__________________________________________________________________________________________________
