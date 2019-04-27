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
    void Inorder(TreeNode* root,vector<int> &numVec)
    {
        if(root)
        {
            Inorder(root->left,numVec);
            numVec.push_back(root->val);
            Inorder(root->right,numVec);            
        }
    }
    int minDiffInBST(TreeNode* root) 
    {
        if(root==nullptr)
            return -1;
        vector<int> numVec;
        Inorder(root, numVec);
        int minDis = INT_MAX;
        for(int i = 0; i<numVec.size()-1; ++i)
        {
            //cout<<numVec[i]<<endl;
            if(numVec[i+1]-numVec[i] < minDis)
            {
                minDis = numVec[i+1]-numVec[i];
            }
        }
        
        return minDis;
    }
};
__________________________________________________________________________________________________
sample 11040 kb submission
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
    int minDiffInBST(TreeNode* root) {
        int minval = INT_MAX;
        int pre = INT_MAX;
        inorder(root, minval, pre);
        return minval;
    }
    
    void inorder(TreeNode* node, int& minval, int& pre){
        if(!node) return;
        inorder(node->left, minval, pre);
        if(pre != INT_MAX) minval = min(minval, node->val-pre);
        pre = node->val;
        inorder(node->right, minval, pre);
    }
};
__________________________________________________________________________________________________
