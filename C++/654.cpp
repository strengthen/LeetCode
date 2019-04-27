__________________________________________________________________________________________________
sample 64 ms submission
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
		stack<TreeNode *> values;
		vector<TreeNode *> nodes(nums.size());
		int index = 0, maximum = INT_MIN;
		for (int i = 0; i < nums.size(); ++i) {
			TreeNode *node = nullptr;
			nodes[i] = new TreeNode(nums[i]);
			while (values.size() && nums[i] > values.top()->val) {
				node = values.top();
				values.pop();
			}
			nodes[i]->left = node;
			values.push(nodes[i]);
			if (nums[i] > maximum) {
				maximum = nums[i];
				index = i;
			}
		}
		while (values.size())
			values.pop();
		for (int i = nums.size() - 1; i >= 0; --i) {
			TreeNode *node = nullptr;
			while (values.size() && nums[i] > values.top()->val) {
				node = values.top();
				values.pop();
			}
			nodes[i]->right = node;
			values.push(nodes[i]);
		}
		return nodes[index];
	}
};
__________________________________________________________________________________________________
sample 26312 kb submission
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
TreeNode* constructMaximumBinaryTree(vector<int> & nums) {
	if (nums.size() == 0) return NULL;

	TreeNode * root = new TreeNode(nums[0]);
	TreeNode * cr = root;
	TreeNode * parentcr = NULL;

	for (int i = 1; i < nums.size(); ++i) {
		int e = nums[i];

		TreeNode * n = new TreeNode(e);
		if (e > root->val) {
			n->left = root;
			root = n;
			parentcr = NULL;
		}
		else {
			if (e < cr->val) {
				parentcr = cr;
				cr->right = n;
			}
			else if (parentcr != NULL && parentcr->val > e) {
				n->left = parentcr->right;
				parentcr->right = n;
			}
			else {
				TreeNode * biggestNode = root;
				while (biggestNode->right->val > e) biggestNode = biggestNode->right;

				n->left = biggestNode->right;
				biggestNode->right = n;
				parentcr = biggestNode;
			}
				
		}
		cr = n;
	}

	return root;
}
};

static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
__________________________________________________________________________________________________
