__________________________________________________________________________________________________
sample 20 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
  int kthSmallest(TreeNode* Root, int K) {
  
    int InorderVisitedCnt = 0;
    TreeNode *KthSmallestNode = nullptr;
    
    std::function<bool(TreeNode *)> FindKthSmallest;
    FindKthSmallest = [&](TreeNode *Curr) {
      if (!Curr)
        return false;
      
      if (FindKthSmallest(Curr->left))
        return true;
      
      InorderVisitedCnt++;
      if (InorderVisitedCnt == K) {
        KthSmallestNode = Curr;
        return true;
      }
      
      return FindKthSmallest(Curr->right);
    };
    
    FindKthSmallest(Root);
    assert(KthSmallestNode && "k is too large");
    
    return KthSmallestNode->val;
  }
};
__________________________________________________________________________________________________
sample 21296 kb submission
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
private: 
    int count;
    int answer;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) 
            return 0;
        count = k;
        helper(root);
        return answer;
    }
    void helper(TreeNode* root){
        if(!root)
            return;
       helper(root->left);
       if(--count == 0)
           answer = root->val;
       helper(root->right);
    }    
};
__________________________________________________________________________________________________
