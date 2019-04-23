__________________________________________________________________________________________________
8ms
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
    vector<vector<int>> ret;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        preOrder(root, 0, true);
        return ret;
    }
    
    void preOrder(TreeNode* root, int depth, bool shouldLeftToRight) {
        if (root == NULL) {
            return;
        }
        
        if (ret.size() == depth) {
            ret.push_back(vector<int>());
        }
        
        if (shouldLeftToRight) {
            ret[depth].push_back(root->val);
            preOrder(root->left, depth+1, false);
            preOrder(root->right, depth+1, false);
        } else {
            ret[depth].insert(ret[depth].begin() ,root->val);
            preOrder(root->left, depth+1, true);
            preOrder(root->right, depth+1, true);
        }
    }
};
__________________________________________________________________________________________________
13252 kb
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
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> res;
    if (!root) return res;

    vector<int> new_lvl;
    deque<TreeNode*> d_lvl;
    int n;
    TreeNode* curr;
    bool backwards = false;
    
    d_lvl.push_back(root);

    while (!d_lvl.empty()) {
        new_lvl.clear();
        n = d_lvl.size();

        for (size_t i = 0; i < n; ++i) {
            if (backwards) {
                curr = d_lvl.back();
                d_lvl.pop_back();
                new_lvl.push_back(curr->val);
                if (curr->right) d_lvl.push_front(curr->right);
                if (curr->left) d_lvl.push_front(curr->left);
            } else {
                curr = d_lvl.front();
                d_lvl.pop_front();
                new_lvl.push_back(curr->val);
                if (curr->left) d_lvl.push_back(curr->left);
                if (curr->right) d_lvl.push_back(curr->right);
            }
        }
        res.push_back(new_lvl);
        backwards = !backwards;
    }

    return res;
}
};
__________________________________________________________________________________________________
