__________________________________________________________________________________________________
sample 44 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int ioSync = []() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    return 0;
}();

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		it = 0;
		flatten(root, flatTree);
	}

	/** @return the next smallest number */
	int next() {
		return flatTree[it++];
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return it < flatTree.size();
	}
private:
	vector<int> flatTree;
	int it;
	void flatten(TreeNode *root, vector<int> &flatTree)
	{
		if (!root)
			return;
		if (root->left)
			flatten(root->left, flatTree);
		flatTree.push_back(root->val);
		if (root->right)
			flatten(root->right, flatTree);
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
__________________________________________________________________________________________________
sample 24292 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode* tree;
public:
    BSTIterator(TreeNode* root) {
        tree = root;
    }
    
    /** @return the next smallest number */
    int next() {
        int val(-1);
        while (tree) {
            if (tree->left) {
                TreeNode* next = tree->left;
                while (next->right && next->right != tree) next = next->right;
                
                if (next->right) {
                    next->right = NULL;
                    val = tree->val;
                    tree = tree->right;
                    break;
                }
                else {
                    next->right = tree;
                    tree = tree->left;
                }
            }
            else {
                val = tree->val;
                tree = tree->right;
                break;
            }
        }
        
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return tree != NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
__________________________________________________________________________________________________
