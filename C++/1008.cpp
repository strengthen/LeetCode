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
#include <climits>
#include <cassert>
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        assert(preorder.size() > 0 && preorder.size() <= 100 && "preorder size must be in [1, 100]");
        std::vector<TreeNode*> stack;
        TreeNode* root = new TreeNode(preorder[0]);
        stack.push_back(root);
        for(auto it = preorder.cbegin() + 1; it != preorder.cend(); ++it) {
            TreeNode* cur = new TreeNode(*it);
            TreeNode* last = nullptr;
            if (stack.back()->val > *it) {
                stack.back()->left = cur;
                stack.push_back(cur);
            } else {
                while (stack.size() && stack.back()->val < *it) {
                    last = stack.back();
                    stack.pop_back();
                }
                last->right = cur;
                stack.push_back(cur);
            }
        }
        return root;
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
    void Insert(TreeNode *&root, int val) {
        if(root == NULL) {
            root = new TreeNode(val);
            return;
        }
        
        if(val > root->val) Insert(root->right, val);
        else Insert(root->left, val);
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = NULL;
        for(int i = 0; i < preorder.size() ; i++) {
            Insert(root, preorder[i]);
        }
        return root;
    }
};
__________________________________________________________________________________________________
