__________________________________________________________________________________________________
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*> back;
        TreeNode *kNode = find(root, k, back);
        queue<TreeNode*> q{{kNode}};
        unordered_set<TreeNode*> visited{{kNode}};
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (!t->left && !t->right) return t->val;
            if (t->left && !visited.count(t->left)) {
                visited.insert(t->left);
                q.push(t->left);
            }
            if (t->right && !visited.count(t->right)) {
                visited.insert(t->right);
                q.push(t->right);
            }
            if (back.count(t) && !visited.count(back[t])) {
                visited.insert(back[t]);
                q.push(back[t]);
            }
        }
        return -1;
    }
    TreeNode* find(TreeNode* node, int k, unordered_map<TreeNode*, TreeNode*>& back) {
        if (node->val == k) return node;
        if (node->left) {
            back[node->left] = node;
            TreeNode *left = find(node->left, k, back);
            if (left) return left;
        }
        if (node->right) {
            back[node->right] = node;
            TreeNode *right = find(node->right, k, back);
            if (right) return right;
        }
        return NULL;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        int res = -1, mn = INT_MAX;
        unordered_map<int, int> m;
        m[k] = 0;
        find(root, k, m);
        helper(root, -1, m, mn, res);
        return res;
    }
    int find(TreeNode* node, int k, unordered_map<int, int>& m) {
        if (!node) return -1;
        if (node->val == k) return 1;
        int r = find(node->left, k, m);
        if (r != -1) {
            m[node->val] = r; 
            return r + 1;
        }
        r = find(node->right, k, m);
        if (r != -1) {
            m[node->val] = r;
            return r + 1;
        }
        return -1;
    }
    void helper(TreeNode* node, int cur, unordered_map<int, int>& m, int& mn, int& res) {
        if (!node) return;
        if (m.count(node->val)) cur = m[node->val];
        if (!node->left && !node->right) {
            if (mn > cur) {
                mn = cur; 
                res = node->val;
            }
        }
        helper(node->left, cur + 1, m, mn, res);
        helper(node->right, cur + 1, m, mn, res);
    }
};
__________________________________________________________________________________________________
