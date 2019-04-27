__________________________________________________________________________________________________
sample 4 ms submission
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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> ret;
        if (!root) return ret;
        int levels = depth(root);
        int column = pow(2, levels) -1;
        vector<string> tmp(column, "");
        vector<vector<string>> result(levels, tmp);
        helper(root, result, 0, column/2, 
              pow(2, levels-2));
        return result;
    }
    int depth(TreeNode* root) {
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        return max(left, right) + 1;
    }
    void helper(TreeNode* root, vector<vector<string>>& result,
               int level, int column, int offset) {
        if (!root) return;
        result[level][column] = to_string(root->val);
        helper(root->left, result, level+1, column - offset, offset/2);
        helper(root->right, result, level+1, column + offset, offset/2);
    }
};
__________________________________________________________________________________________________
sample 9548 kb submission
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
    void printTreeHelper(TreeNode* node, vector<vector<string>>& data, int l, int r, int h) {
        if (node == nullptr) { return; }
        
        stringstream str;
        str << node->val;
        data[h][(l + r) / 2] = str.str();
        
        printTreeHelper(node->left, data, l, (l + r) / 2, h + 1);
        printTreeHelper(node->right, data, (l + r + 1) / 2, r, h + 1);
    }
    
    int getHeight(TreeNode* root) {
        if (root == nullptr) { return 0; }
        return 1 + max<int>(getHeight(root->left), getHeight(root->right));
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        vector<vector<string>> output(height, vector<string>((1 << height) - 1));
        
        printTreeHelper(root, output, 0, output[0].size(), 0);
        
        return output;
    }
};
__________________________________________________________________________________________________
