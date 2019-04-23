__________________________________________________________________________________________________
4ms
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
    bool pb;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL && q != NULL || p != NULL && q == NULL || p->val != q->val) return false;
        pb = isSameTree(p->left, q->left);
        if (pb == false) return false;
        pb = isSameTree(p->right, q->right);
        if (pb == false) return false;
        return true;
    }
};
__________________________________________________________________________________________________
9708 kb
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) return p == q;
		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
__________________________________________________________________________________________________
