__________________________________________________________________________________________________
sample 44 ms submission
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
  bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    E.clear();
    this->T = target;
    dfsA(root1);
    return dfsB(root2);
  }
private:
  unordered_set<int> E;
  int T;
  void dfsA(TreeNode* x) {
    if (!x) return;
    E.insert(x->val);
    dfsA(x->left);
    dfsA(x->right);
  }
  bool dfsB(TreeNode* x) {
    if (!x) return false;
    if (E.find(T - x->val) != E.end()) return true;
    if (dfsB(x->left)) return true;
    return dfsB(x->right);
  }
};
__________________________________________________________________________________________________
sample 56 ms submission
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
    int t;
    bool ok = false;
    set < int > S;
    void dfs(TreeNode *node) {
        S.insert(node -> val);
        if((node -> left) != NULL) {
            dfs(node -> left);
        }
        if((node -> right) != NULL) {
            dfs(node -> right);
        }
    }
    
    void dfs2(TreeNode *node) {
        if(S.find(t - node -> val) != S.end()) {
            ok = true;
        }
        if((node -> left) != NULL) {
            dfs2(node -> left);
        }
        if((node -> right) != NULL) {
            dfs2(node -> right);
        }
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        t = target;
        dfs(root1);
        dfs2(root2);
        return ok;
    }
};
__________________________________________________________________________________________________
sample 60 ms submission
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
    void get(unordered_set<int>& s, TreeNode* root) {
        if (root) {
            s.insert(root->val);
            get(s, root->left);
            get(s, root->right);
        }
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> s1, s2;
        get(s1, root1);
        get(s2, root2);
        for (int i : s1) {
            if (s2.count(target-i)) return true;
        }
        return false;
    }
};