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
    pair<int, TreeNode*> helper(TreeNode* root)
    {
        if(!root)
            return {0,NULL};
        pair<int,TreeNode*> l=helper(root->left);
        pair<int,TreeNode*> r=helper(root->right);
        int d1=l.first;
        int d2=r.first;
        return {1+max(d1,d2),d1==d2?root:d1>d2?l.second:r.second};
        
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).second;
        
    }
};
__________________________________________________________________________________________________
sample 14932 kb submission
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
    int depth(TreeNode * root) {
        if(root == NULL) {
            return 0;
        }
        return max(depth(root->left), depth(root->right)) + 1;
    }
    bool solve(TreeNode* root, int dep, int curdep, TreeNode **ans) {
        if(root == NULL) {
            return false;
        }
        bool ok = 0;
        if(curdep == dep) {
            ok = 1;
        }
        bool lok = solve(root->left, dep, curdep + 1, ans);
        bool rok = solve(root->right, dep, curdep + 1, ans);
        if((lok && rok) || ok) {
            *ans = root;
        }
        return (lok | ok | rok);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int dep = depth(root);
        TreeNode** ans;
        ans = &root;
        solve(root, dep, 1, ans);
        return *ans; 
    }
};
__________________________________________________________________________________________________
