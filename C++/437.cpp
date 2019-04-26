__________________________________________________________________________________________________
sample 16 ms submission
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
    
    std::vector<int> sumTotal;
    int count {0};
    void calculatepath(TreeNode *r , int t)
    {
        if(r == NULL)
            return ;
        sumTotal.push_back(r->val);
        calculatepath(r->left,t);
        calculatepath(r->right,t);
        int temp {0};
        
        for(int i = sumTotal.size() - 1 ; i >= 0; i--)
        {
            temp = temp + sumTotal[i];
            if(temp == t)
                count++;
        }
        
        sumTotal.pop_back();
        
    }
    int pathSum(TreeNode* root, int sum) 
    {
        if(!root)
            return 0;
        calculatepath(root,sum);
        return count;
        
    }
};
__________________________________________________________________________________________________
sample 14992 kb submission
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
    void traverse(TreeNode* subtree, int& sum, int& sol) {
        traversesubtree(subtree, 0, sum, sol);
        if(subtree->left != NULL) traverse(subtree->left, sum, sol);
        if(subtree->right != NULL) traverse(subtree->right, sum, sol);
    }
    void traversesubtree(TreeNode* subtree, int curr_sum, int& sum, int& sol) {
        curr_sum += subtree->val;
        if(curr_sum == sum) sol++;
        if(subtree->left != NULL) traversesubtree(subtree->left, curr_sum, sum, sol);
        if(subtree->right != NULL) traversesubtree(subtree->right, curr_sum, sum, sol);
    }
    int pathSum(TreeNode* root, int sum) {
        int sol = 0;
        if(root != NULL) traverse(root, sum, sol);
        return sol;
    }
};
__________________________________________________________________________________________________
