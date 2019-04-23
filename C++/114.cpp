__________________________________________________________________________________________________
8ms
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
    void helper (TreeNode * root, TreeNode ** toUpdate)
    {
        if (root == nullptr)
        {
            return;
        }
        
        if (*toUpdate !=  nullptr)
        {
            (*toUpdate)->left = root;
        }
        
        if (root->left == nullptr)
        {
            *toUpdate = root;
        }
        else
        {
            *toUpdate = nullptr;
        }
        helper (root->left, toUpdate);
        helper (root->right, toUpdate);
        
        root->right = nullptr;
    }
    
    void swap (TreeNode * root)
    {
        if (root == nullptr) 
        {
            return;
        }
        root->right = root->left;
        root->left = nullptr;
        swap (root->right);
    }
    void flatten(TreeNode* root) {
        TreeNode * helperNode = nullptr;
        helper (root, &helperNode);
        swap(root);
    }
};
__________________________________________________________________________________________________
9900 kb
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
    
    void attachToEnd(TreeNode *node, TreeNode *attach) {
        assert(!node->left);
        while (node->right) {
            node = node->right;
        }
        node->right = attach;
    }
    
    
    void flatten(TreeNode* root) {
        if (!root)
            return;
        if (!(root->left || root->right))       
            return;
        if (root->left)
            flatten(root->left);
        if (root->right)
            flatten(root->right);
        
        if (root->left && root->right) {
            attachToEnd(root->left, root->right);
        } 
        if (root->left) {
            root->right = root->left;
            root->left = NULL;
        }               
    }
};

static const auto _____ = []()
{
    // fast IO code : this I understand
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
