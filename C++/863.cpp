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
vector<TreeNode*> path;
TreeNode* target;
vector<int> ans;
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
  this->target = target;
  getPath(root);
  // printf("path: ");
  // for (auto it : path) printf("%d ", it->val); puts("");
  for (int i = path.size()-1; i >= 0; --i) {
    if (i == path.size()-1) go(path[i], k);
    else {
      if (k == 0) ans.push_back(path[i]->val);
      if (path[i]->left == path[i+1]) {
        go(path[i]->right, k-1);
      } else {
        go(path[i]->left, k-1);
      }
    }
    k--;
  }
  return ans;
}
void go(TreeNode* root, int dep) {
  if (dep < 0) return;
  if (!root) return;
  if (dep == 0) {
    ans.push_back(root->val);
    return;
  }
  go(root->left, dep-1);
  go(root->right, dep-1);
}
bool getPath(TreeNode* root) {
  if (!root) return false;
  if (root->val == target->val) {
    path.push_back(root);
    return true;
  }
  path.push_back(root);
  if (getPath(root->left)) return true;
  if (getPath(root->right)) return true;
  path.pop_back();
  return false;
}

};
__________________________________________________________________________________________________
sample 11984 kb submission
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
    vector<int> ret;
    stack<TreeNode*> s;
    
    void down(TreeNode* root,int k) {
        if(!root) return;
        if(!k) {
            ret.push_back(root->val);
            return;
        }
        down(root->left,k-1);
        down(root->right,k-1);
    }
    
    void find(TreeNode* root,TreeNode* t) {
        TreeNode* p = root;
        TreeNode* k = NULL;

        while(!s.empty()||p!=NULL) {
          if(p) {
              if(p==t) return;
              s.push(p);
              p = p->left;
          }
          else {
              p = s.top();
              if(p->right != NULL && k != p->right)
                  p = p->right;
              else{
                  s.pop();
                  k = p; 
                  p = NULL;
              }
          }
        }
    }

    void deal(TreeNode* root,TreeNode* t) {
        TreeNode* pre=NULL,*cur=t,*next=NULL;
        TreeNode* tmp=NULL;
        while(!s.empty()) {
            next=s.top(); s.pop();
            if(next==root) tmp=cur;
            
            if(cur->left==pre) cur->left=next;
            else cur->right=next;
            
            pre=cur;
            cur=next;
        }
        
        if(root->left==tmp) root->left=NULL;
        else root->right=NULL;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        if(!root) return {};
        if(!k) return {t->val};
        down(t,k);
        t->left=NULL;
        t->right=NULL;
        
        find(root,t);
        
        deal(root,t);
        down(t,k);
        return ret;
    }
};
__________________________________________________________________________________________________
