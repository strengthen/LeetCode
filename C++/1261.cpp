__________________________________________________________________________________________________
sample 20 ms submission
/*
Problem Statement: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
*/

static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class FindElements {
private:
	unordered_set<int> seen;
public:
    FindElements(TreeNode* root) {
		fix(0, root);
    }

	void fix(int val, TreeNode* node) {
		seen.insert(val);
		if (node->left)
			fix(2 * val + 1, node->left);
		if (node->right)
			fix(2 * val + 2, node->right);
	}
    
    bool find(int target) {
		return seen.find(target) != seen.end();
    }
};
__________________________________________________________________________________________________
sample 24 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> set;
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    void recover(TreeNode* root, int x){
        if(root==NULL) return;
        root->val = x;
        set.emplace(x);
        if(root->left) recover(root->left,  2 * x + 1);
        
        if(root->right) recover(root->right,  2 *x + 2);
        
        
    }
    
    bool find(int target) {
        return set.count(target);
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
__________________________________________________________________________________________________
