__________________________________________________________________________________________________
sample 16 ms submission
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//in order traversal for binary search tree the order of poped is increasing
//this is not a good solution since the tree changed
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		int prev(INT_MAX), min(INT_MAX);
		std::stack<TreeNode *> S;
		S.push(root);
		while (!S.empty()) {
			TreeNode *temp = S.top();
			if (temp->left != NULL) {
				S.push(temp->left);
				temp->left = NULL;
			}
			else {
				S.pop();
				min = std::min(min, std::abs(prev - temp->val));
				prev = temp->val;
				if (temp->right != NULL) S.push(temp->right);
			}
		}
		return min;
	}
};
__________________________________________________________________________________________________
sample 12604 kb submission
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
    int getMinimumDifference(TreeNode* root) {
        int prev(INT_MAX), min(INT_MAX);
        std::stack<TreeNode *> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode *temp = S.top();
            if (temp->left != NULL) {
                S.push(temp->left);
                temp->left = NULL;
            }
            else {
                S.pop();
                min = std::min(min, std::abs(prev - temp->val));
                prev = temp->val;
                if (temp->right != NULL) S.push(temp->right);
            }
        }
        return min;
    }
};
__________________________________________________________________________________________________
