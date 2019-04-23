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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {return 0;}
        const auto l = minDepth(root->left);
        const auto r = minDepth(root->right);
        if (l && r) {
            return std::min(l, r) + 1;
        } else if (l || r) {
            return std::max(l, r) + 1;
        } else {
            return 1;
        }
    }
};

static string s=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}();
__________________________________________________________________________________________________
19240 kb
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
    void call(TreeNode* root,int &max,int level)
    {
        if(!root)
        {
            return;
        }
        if(!root->left&&!root->right&&level<max)
        {
            max=level;
        }
        call(root->left,max,level+1);
        call(root->right,max,level+1);
    }
    int minDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int max=INT_MAX;
        call(root,max,1);
        return max;
    }
};
__________________________________________________________________________________________________
