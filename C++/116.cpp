__________________________________________________________________________________________________
28ms
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if (!root){
            return;
        }
        
        q.push(root);
        
        while (!q.empty()){
            int size = q.size();
            while (size--){
                TreeLinkNode* c = q.front();
                q.pop();
                
                if (size == 0){
                    c->next = NULL;
                }
                else{
                    c->next = q.front();
                }
                
                if (c->left){
                    q.push(c->left);
                }
                if (c->right){
                    q.push(c->right);
                }
            }
        }
        return;
    }
};
__________________________________________________________________________________________________
20556 kb
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode* pre = nullptr;
            TreeLinkNode* nextRoot = nullptr;
            for (TreeLinkNode* curr = root; curr; curr = curr->next) {
                if (curr->left) {
                    if (!nextRoot) {
                        nextRoot = curr->left;
                    }
                    if (pre) {
                        pre->next = curr->left;
                    }
                    pre = curr->left;
                }
                if (curr->right) {
                    if (!nextRoot) {
                        nextRoot = curr->right;
                    }
                    if (pre) {
                        pre->next = curr->right;
                    }
                    pre = curr->right;
                }
            }
            root = nextRoot;
        }
    }
};
__________________________________________________________________________________________________
