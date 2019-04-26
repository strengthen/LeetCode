__________________________________________________________________________________________________
sample 24 ms submission
#pragma GCC optimize("O3")
static const auto __ = [] {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

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
    bool isSubtreeHelper(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        
        if (s->val == t->val && isSubtreeHelper(s->left, t->left) && isSubtreeHelper(s->right, t->right)) {
            return true;
        }
        
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        
        if (isSubtreeHelper(s, t)) {
            return true;
        }

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
__________________________________________________________________________________________________
sample 20924 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
class Solution {
public:
    
    bool isSubtreeUtil(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        
        if (   !s
            || !t
            || (s->val != t->val))
            return false;
                
        return (   isSubtreeUtil(s->left,t->left) 
                && isSubtreeUtil(s->right, t->right)
               );
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
         if (!s && !t)
            return true;
        
        if (!s || !t)
            return false;
        
        return (   isSubtreeUtil(s,t) 
                || isSubtree(s->left, t) 
                || isSubtree(s->right, t)
               );
    }
};
__________________________________________________________________________________________________
