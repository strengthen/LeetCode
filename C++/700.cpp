__________________________________________________________________________________________________
sample 36 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val==val){
                return root;
            }else if(root->val>val){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return nullptr;
    }
};
__________________________________________________________________________________________________
sample 24556 kb submission
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val){
            return root;
        }
        else if(root->val > val){
            return root->left = searchBST(root->left, val);
        }
        else{
            return root->right = searchBST(root->right, val);
        }
    }
};
__________________________________________________________________________________________________
