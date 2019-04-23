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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return NULL;
         stack<int> s;
         stack<TreeNode *> st;
         TreeNode *t,*r,*root;
         int i,j,f;

         f=i=j=0;
         s.push(preorder[i]);

         root = new TreeNode(preorder[i]);
         st.push(root);
         t = root;
         i++;

         while(i<preorder.size())
         {
             if(!st.empty() && st.top()->val==inorder[j])
             {
                 t = st.top();
                 st.pop();
                 s.pop();
                 f = 1;
                 j++;
             }
             else
             {
                 if(f==0)
                 {
                     s.push(preorder[i]);
                     t -> left = new TreeNode(preorder[i]);
                     t = t -> left;
                     st.push(t);
                     i++;
                 }
                 else 
                 {
                     f = 0;
                     s.push(preorder[i]);
                     t -> right = new TreeNode(preorder[i]);
                     t = t -> right;
                     st.push(t);
                     i++;
                 }
             }
         }

         return root;
     } 
};
__________________________________________________________________________________________________
14164 kb
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return nullptr;
        }
        
        stack<TreeNode*> s;
        TreeNode* p;
        TreeNode* root = new TreeNode(preorder[0]);
        int j=0;
        s.push(root);
        
        for(int i=1;i<preorder.size();i++){
            if(s.top()->val!=inorder[j] && s.top()->left==nullptr){
                TreeNode* node = new TreeNode(preorder[i]);
                s.top()->left=node;
                s.push(node);
            }else{
                while(s.empty()==false && s.top()->val == inorder[j]){
                    p=s.top();
                    s.pop();
                    j++;
                }
                p->right=new TreeNode(preorder[i]);
                s.push(p->right);
            }
        }
        return root;
    }
};
__________________________________________________________________________________________________
