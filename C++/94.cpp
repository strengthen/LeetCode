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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ret{};
        inorderTraversal(root, ret);
        return ret;

    }
    void inorderTraversal(TreeNode *root, std::vector<int> &t){
        if(root == NULL){
            return ;
        } else {
            inorderTraversal(root->left, t);
            t.push_back(root->val);
            inorderTraversal(root->right, t);
            return;
        }
    }
    
};
__________________________________________________________________________________________________
8456 kb
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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        TreeNode* curr=root;
        TreeNode *pre,*temp;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                out.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                pre = curr->left;
                while(pre->right!=NULL)
                    pre = pre -> right;
                
                pre -> right = curr;
                temp = curr;
                curr = curr->left;
                temp->left=NULL;
            }
    
        }
        return out;
    } 
};
__________________________________________________________________________________________________
