__________________________________________________________________________________________________
class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) return NULL;
        TreeNode *res = new TreeNode(root->val);
        if (!root->children.empty()) {
            res->left = encode(root->children[0]);
        }
        TreeNode *cur = res->left;
        for (int i = 1; i < root->children.size(); ++i) {
            cur->right = encode(root->children[i]);
            cur = cur->right;
        }
        return res;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) return NULL;
        Node *res = new Node(root->val, {});
        TreeNode *cur = root->left;
        while (cur) {
            res->children.push_back(decode(cur));
            cur = cur->right;
        }
        return res;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
