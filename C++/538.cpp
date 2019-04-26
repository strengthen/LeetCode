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
    
    TreeNode* convertBST(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        TreeNode* initialRoot{root};
        std::stack<TreeNode*> st;
        int sum = 0;
        while (!st.empty() || root != nullptr) {
            if (root != nullptr) {
                st.push(root);
                root = root->right;
            } else {
                root = st.top();
                st.pop();
                root->val = (sum += root->val);
                root = root->left;
            }
        }
        return initialRoot;

    }
};
__________________________________________________________________________________________________
sample 23656 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();



class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        addlarger(root,sum);
        return root;
    }
    
    void addlarger(TreeNode* root, int& sum){
        if(!root) return;
        addlarger(root->right,sum);
        root->val+=sum;
        sum=root->val;
        addlarger(root->left,sum);
    }
};
__________________________________________________________________________________________________
