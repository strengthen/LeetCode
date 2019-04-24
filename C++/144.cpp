__________________________________________________________________________________________________
4ms
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> path;
        TreeNode* current = root;
        while(current || !path.empty()){
            while(current){
                result.push_back(current->val);
                path.push(current);
                current = current->left;
            }
            current = path.top();
            path.pop();
            current = current->right;
        }
        return result;
    }
};
__________________________________________________________________________________________________
8672 kb
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        while (root != NULL) {
            result.push_back(root->val);
            if (root->left == NULL) {
                root = root->right;
                continue;
            }
            TreeNode* tp = root->left;
            while (tp->right != NULL) {
                tp = tp->right;
            }
            tp->right = root->right;
            TreeNode* tmp = root->left;
            root->left = NULL;
            root = tmp;
        }
        return result;
    }
};
__________________________________________________________________________________________________
