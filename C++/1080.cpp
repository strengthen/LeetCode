__________________________________________________________________________________________________
sample 28 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static int my_speed_up = []()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (root == NULL) {
            return NULL;
        }

        return sufficient(root, limit, 0);
    }

private:
    TreeNode* sufficient(TreeNode* root, int limit, int cur) {
        cur += root->val;

        if (root->left == NULL && root->right == NULL) {
            return cur >= limit? root : NULL;
        }

        if (root->left != NULL) {
            root->left = sufficient(root->left, limit, cur);
        }
        
        if (root->right != NULL) {
            root->right = sufficient(root->right, limit, cur);
        }
        
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }
        
        return root;
    }
};
__________________________________________________________________________________________________
sample 32 ms submission
// Time:  O(n)
// Space: O(h)

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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) {
            return nullptr;
        }
        if (!root->left && !root->right) {
            return root->val < limit ? nullptr : root;
        }
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);
        if (!root->left && !root->right) {
            return nullptr;
        }
        return root;
    }
};
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
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        m_limit = limit;
        dfs(root, 0);
        return root;
    }
    
    bool dfs(TreeNode*& n, int s)
    {
        if (!n) return false;
        
        int sum = s + n->val;
        bool suf = true;
        
        if (!n->left && !n->right)
            suf = sum >= m_limit;
        else{
            bool l_suf = dfs(n->left, sum);
            bool r_suf = dfs(n->right, sum);
            suf = l_suf || r_suf;
        }
        
        // printf("node %d sum %d, m_limit %d, suf %s\n", n->val, sum, m_limit, suf ? "yes" : "no");
        if (!suf)
            n = nullptr;
        
        return suf;
    }
    
    int m_limit;
};