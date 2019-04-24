__________________________________________________________________________________________________
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s;
        bool b = false;
        TreeNode *t = root;
        while (t || !s.empty()) {
            while (t) {
                s.push(t);
                t = t->left;
            }
            t = s.top(); s.pop();
            if (b) return t;
            if (t == p) b = true;
            t = t->right;
        }
        return NULL;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!p) return NULL;
        inorder(root, p);
        return suc;
    }
    void inorder(TreeNode *root, TreeNode *p) {
        if (!root) return;
        inorder(root->left, p);
        if (pre == p) suc = root;
        pre = root;
        inorder(root->right, p);
    }
private:
    TreeNode *pre = NULL, *suc = NULL;
};
__________________________________________________________________________________________________
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *res = NULL;
        while (root) {
            if (root->val > p->val) {
                res = root;
                root = root->left;
            } else root = root->right;
        }
        return res;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return NULL;
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode *left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};