__________________________________________________________________________________________________
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return NULL;
        Node *res = NULL;
        if (node->right) {
            res = node->right;
            while (res && res->left) res = res->left;
        } else {
            res = node->parent;
            while (res && res->val < node->val) res = res->parent;
        }
        return res;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
