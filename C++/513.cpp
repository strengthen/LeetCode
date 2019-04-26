__________________________________________________________________________________________________
sample 16 ms submission
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
    TreeNode* res = NULL;
    int max_level = INT_MIN;
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) return 0;
        
        static int level = 0;
        
        if(level > max_level) {
            max_level = level;
            res = root;
        }
        
        ++level;
        findBottomLeftValue(root->left);
        findBottomLeftValue(root->right);
        --level;
        
        if(res)
            return res->val;
        
        return 0;
    }
};

static auto s = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;   
}();
__________________________________________________________________________________________________
sample 20944 kb submission
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
    int findBottomLeftValue(TreeNode* root) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        TreeNode* tn=root;
        TreeNode** bottomleft=&tn;
        findBottomLeft(bottomleft, tn, 0);
        return (*bottomleft)->val;
    }
    int findBottomLeft(TreeNode** bottomleft, TreeNode* tn, int depth) {
        depth++;
        if(tn->left && tn->right) {
            int l=findBottomLeft(bottomleft, tn->left, depth);
            TreeNode* tmp=*bottomleft;
            int r=findBottomLeft(bottomleft, tn->right, depth);
            if(l>=r) {*bottomleft=tmp; return l;}
            else return r;
        }
        else if(!tn->left && tn->right) return findBottomLeft(bottomleft, tn->right,depth);
        else if(tn->left && !tn->right) return findBottomLeft(bottomleft, tn->left,depth);
        else {*bottomleft=tn; return --depth;}
    }
};
__________________________________________________________________________________________________
