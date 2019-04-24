__________________________________________________________________________________________________
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double d = numeric_limits<double>::max();
        int res = 0;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            if (d >= abs(target - p->val)) {
                d = abs(target - p->val);
                res = p->val;
            }
            p = p->right;
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        while (root) {
            if (abs(res - target) >= abs(root->val - target)) {
                res = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int a = root->val;
        TreeNode *t = target < a ? root->left : root->right;
        if (!t) return a;
        int b = closestValue(t, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        if (target < root->val && root->left) {
            int l = closestValue(root->left, target);
            if (abs(res - target) >= abs(l - target)) res = l;
        } else if (target > root->val && root->right) {
            int r = closestValue(root->right, target);
            if (abs(res - target) >= abs(r - target)) res = r;
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double diff = numeric_limits<double>::max();
        int res = 0;
        helper(root, target, diff, res);
        return res;
    }
    void helper(TreeNode *root, double target, double &diff, int &res) {
        if (!root) return;
        if (diff >= abs(root->val - target)) {
            diff = abs(root->val - target);
            res = root->val;
        }
        helper(root->left, target, diff, res);
        helper(root->right, target, diff, res);
    }
};