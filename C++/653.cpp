__________________________________________________________________________________________________
sample 28 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return k == 0;
        //TreeNode* node = root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            int val = k - node -> val;
            TreeNode* tmp = root;
            if (val != node -> val) { 
                while (tmp) {
                    if (tmp -> val == val) return true;
                    else if (tmp -> val < val) tmp = tmp -> right;
                    else tmp = tmp -> left;
                }
            }
            if (node -> left) q.push(node -> left);
            if (node -> right) q.push(node -> right);
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 25148 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

auto io = []() {
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);
	std::cout.tie(0);
	return 0;
}();

class Solution {
	std::vector<int> v;
public:
	void build_list(TreeNode* root) {
		if (root == nullptr) return;
		build_list(root->left);
		v.push_back(root->val);
		build_list(root->right);
	}

	bool findTarget(TreeNode* root, int k) {
		build_list(root);

		int l{}, r{v.size() - 1};

		while (l < r) {
			int sum_ = v[l] + v[r];
			if (sum_ == k) return true;
			if (sum_ > k) {
				--r;
			} else {
				++l;
			}
		}
		return false;
	}
};
__________________________________________________________________________________________________
