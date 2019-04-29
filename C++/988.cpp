__________________________________________________________________________________________________
sample 8 ms submission
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
    TreeNode* minimumLeaf;
    
    void saveLeaf(TreeNode* leaf) {
        if (!leaf) {
            return;
        }
        
        if (!minimumLeaf) {
            minimumLeaf = leaf;
            return;
        }
        
        TreeNode* minimumLeafCopy = minimumLeaf;
        TreeNode* leafCopy = leaf;
        
        while (leafCopy && minimumLeafCopy) {
            if (leafCopy->val < minimumLeafCopy->val) {
                minimumLeaf = leaf;
                return;
            } else if (leafCopy->val > minimumLeafCopy->val) {
                return;
            } else {
                leafCopy = leafCopy->left;
                minimumLeafCopy = minimumLeafCopy->left;
            }
        }
        
        if (minimumLeafCopy) {
            minimumLeaf = leaf;
        }
    }
    
    void rec(TreeNode* node, TreeNode* parent = nullptr) {
        if (!node) { return; }
        
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        
        node->left = parent;
        node->right = parent;
        
        if (!left && !right) {
            saveLeaf(node);
        } else {
            rec(left, node);
            rec(right, node);
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        rec(root);
        
        stringstream result;
        
        while (minimumLeaf) {
            result << static_cast<char>(minimumLeaf->val + 'a');
            minimumLeaf = minimumLeaf->left;
        }
        
        return result.str();
    }
};
__________________________________________________________________________________________________
sample 14244 kb submission
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
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        
        string left = smallestFromLeaf(root->left);    
        string right = smallestFromLeaf(root->right);
        
        if (left=="" && right=="") {
            return string(1,'a'+ root->val);
        } else if (left=="") {
            return right + string(1, 'a'+ root->val);
        } else if (right =="") {
            return left + string(1, 'a'+root->val);
        }
        int i=0;
        while(left[i]==right[i] && i < left.size() && i < right.size()) {
            i++;
        }
        if(i == left.size()) {
            return left + string(1,'a'+ root->val);
        } else if (i==right.size()) {
            return right + string(1,'a'+ root->val);
        } else {
            return left[i] > right[i] ? right + string(1,'a'+ root->val) : left + string(1,'a'+ root->val);
        }
    }
};
__________________________________________________________________________________________________
