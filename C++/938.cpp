__________________________________________________________________________________________________
sample 96 ms submission
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
    int sum=0;
    void inorder(TreeNode* r, int L, int R){
        if(r == NULL)
            return;
        if(L <= r->val)
            inorder(r->left, L, R);
        if((L <= r->val)&&(R >= r->val))
            sum += r->val;
        if(R >= r->val)
            inorder(r->right, L, R);
            
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        inorder(root, L, R);
        return sum;
    }
};
__________________________________________________________________________________________________
sample 41008 kb submission
static const auto fastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
} ();

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        
        int left = rangeSumBST(root->left, L, R);
        int right = rangeSumBST(root->right, L, R);
        return left + right + ((root->val >= L && root->val <= R) ? root->val : 0);
    }
};
__________________________________________________________________________________________________
