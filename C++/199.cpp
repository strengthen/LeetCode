__________________________________________________________________________________________________
sample 4 ms submission
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        
        util(root, res, 1);
        return res;
    }
    
    void util(TreeNode *root, vector<int> &res, int level) {
        if (root == NULL) return ;
        
        if (level == res.size() + 1) res.push_back(root->val);
        util(root->right, res, level + 1);
        util(root->left, res, level + 1);
    }
};
__________________________________________________________________________________________________
sample 9272 kb submission
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
    vector<int> rightSideView(TreeNode* root) {
        int height = maxDepth(root);
        vector<int> view(height);
        dfs(root, 0, view);
        return view;
    }
    
private:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    void dfs(TreeNode* root, int level, vector<int>& view) {
        if (root == nullptr) {
            return;
        }
        view[level] = root->val;
        dfs(root->left, level + 1, view);
        dfs(root->right, level + 1, view);
    }
};
__________________________________________________________________________________________________
