__________________________________________________________________________________________________
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    void dfs(TreeNode *root, int &res) {
        if (!root) return;
        int d = countBFS(root, INT_MIN, INT_MAX);
        if (d != -1) {
            res = max(res, d);
            return;
        }
        dfs(root->left, res);
        dfs(root->right, res);
    }
    int countBFS(TreeNode *root, int mn, int mx) {
        if (!root) return 0;
        if (root->val <= mn || root->val >= mx) return -1;
        int left = countBFS(root->left, mn, root->val);
        if (left == -1) return -1;
        int right = countBFS(root->right, root->val, mx);
        if (right == -1) return -1;
        return left + right + 1;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        if (isValid(root, INT_MIN, INT_MAX)) return count(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
    bool isValid(TreeNode* root, int mn, int mx) {
        if (!root) return true;
        if (root->val <= mn || root->val >= mx) return false;
        return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
    }
    int count(TreeNode* root) {
        if (!root) return 0;
        return count(root->left) + count(root->right) + 1;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0, mn = INT_MIN, mx = INT_MAX;
        isValidBST(root, mn, mx, res);
        return res;
    }
    void isValidBST(TreeNode* root, int& mn, int& mx, int& res) {
        if (!root) return;
        int left_cnt = 0, right_cnt = 0, left_mn = INT_MIN;
        int right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
        isValidBST(root->left, left_mn, left_mx, left_cnt);
        isValidBST(root->right, right_mn, right_mx, right_cnt);
        if ((!root->left || root->val > left_mx) && (!root->right || root->val < right_mn)) {
            res = left_cnt + right_cnt + 1;
            mn = root->left ? left_mn : root->val;
            mx = root->right ? right_mx : root->val;
        } else {
            res = max(left_cnt, right_cnt);    
        }
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        vector<int> res = helper(root);
        return res[2];
    }
    vector<int> helper(TreeNode* node) {
        if (!node) return {INT_MAX, INT_MIN, 0};
        vector<int> left = helper(node->left), right = helper(node->right);
        if (node->val > left[1] && node->val < right[0]) {
            return {min(node->val, left[0]), max(node->val, right[1]), left[2] + right[2] + 1};
        } else {
            return {INT_MIN, INT_MAX, max(left[2], right[2])};
        }
    }
};