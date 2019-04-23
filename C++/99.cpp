__________________________________________________________________________________________________
24ms
auto speed=[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
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
private:
    TreeNode* pre=NULL;
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    
    void  inOrder(TreeNode * root){
        if(!root) return;
        inOrder(root->left);
        if(pre!=NULL && first==NULL && pre->val>=root->val){
            first=pre;
        }
        
        if(first!=NULL && pre->val>=root->val){
            second=root;
            if(pre!=first){
                return;
            }
        }
        pre=root;
        inOrder(root->right);
    }
    
public:
    void recoverTree1(TreeNode* root) {
        stack<TreeNode*> helper;
        TreeNode* pre=NULL;
        bool first=false;
        TreeNode *second;
        int tag=INT_MAX;
        while(root!=NULL || !helper.empty()){
            while(root!=NULL){
                helper.push(root);
                root=root->left;
            }
            root=helper.top();
            helper.pop();
            if(pre!=NULL && !first && pre->val>=root->val){
                first=true;
                second=root;
                tag=root->val;
            }
            if(!first){
                pre=root;
            }else if(root->val<tag){
                tag=root->val;
                second=root;
            }
            
            root=root->right;
        }
        int tmp=pre->val;
        pre->val=second->val;
        second->val=tmp;
    }
    
    void recoverTree(TreeNode* root) {
        inOrder(root);
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
    }
};
__________________________________________________________________________________________________
17628 kb
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void visit(TreeNode *&prev, TreeNode *&cur, TreeNode *&a, TreeNode *&b) 
    {
        if(prev != NULL && prev -> val > cur -> val)
        {
            if(a == NULL)
            {
                a = prev;
                b = cur;
            }
            else
                b = cur;
        }
        prev = cur;
        cur = cur -> right;
        return;
    }
    void recoverTree(TreeNode* root) 
    {
        TreeNode *prev = NULL, *cur = root, *a = NULL, *b = NULL;
        while(cur != NULL)
        {
            if(cur -> left == NULL)
                visit(prev, cur, a, b);
            else
            {
                TreeNode *temp = cur -> left;
                while(temp -> right != NULL && temp -> right != cur)
                    temp = temp -> right;
                if(temp -> right == NULL)
                {
                    temp -> right = cur;
                    cur = cur -> left;
                }
                else 
                {
                    temp -> right = NULL;
                    visit(prev, cur, a, b);
                }
            }
        }
        int temp = a -> val;
        a -> val = b -> val;
        b -> val = temp;
        return;
    }
};
__________________________________________________________________________________________________
