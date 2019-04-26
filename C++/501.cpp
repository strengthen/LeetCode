__________________________________________________________________________________________________
sample 16 ms submission
class Solution {
public:
  TreeNode* findright(TreeNode* root){
    while(root->right){root=root->right;}
    return root;
  }

    vector<int> findMode(TreeNode* root) {
      if(!root){ return {}; }

      vector<int> res;
      // int last=INT_MAX;
      int last=1000;
      int max_index=0;
      int index=0;

      while(root){
        if(!root->left){
          if(root->val==last){index++;}
          else{
            if(index==max_index){res.push_back(last);}
            else {if(index>max_index){max_index=index;res.clear();res.push_back(last);}}
            index=1;
            last=root->val;
          }
          root=root->right;
        }else{
          TreeNode * p=findright(root->left);
          p->right=root;
          root=root->left;
          p->right->left=NULL;
        }
      }

        if(index==max_index){res.push_back(last);}
        else {if(index>max_index){max_index=index;res.clear();res.push_back(last);}}

      return res;
    }
};
__________________________________________________________________________________________________
sample 23168 kb submission
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
    vector<int> findMode(TreeNode* root) {
        
        int cur = INT_MAX;
        int cur_max = 0;
        int prev_max = 1;
        TreeNode* node = root;
        stack<TreeNode*> s;
        vector<int> modes;
        
        while(node || !s.empty()){
            
            if(!node){
                node = s.top();
                s.pop();
                
                if(node->val != cur){
                    if(cur_max > prev_max){
                        prev_max = cur_max;
                        modes = {cur};
                    }else if(cur_max == prev_max)
                        modes.push_back(cur);
                    cur_max = 1;
                    cur = node->val;
                }else
                    cur_max++;
                node = node->right;
            }
            
            while(node){
                s.push(node);
                node = node->left;
            }
        }
        
        if(cur_max > prev_max)
            modes = {cur};
        else if(cur_max == prev_max)
            modes.push_back(cur);
        
        return modes;
    }    
};
__________________________________________________________________________________________________
