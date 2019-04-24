__________________________________________________________________________________________________
class Solution {
public:
    int res = 0;
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return res;
        if (isUnival(root, root->val)) ++res;
        countUnivalSubtrees(root->left);
        countUnivalSubtrees(root->right);
        return res;
    }
    bool isUnival(TreeNode *root, int val) {
        if (!root) return true;
        return root->val == val && isUnival(root->left, val) && isUnival(root->right, val);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        isUnival(root, -1, res);
        return res;
    }
    bool isUnival(TreeNode* root, int val, int& res) {
        if (!root) return true;
        if (!isUnival(root->left, root->val, res) | !isUnival(root->right, root->val, res)) {
            return false;
        }
        ++res;
        return root->val == val;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        bool b = true;
        return isUnival(root, b);
    }
    int isUnival(TreeNode *root, bool &b) {
        if (!root) return 0;
        bool l = true, r = true;
        int res = isUnival(root->left, l) + isUnival(root->right, r);
        b = l && r && (root->left ? root->val == root->left->val : true) && (root->right ? root->val == root->right->val : true);
        return res + b;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        set<TreeNode*> res;
        if (!root) return 0;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *head = root;
        while (!s.empty()) {
            TreeNode *t = s.top(); 
            if ((!t->left && !t->right) || t->left == head || t->right == head) {
                if (!t->left && !t->right) {
                    res.insert(t);
                } else if (!t->left && res.find(t->right) != res.end() && t->right->val == t->val) {
                    res.insert(t);
                } else if (!t->right && res.find(t->left) != res.end() && t->left->val == t->val) {
                    res.insert(t);
                } else if (t->left && t->right && res.find(t->left) != res.end() && res.find(t->right) != res.end() && t->left->val == t->val && t->right->val == t->val) {
                    res.insert(t);
                }
                s.pop();
                head = t;
            } else {
                if (t->right) s.push(t->right);
                if (t->left) s.push(t->left);
            }
        }
        return res.size();
    }
};