__________________________________________________________________________________________________
sample 72 ms submission
class Solution {
 public:
  static inline TreeNode* insertIntoBST(TreeNode* root, const int val) {
    TreeNode* node = new TreeNode(val);
    if (root == nullptr) {
      return node;
    }
    for (auto crnt = root; crnt->val != val;) {
      if (val > crnt->val) {
        if (crnt->right == nullptr) {
          crnt->right = node;
        }
        crnt = crnt->right;
      } else {
        if (crnt->left == nullptr) {
          crnt->left = node;
        }
        crnt = crnt->left;
      }
    }
    return root;
  }
};


__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}
__________________________________________________________________________________________________
sample 32764 kb submission
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);
        TreeNode *temp = root;
        while(temp){
            if(temp->val > val){
                if(temp->left){
                    temp = temp->left;
                }else{
                    temp->left = node;
                    break;
                }
            }else if(temp->val <= val){
                if(temp->right){
                    temp = temp->right;
                }else{
                    temp->right = node;
                    break;
                }
            }
        }
        return root;
    }
};
__________________________________________________________________________________________________
