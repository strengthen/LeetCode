__________________________________________________________________________________________________
sample 4 ms submission
static const auto io_sync_off = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

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
	int result = 0;
	void solve(TreeNode *node, int mi, int ma) {
		if(!node) return;
		int a = abs(node->val - mi);
		int b = abs(node->val - ma);
		if(result < a) result = a;
		if(result < b) result = b;
		if(node->val < mi) mi = node->val;
		if(node->val > ma) ma = node->val;
		solve(node->left, mi, ma);
		solve(node->right, mi, ma);
	}
	int maxAncestorDiff(TreeNode* root) {
		solve(root->left, root->val, root->val);
		solve(root->right, root->val, root->val);
		return result;
	}
};
__________________________________________________________________________________________________
sample 8 ms submission
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
	int maxAncestorDiffHelp(TreeNode *root, int minum, int maxium) {
		if (root == NULL)return 0;
		int newmin = minum, newmax = maxium;
		if (root->val > maxium)newmax = root->val;
		if (root->val < minum)newmin = root->val;
		int left = maxAncestorDiffHelp(root->left, newmin, newmax);
		int right= maxAncestorDiffHelp(root->right, newmin, newmax);
		int diffrence = max(abs(root->val - minum), abs(root->val - maxium));
		return max(right, max(left, diffrence));
	}
	int maxAncestorDiff(TreeNode* root) {
		return maxAncestorDiffHelp(root, root->val, root->val);
	}
};
__________________________________________________________________________________________________
sample 12 ms submission
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
    int maxAncestorDiff(TreeNode* r, int mn = 100000, int mx = 0) {
        if (r == nullptr)
            return mx - mn;
        mx = max(mx, r->val);
        mn = min(mn, r->val);
        return max(maxAncestorDiff(r->left, mn, mx), maxAncestorDiff(r->right, mn, mx));
    }
};