__________________________________________________________________________________________________
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        if (root->left || root->right) res.push_back(root->val);
        leftBoundary(root->left, res);
        leaves(root, res);
        rightBoundary(root->right, res);
        return res;
    }
    void leftBoundary(TreeNode* node, vector<int>& res) {
        if (!node || (!node->left && !node->right)) return;
        res.push_back(node->val);
        if (!node->left) leftBoundary(node->right, res);
        else leftBoundary(node->left, res);
    }
    void rightBoundary(TreeNode* node, vector<int>& res) {
        if (!node || (!node->left && !node->right)) return;
        if (!node->right) rightBoundary(node->left, res);
        else rightBoundary(node->right, res);
        res.push_back(node->val);
    }
    void leaves(TreeNode* node, vector<int>& res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.push_back(node->val);
        }
        leaves(node->left, res);
        leaves(node->right, res);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res{root->val};
        helper(root->left, true, false, res);
        helper(root->right, false, true, res);
        return res;
    }
    void helper(TreeNode* node, bool leftbd, bool rightbd, vector<int>& res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.push_back(node->val);
            return;
        }
        if (leftbd) res.push_back(node->val);
        helper(node->left, leftbd && node->left, rightbd && !node->right, res);
        helper(node->right, leftbd && !node->left, rightbd && node->right, res);
        if (rightbd) res.push_back(node->val);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res, right;
        TreeNode *l = root->left, *r = root->right, *p = root;
        if (root->left || root->right) res.push_back(root->val);
        while (l && (l->left || l->right)) {
            res.push_back(l->val);
            if (l->left) l = l->left;
            else l = l->right;
        }
        stack<TreeNode*> st;
        while (p || !st.empty()) {
            if (p) {
                st.push(p);
                if (!p->left && !p->right) res.push_back(p->val);
                p = p->left;
            } else {
                p = st.top(); st.pop();
                p = p->right;
            }
        }
        while (r && (r->left || r->right)) {
            right.push_back(r->val);
            if (r->right) r = r->right;
            else r = r->left;
        }
        res.insert(res.end(), right.rbegin(), right.rend());
        return res;
    }
};