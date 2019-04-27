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
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL || root->left==NULL && root->right==NULL){return -1;}
        
        int left=root->left->val==root->val?findSecondMinimumValue(root->left):root->left->val;
        int right=root->right->val==root->val?findSecondMinimumValue(root->right):root->right->val;
        
        if(left==-1 && right==-1){return -1;}
        if(left==-1){return right;}
        if(right==-1){return left;}
        return min(right,left);
    }
};
__________________________________________________________________________________________________
sample 8464 kb submission
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
    int first = INT_MAX, second= INT_MAX;
    void preorder(TreeNode* root){
        
        if(!root) return ;
        if(root->val < first){
            first = root->val;
            
        }
        else if(root->val < second && first != root->val){
            second = root->val;
        }
        preorder(root->left);
        
        preorder(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        preorder(root);
        return second != INT_MAX? second:-1;
    }
};
__________________________________________________________________________________________________
