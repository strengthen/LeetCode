__________________________________________________________________________________________________
sample 4 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> flips;
    
    bool traverse(TreeNode* root, vector<int>& voyage, int &pos) {
        if (!root) 
            return true;
    
        if (root->val != voyage[pos++]) 
            return false;
        
        auto l = root->left, r = root->right;
  
        if (l != nullptr && l->val != voyage[pos]) {
            flips.push_back(root->val);
            swap(l, r);
        }
  
        return traverse(l, voyage, pos) && traverse(r, voyage, pos);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage, int pos = 0) {
        return traverse(root, voyage, pos) ? flips : vector<int>() = { -1 };
    }
};
__________________________________________________________________________________________________
sample 11848 kb submission
    class Solution {
    public:
        vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
            if (root->val != voyage[0]) return { -1 };
            vector<int> res;
            stack<TreeNode*> s;
            s.push(root);
            int i = 0;
            while (!s.empty()) {
                TreeNode* p = s.top();
                s.pop();
                if (p->val != voyage[i++]) return { -1 };
                if (p->left && p->left->val != voyage[i]) {
                    res.push_back(p->val);
                    if (p->left) s.push(p->left);
                    if (p->right) s.push(p->right);
                } else {
                    if (p->right) s.push(p->right);
                    if (p->left) s.push(p->left);
                }
            }
            return res;
        }
    };
__________________________________________________________________________________________________
