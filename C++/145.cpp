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
#define pb push_back
class Solution {
public:
    vector<int> ans;
    void solve(TreeNode* root)
    {
        if(root->left!=NULL)
        {
            solve(root->left);
        }
        if(root->right!=NULL)
        {
            solve(root->right);
        }
        ans.pb(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        ans.clear();
        if(root==NULL)
        {
            return ans;
        }
        solve(root);
        
        return ans;
    }
};
__________________________________________________________________________________________________
8536 kb
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> vals;
        if(!root) {
            return vals;
        }
        nodes.push(root);
        
        while(!nodes.empty()) {
            TreeNode* curr = nodes.top();
            nodes.pop();
            if(curr -> left) {
                nodes.push(curr);                
                nodes.push(curr -> left);
                curr -> left = NULL;
            } else if (curr -> right) {
                nodes.push(curr);
                nodes.push(curr -> right);
                curr -> right = NULL;
            } else {
                vals.push_back(curr -> val);
            }
        }
        return vals;
    }
};
__________________________________________________________________________________________________
