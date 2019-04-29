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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == NULL) {
            return new TreeNode(val);
        }
        
        if(root->val < val) {
            TreeNode* ret = new TreeNode(val);
            ret->left = root;
            return ret;
        }else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};
__________________________________________________________________________________________________
sample 12 ms submission
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if(root->val<val){
            TreeNode* newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        else
        {
            if(root->right==nullptr) //leaf
            {
                TreeNode* newnode=new TreeNode(val);
                root->right=newnode;
                return root;
            }
            else
                root->right=insertIntoMaxTree(root->right,val);
        }
        return root;
    
    }
};
__________________________________________________________________________________________________
