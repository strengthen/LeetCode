__________________________________________________________________________________________________
sample 32 ms submission
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
    TreeNode* increasingBST(TreeNode* root, TreeNode *tail = nullptr) {
        if(root){
            if(root->right){
                root->right = increasingBST(root->right, tail);
            }
            else{
                root->right = tail;
            }
            if(root->left){
                TreeNode *p = root->left;
                root->left = nullptr;
                return increasingBST(p, root);
            }
            else{
                return root;
            }
        }
        else{
            return nullptr;
        }
    }

    TreeNode* increasingBST2(TreeNode* root) {
        if(root){
            root->right = increasingBST(root->right);
            if(root->left){
                TreeNode *p = increasingBST(root->left), *q = p;
                while(q->right){
                    q = q->right;
                }
                q->right = root;
                root->left = nullptr;
                return p;
            }
            else{
                return root;
            }
        }
        else{
            return nullptr;
        }
    }
};

struct InputBooster {
    InputBooster(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
}ib;
__________________________________________________________________________________________________
sample 25312 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution
{
private:
	TreeNode *head, *track;

public:
	Solution()
	{
		head = new TreeNode(0);
		track = head;
	}

	TreeNode *increasingBST(TreeNode *root)
	{
		if(!root) return nullptr;
		increasingBST(root->left);
		track->right = new TreeNode(root->val);
		track = track->right;
		increasingBST(root->right);
		return head->right;
	}
};
__________________________________________________________________________________________________
