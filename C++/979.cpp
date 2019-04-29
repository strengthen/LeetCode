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
    int distributeCoins(TreeNode* root){
        if(root==NULL)return 0;
        int ret = 0;
        if(root->left!=NULL){
        ret+=distributeCoins(root->left);
        ret+=abs(root->left->val-1);
        root->val+=(root->left->val-1);
        }    
        if(root->right!=NULL){
            ret+=distributeCoins(root->right);
        ret+=abs(root->right->val-1);
        root->val+=(root->right->val-1);
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 13732 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans=0;
int solve(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=solve(root->left);
   
    int r=solve(root->right);
    
    ans+=abs(l+r+root->val-1);
        return l+r+root->val-1;
    
    return l+r;
}
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        ans=0;
        int s=solve(root);
        return ans;
    }
};
__________________________________________________________________________________________________
