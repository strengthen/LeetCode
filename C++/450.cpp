__________________________________________________________________________________________________
sample 28 ms submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode * prev;
        TreeNode * cur = root;
        TreeNode * delNode;
        while(cur != NULL && cur -> val != key) {
            prev = cur;
            if(key < cur->val) cur = cur->left;
            else if(key > cur->val) cur = cur->right;
        }
        if(cur == NULL) return root; //Could not find key
        if(cur -> right == NULL) {
            //Relink
            if(cur == root) {
                cur = cur->left;
                delete root;
                return cur;
            } else {
                if(prev -> right == cur)
                    prev->right = cur->left;
                else
                    prev->left = cur->left;
                delete cur;
                return root;
            }
        } else {
            //Find next largest, assign val, delete that one
            delNode = cur;
            prev = cur;
            cur = cur -> right;
            while(cur->left != NULL) {
                prev = cur;
                cur = cur->left;
            }
            if(prev -> right == cur) {
                prev -> right = cur -> right;
            } else {
                prev -> left = cur -> right;
            }
            delNode -> val = cur -> val;
            delete cur;
        }
        return root;
    }
};
__________________________________________________________________________________________________
sample 12992 kb submission
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* superRoot = new TreeNode(0);
        superRoot->left = root;
        
        TreeNode* parent = superRoot;
        TreeNode* current = root;
        while (current != NULL && current->val != key){
            parent = current;
            if (key <= current->val){
                current = current->left;
            }else{
                current = current->right;
            }
        }
        // Not found
        if (current==NULL) return superRoot->left;
        
        while (current->left != NULL || current->right != NULL){
            TreeNode *origin = current;
            if (current->left != NULL){
                parent = current;
                current = current->left;
                while (current->right!=NULL){
                    parent = current;
                    current = current->right;
                }
            }else{
                parent = current;
                current = current->right;
                while (current->left!=NULL){
                    parent = current;
                    current = current->left;
                }
            }
            swap(origin->val, current->val);
        }
        
        if (parent->left == current) 
            parent->left = NULL; else
            parent->right = NULL;
        delete current;
        return superRoot->left;
    }
};
__________________________________________________________________________________________________
