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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> myQueue;
        bool lastNodeReached = false;
        
        if (root == NULL)
            return true;
        
        myQueue.push(root);
        
        while(!myQueue.empty())
        {
            TreeNode *curr = myQueue.front();
            
            if (curr->left != NULL && lastNodeReached)
                return false;
            else if (curr->left == NULL && !lastNodeReached)
                lastNodeReached = true;
            
            if (curr->right != NULL && lastNodeReached)
                return false;
            else if (curr->right == NULL && !lastNodeReached)
                lastNodeReached = true;
            
            if (curr->left)
                myQueue.push(curr->left);
            if (curr->right)
                myQueue.push(curr->right);
            myQueue.pop();
        }
        
        return true;
    }
};
__________________________________________________________________________________________________
sample 10316 kb submission

static auto x = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        int level = 0;
        bool hasNull = false;
        while (!myqueue.empty()) {
            TreeNode* n = myqueue.front();
            myqueue.pop();

            if (n == nullptr) {
                hasNull = true;
            } else {
                if (hasNull) {
                    return false;
                }
                if (n->left) {
                    myqueue.push(n->left);
                } else {
                    myqueue.push(nullptr);
                }
                if (n->right) {
                    myqueue.push(n->right);
                } else {
                    myqueue.push(nullptr);
                }
            }
        }
        return true;
    }
};
__________________________________________________________________________________________________
