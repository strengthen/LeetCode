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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true; 
        return isSymmetricHelper(root->left,root->right);
    }
   bool isSymmetricHelper(TreeNode* root1, TreeNode* root2)
    {
       queue<TreeNode*> myqueue ; 
       
       myqueue.push(root1);
       myqueue.push(root2);
       TreeNode* temp1;
       TreeNode* temp2;
       while(!myqueue.empty())
       {
           root1 = myqueue.front();
           myqueue.pop();
           root2 = myqueue.front();
           myqueue.pop();
           
           if(root1 == NULL && root2 == NULL)
               continue;
           if(root1 == NULL || root2 == NULL)
               return false;
           
           if(root1->val != root2->val)
               return false;
           
           myqueue.push(root1->left);
           myqueue.push(root2->right);
           myqueue.push(root1->right);
           myqueue.push(root2->left);

       }
       return true;
       
    }
};
__________________________________________________________________________________________________
14684 kb
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto _______ = [](){
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	std::cin.tie(nullptr);
	return 0;
}();
#include <stack>
#include <algorithm>
class Solution {
public:
    bool isMirror(struct TreeNode *root1, struct TreeNode *root2) 
    { 
        // If both trees are emptu, then they are mirror images 
        if (root1 == NULL && root2 == NULL) 
            return true; 

        // For two trees to be mirror images, the following three 
        // conditions must be true 
        // 1 - Their root node's key must be same 
        // 2 - left subtree of left tree and right subtree 
        //      of right tree have to be mirror images 
        // 3 - right subtree of left tree and left subtree 
        //      of right tree have to be mirror images 
        if (root1 && root2 && root1->val == root2->val) 
            return isMirror(root1->left, root2->right) && 
                   isMirror(root1->right, root2->left); 

        // if neither of above conditions is true then root1 
        // and root2 are not mirror images 
        return false; 
    } 
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root); 
    }
};
__________________________________________________________________________________________________
