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
static int speed = [](){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int tilt=0;
    int tiltTree(TreeNode *root) {
        if (!root) return 0;
        int left = tiltTree(root->left);
        int right = tiltTree(root->right);
        tilt+=abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        tiltTree(root);
        return tilt;
    }
};
__________________________________________________________________________________________________
sample 21904 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode* root,int &sum)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
    {
        return;
    }
    
    solve(root->left,sum);
    solve(root->right,sum);
    
    int s1 = 0;
    int s2 = 0;
    if(root->left != NULL)
        s1 = root->left->val;
    if(root->right != NULL)
        s2 = root->right->val;
    
    sum += abs(s1-s2);
    root->val += s1 + s2;
    
    return;
}

class Solution {
public:
    int findTilt(TreeNode* root) {
        
        if(root == NULL)
            return 0;
    
        int sum = 0;
        solve(root,sum);        
        
        return sum;
    }
};
__________________________________________________________________________________________________
