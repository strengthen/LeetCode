__________________________________________________________________________________________________
sample 20 ms submission
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this -> root = root;
        next_parent.push(root);
        TreeNode *parent = next_parent.front();
        while(parent -> right != NULL)
        {
            next_parent.push(parent -> left);
            next_parent.push(parent -> right);
            next_parent.pop();
            parent = next_parent.front();
        }
        if(parent -> left != NULL)
            next_parent.push(parent -> left);
    }
    
    int insert(int v) {
        TreeNode *parent = next_parent.front(), *cur = new TreeNode(v);
        if(parent -> left == NULL)
            parent -> left = cur;
        else
        {
            parent -> right = cur;
            next_parent.pop();
        }
        next_parent.push(cur);
        return parent -> val;
    }
    
    TreeNode* get_root() {
        return root;
    }

private:
    TreeNode *root;
    queue <TreeNode *> next_parent;
};
__________________________________________________________________________________________________
sample 13540 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    TreeNode * r;
    queue<TreeNode*> q;
    CBTInserter(TreeNode* root) {
      r = root;
      q.push(r);
    }
    
    int insert(int v) {
        
      
      while(!q.empty()){
        int len = q.size();
        
        for (int i = 0; i < len; i++){
          auto t = q.front();
          if (!t->left) {
            t->left = new TreeNode(v);
            return t->val;
          }
          else if (!t->right){
            t->right = new TreeNode(v);
            q.push(t->left);
            q.push(t->right);
            q.pop();
            return t->val;
          }
          
          else {
            q.push(t->left);
            q.push(t->right);
            q.pop();
          }
        }
      }
      
      return -1;
    }
    
    TreeNode* get_root() {
        return r;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
__________________________________________________________________________________________________
