__________________________________________________________________________________________________
class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> m;
        int sum = helper(root, m);
        if (sum == 0) return m[0] > 1;
        return sum % 2 == 0 && m.count(sum / 2);
    }
    int helper(TreeNode* node, unordered_map<int, int>& m) {
        if (!node) return 0;
        int cur = node->val + helper(node->left, m) + helper(node->right, m);
        ++m[cur];
        return cur;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
