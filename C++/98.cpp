__________________________________________________________________________________________________
12ms
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
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    void inorderTraverse(TreeNode* root, long long& prev_val, bool& bad)
    {
        if (root == nullptr or bad)
        {
            return;
        }

        inorderTraverse(root->left, prev_val, bad);
        if (prev_val >= root->val)
        {
            bad = true;
            return;
        }
        prev_val = root->val;
        inorderTraverse(root->right, prev_val, bad);
    }

    bool isValidBST(TreeNode* root)
    {
        bool bad = false;
        long long prev_val = LLONG_MIN;
        inorderTraverse(root, prev_val, bad);
        return not bad;
    }
};
__________________________________________________________________________________________________
11320 kb 
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
    TreeNode * findRight(TreeNode* root){
      while(root->right!=NULL){root=root->right;}
      return root;
    }

    bool isValidBST(TreeNode* root) {
      // if(!root){return true;}
      // if(root->left==NULL && root->right==NULL){return true;}
      stack<int> s;
      while(root!=NULL){
        if(root->left==NULL){
          if(!s.empty() && s.top()>=root->val){return false;}
          if(!s.empty()){s.pop();}
          s.push(root->val);
          root=root->right;
        }else{
          TreeNode * t=root->left;
          TreeNode * temp=findRight(root->left);
          temp->right=root;
          temp->right->left=NULL;
          root=t;
        }
      }
      return true;
    }

};
__________________________________________________________________________________________________
