__________________________________________________________________________________________________
sample 184 ms submission
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> v1, v2, res;
        helper(root1, v1);
        helper(root2, v2);
        
        int s1 = v1.size(), s2 = v2.size();
        auto it1 = v1.cbegin(), it2 = v2.cbegin();
        
        while(it1 != v1.cend() && it2 != v2.cend()) {
            if(*it1 < *it2) {
                res.push_back(*it1);
                ++it1;
            }
            else {
                res.push_back(*it2);
                ++it2;
            }
        }
        
        while(it1 != v1.cend()) {
            res.push_back(*it1);
            ++it1;
        }
        
        while(it2 != v2.cend()) {
            res.push_back(*it2);
            ++it2;
        }
        
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& v) {
        if(!root) return;
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }
};
__________________________________________________________________________________________________
sample 192 ms submission
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
            ios_base::sync_with_stdio(false);
        cin.tie(NULL);
      stack<TreeNode*> s1, s2;
      vector<int> ret;
      pushLeft(root1, s1); pushLeft(root2, s2);
      
      while(s1.size() || s2.size()) {
        stack<TreeNode*>* m_stack;
        if (s1.size() && s2.size())
          m_stack = s1.top()->val < s2.top()->val ? &s1 : &s2;
        else if (s1.size())
          m_stack = &s1;
        else 
          m_stack = &s2;
      
        auto n = m_stack->top(); m_stack->pop();
        ret.push_back(n->val);
        pushLeft(n->right, *m_stack);
      }
      return ret;
    }
  
    void pushLeft(TreeNode* node, stack<TreeNode*>& s) {
      while (node) {
        s.push(node);
        node = node->left;
      }
    }
};
__________________________________________________________________________________________________
