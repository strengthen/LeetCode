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
static int x=[](){
std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int n=0,c=0;
    int maxDepth(TreeNode* root) {
        n++;
        if(n>c)c=n;
        if(root==NULL)return 0;
        if(root->left!=NULL)
        {
            maxDepth(root->left);
            n--;
        }
        if(root->right!=NULL)
        {
            maxDepth(root->right);
            n--;
        }
        return c;
    }
};
__________________________________________________________________________________________________
18872 kb
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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right ? left : right) + 1;
    }
};
__________________________________________________________________________________________________
