__________________________________________________________________________________________________
sample 4 ms submission
static int speedup = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

vector<int> t1, t2;


void preOrder(TreeNode* root)
{
	if (root == NULL)
		return;

	preOrder(root->left);

	
	if(root->left == NULL && root->right == NULL)
		t1.push_back(root->val);
	preOrder(root->right);
}

int cnt = 0;

bool preOrder1(TreeNode* root)
{
	if (root == NULL)
		return true;

	if (preOrder1(root->left) == false)
		return false;

	if (root->left == NULL && root->right == NULL)
	{
		if (root->val != t1[cnt])
			return false;
		cnt++;
	}
	if (preOrder1(root->right) == false)
		return false;

	return true;
}

class Solution {
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		cnt = 0;
        t1.clear();
		preOrder(root1);
		return preOrder1(root2);
	}
};
__________________________________________________________________________________________________
sample 13432 kb submission
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
    bool isLeaf(TreeNode* node) {
        return node->left==NULL && node->right==NULL;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if (root1 == NULL || root2 == NULL) {
            return false;
        }
        
        stack<TreeNode*> s1, s2;
        s1.push(root1);
        s2.push(root2);
        
        while (!s1.empty() && !s2.empty()) {
            TreeNode *r1=s1.top(), *r2=s2.top();
            s1.pop();
            if (r1->right!=NULL) {
                s1.push(r1->right);
            }
            if (r1->left!=NULL) {
                s1.push(r1->left);
            }
            s2.pop();
            if (r2->right!=NULL) {
                s2.push(r2->right);
            }
            if (r2->left!=NULL) {
                s2.push(r2->left);
            }
            if (isLeaf(r1) && isLeaf(r2)) {
                if (r1->val != r2->val) {
                    return false;
                }
            }
            if (isLeaf(r1) && !isLeaf(r2)) {
                s1.push(r1);
            }
            if (!isLeaf(r1) && isLeaf(r2)) {
                s2.push(r2);
            }
        }
        return (s1.empty() && s2.empty());
    }
};
__________________________________________________________________________________________________
