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
class QNode
{
public:
    QNode(TreeNode *node, int parent, int level) : node(node), parent(parent), level(level) {};
    TreeNode *node;
    int parent;
    int level;
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) 
    {
        QNode xval(NULL, -1, -1), yval(NULL, -2, -2);
        deque<QNode> q;
        
        QNode r(root, -1, 0);
        
        q.push_back(r);
        
        while(!q.empty())
        {
            QNode curr = q.front();
            q.pop_front();
            
            if(curr.node)
            {
                if(curr.node->val == x)
                {
                    xval.parent = curr.parent;
                    xval.level = curr.level;
                }
                
                if(curr.node->val == y)
                {
                    yval.parent = curr.parent;
                    yval.level = curr.level;
                }
                
                if(curr.node->left)
                {
                    QNode left(curr.node->left, curr.node->val, curr.level+1);
                    q.push_back(left);
                }
                
                if(curr.node->right)
                {
                    QNode right(curr.node->right, curr.node->val, curr.level+1);
                    q.push_back(right);
                }
            }
        }
        
        if(xval.level == yval.level)
        {
            if(xval.parent != yval.parent)
                return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
sample 11056 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int level(TreeNode *root, int x,int l){
    if(!root)
        return 0;
    
    if(root->val == x)
        return l;
    
    int left = level(root->left,x,l+1);
    if(left)
        return left;
    
    return level(root->right,x,l+1);
}

bool isSibling(TreeNode *root, int x, int y)
{
    // TERMINATING CONDITION
    if (root==NULL)  
        return 0;
    bool a = false, b = false, c = false;
    
    if(root->left != NULL && root->right != NULL)
        a = ( (root->left->val == x && root->right->val == y) ||
              (root->left->val == y && root->right->val == x) );
    if(root->left != NULL) 
        b = isSibling(root->left, x, y);
    
    if(root->right != NULL) 
        c = isSibling(root->right, x, y);
    
    return (a || b || c);
}
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(!root || x == y){
            return false;
        }
        
        
        int level1 = level(root,x,0);
        int level2 = level(root,y,0);
        
        
        // cout<<level1<<" "<<level2<<endl;
        
        bool checkSibling = isSibling(root,x,y);
  
        // cout<<checkSibling<<endl;
        
        return (level1 == level2) && !checkSibling;
    }
};
__________________________________________________________________________________________________
